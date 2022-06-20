// Copyright Nirilon Studio © 2022. All Rights Reserved.

#include "AsyncLoadAd.h"
#include "Async/Async.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif

UAsyncLoadAd* LoadProxy;

UAsyncLoadAd* UAsyncLoadAd::LoadAd(EAdType AdType)
{
	UAsyncLoadAd* Instance = NewObject<UAsyncLoadAd>();
	return Instance;
}

void UAsyncLoadAd::Activate()
{
	LoadProxy = this;
}

#if PLATFORM_ANDROID && USE_ANDROID_JNI
if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
{
	const jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "javaLoadAd", "()V", false);

	if (Method != nullptr)
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
}
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI
JNI_METHOD void Java_com_epicgames_ue4_GameActivity_OnLoadSuccess(JNIEnv* jenv, jclass clazz)
{
	if (Proxy != nullptr)
	{
		AsyncTask(ENamedThreads::GameThread, [=]() { LoadProxy->OnSuccess.Broadcast(); });
	}
}
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI
JNI_METHOD void Java_com_epicgames_ue4_GameActivity_OnLoadFailed(JNIEnv* jenv, jclass clazz)
{
	if (Proxy != nullptr)
	{
		AsyncTask(ENamedThreads::GameThread, [=]() { LoadProxy->OnFailed.Broadcast(); });
	}
}
#endif