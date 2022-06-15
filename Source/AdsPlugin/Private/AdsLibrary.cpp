// Copyright Nirilon Studio © 2022. All Rights Reserved.

#include "AdsLibrary.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif

bool UAdsLibrary::CallJavaGameActivity(FString MethodName, bool bIsOptional)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bIsOptional;
		const jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, TCHAR_TO_ANSI(*MethodName), "()V", bIsOptional);

		if (Method != nullptr)
		{
			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethod);
			return true;
		}
	}
#endif
	return false;
}
