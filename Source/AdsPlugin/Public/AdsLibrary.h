// Copyright Nirilon Studio © 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "AdsLibrary.generated.h"

//enam ads type
UENUM(BlueprintType)
enum class EAdsType : uint8
{
	Banner,
	Interstitial,
	RewardedVideo,
	NativeAds
};

UCLASS()
class ADSPLUGIN_API UAdsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Ads|AdMob")
	static void LoadAd(EAdsType Type);
	
	UFUNCTION(BlueprintCallable, Category = "Ads|AdMob")
	static void IsAdLoaded(EAdsType Type, bool& isLoaded);
	
	static void CallJavaMethod(const ANSICHAR* MethodName);
	
};
