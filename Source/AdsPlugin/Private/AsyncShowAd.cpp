// Copyright Nirilon Studio © 2022. All Rights Reserved.


#include "AsyncShowAd.h"
#include "Async/Async.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif

UAsyncShowAd* ShowProxy;

UAsyncShowAd * UAsyncShowAd::ShowAd(EAdType AdType)
{
	UAsyncShowAd* Instance = NewObject<UAsyncShowAd>();
	return Instance;
}

void UAsyncShowAd::Activate()
{
	ShowProxy = this;

#if PLATFORM_ANDROID && USE_ANDROID_JNI
if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
{
	const jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "javaShowAd", "()V", false);

	if (Method != nullptr)
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
}
#endif
}

#if PLATFORM_ANDROID && USE_ANDROID_JNI
JNI_METHOD void Java_com_epicgames_ue4_GameActivity_OnShowSuccess(JNIEnv* jenv, jclass clazz)
{
	if (ShowProxy != nullptr)
	{
		AsyncTask(ENamedThreads::GameThread, [=]() { ShowProxy->OnSuccess.Broadcast(); });
	}
}
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI
JNI_METHOD void Java_com_epicgames_ue4_GameActivity_OnShowFailed(JNIEnv* jenv, jclass clazz)
{
	if (ShowProxy != nullptr)
	{
		AsyncTask(ENamedThreads::GameThread, [=]() { ShowProxy->OnFailed.Broadcast(); });
	}
}
#endif
