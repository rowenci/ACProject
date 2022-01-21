// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ACProjectGameState.h"
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

	UPROPERTY(EditAnywhere)
	FString PlaneFileName;
	
	UPROPERTY(EditAnywhere)
	FString ObjectFileName;

	UPROPERTY(EditAnywhere)
	FString Directory;

	UPROPERTY(EditAnywhere)
	int frame;

	UPROPERTY(EditAnywhere)
	int frame_count;

	UPROPERTY(VisibleAnywhere)
	bool GameControlBegin = false;

	UPROPERTY(VisibleAnywhere)
	bool GameControlReset = false;

};
