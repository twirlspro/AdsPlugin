// Copyright Nirilon Studio © 2022. All Rights Reserved.

#include "AdsLibrary.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif

void UAdsLibrary::LoadAd(EAdsType Type)
{
	CallJavaMethod("JavaLoadAd");
}

void UAdsLibrary::IsAdLoaded(EAdsType Type, bool& isLoaded)
{
	CallJavaMethod("JavaIsAdLoaded");
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
