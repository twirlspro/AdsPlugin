// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

UENUM(BlueprintType)
enum class EAdType : uint8
{
	Banner,
	Interstitial,
	RewardedVideo,
};

class FAdsPluginModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
