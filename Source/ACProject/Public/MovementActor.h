// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ACProjectGameMode.h"
#include "ATrackLine.h"
#include "GameFramework/Actor.h"
#include "MovementActor.generated.h"

UCLASS()
class ACPROJECT_API AMovementActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovementActor();

	UPROPERTY(VisibleAnywhere)
	bool flag;

	UPROPERTY(VisibleAnywhere)
	int frame;

	UPROPERTY(VisibleAnywhere)
	int frame_count;

	UPROPERTY(VisibleAnywhere)
	FString Directory;

	UPROPERTY(VisibleAnywhere)
	FString FileDirectory;

	UPROPERTY(VisibleAnywhere)
	AACProjectGameMode* gm;

	UPROPERTY(VisibleAnywhere)
	FTimerHandle TimerHandle;
	
	UPROPERTY(VisibleAnywhere)
	ULineBatchComponent* LineBatch;

	UPROPERTY(EditAnywhere)
	float LineLifeTime;

	//UPROPERTY(EditAnywhere)
	//TSubclassOf<AATrackLine> TrackLineType;

	UFUNCTION()
	void Delay();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
