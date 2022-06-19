// Copyright Nirilon Studio © 2022. All Rights Reserved.


#include "ShowInterstitialAd.h"
#include "Async/Async.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif

UShowInterstitialAd* Proxy;

UShowInterstitialAd* UShowInterstitialAd::ShowTest()
{
	UShowInterstitialAd* Instance = NewObject<UShowInterstitialAd>();
	UE_LOG(LogTemp, Warning, TEXT("Init ShowTest"));
	return Instance;
}

// acivate
void UShowInterstitialAd::Activate()
{
	UE_LOG(LogTemp, Warning, TEXT("Activate ShowTest"));
	Proxy = this;

#if PLATFORM_ANDROID && USE_ANDROID_JNI
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "showInterstitialAd", "()V", false);

		if (Method != nullptr)
		{
			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
		}
	}
#endif
}

#if PLATFORM_ANDROID && USE_ANDROID_JNI
JNI_METHOD void Java_com_epicgames_ue4_GameActivity_OnSuccessAd(JNIEnv* jenv, jclass clazz, jboolean bIsSuccess)
{
	//print proxy address
	UE_LOG(LogTemp, Warning, TEXT("Proxy address: %s"), *FString::FromInt((int64)Proxy));
	if(Proxy != nullptr)
	{
		AsyncTask(ENamedThreads::GameThread, [=]() {
		if (bIsSuccess)
		{
			Proxy->OnSuccess.Broadcast(true);
		}
		else
		{
			Proxy->OnFailed.Broadcast(false);
		}
		});
	}
}
#endif
