// Copyright Nirilon Studio © 2022. All Rights Reserved.

#include "AdsLibrary.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif

bool UAdsLibrary::IsAdLoaded(EAdType Type)
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "IsAdLoaded", "()Z", false);

		if (Method != nullptr)
		{
			return FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method);
		}
	}
#endif
	return false;
}

void UAdsLibrary::CallJavaMethod(const ANSICHAR* MethodName)
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, MethodName, "()V", false);

		if (Method != nullptr)
		{
			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
		}
	}
#endif
}
