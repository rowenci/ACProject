// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ACProjectGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ACPROJECT_API AACProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AACProjectGameMode();

	UPROPERTY(VisibleAnywhere)
	TArray<FString> PlaneIdArray;
	
	UPROPERTY(VisibleAnywhere)
	TArray<FString> ObjectIdArray;

	UPROPERTY(VisibleAnywhere)
	bool ActorGenerated;

	UPROPERTY(VisibleAnywhere)
	TMap<int, FVector> LastPlaneLocationMap;
};
