// Copyright Nirilon Studio © 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncLoadAd.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLoadAdDelegate);

UCLASS()
class ADSPLUGIN_API UAsyncLoadAd : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FLoadAdDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FLoadAdDelegate OnFailed;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAsyncLoadAd* LoadAd(EAdType AdType);

	virtual void Activate() override;
};
