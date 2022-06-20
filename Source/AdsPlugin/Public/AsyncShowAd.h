// Copyright Nirilon Studio © 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncShowAd.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FShowAdDelegate);

UCLASS()
class ADSPLUGIN_API UAsyncShowAd : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FShowAdDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FShowAdDelegate OnFailed;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAsyncShowAd* ShowAd(EAdType AdType);

	virtual void Activate() override;
	
};
