// Copyright Nirilon Studio © 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "AdsLibrary.generated.h"

UCLASS()
class ADSPLUGIN_API UAdsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Ads|AdMob")
	static void ShowAdBanner();
	UFUNCTION(BlueprintCallable, Category = "Ads|AdMob")
	static void ShowInterstitialAd();
	UFUNCTION(BlueprintCallable, Category = "Ads|AdMob")
	static void ShowRewardedAd();
	
private:
	static void CallJavaMethod(const ANSICHAR* MethodName);
	
};
