// Copyright Nirilon Studio © 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ShowInterstitialAd.generated.h"

//delegate one parameters bool isSuccess
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInterstitialDelegate, bool, isSuccess);

UCLASS()
class ADSPLUGIN_API UShowInterstitialAd : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FInterstitialDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FInterstitialDelegate OnFailed;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UShowInterstitialAd* ShowTest();

	virtual void Activate() override;
};
