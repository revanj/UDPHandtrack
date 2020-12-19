// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HandTrackTestUnrealGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class HANDTRACKTESTUNREAL_API AHandTrackTestUnrealGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	virtual void StartPlay() override;
};

