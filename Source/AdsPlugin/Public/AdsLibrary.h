// Copyright Nirilon Studio © 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AdsPlugin.h"
#include "AdsLibrary.generated.h"

UCLASS()
class ADSPLUGIN_API UAdsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintPure, Category = "Ads|AdMob")
	static bool IsAdLoaded(EAdType Type);
	
	static void CallJavaMethod(const ANSICHAR* MethodName);
	
};
