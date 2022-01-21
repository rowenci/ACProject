// Fill out your copyright notice in the Description page of Project Settings.


#include "AController.h"
#include "MovementActor.h"

// Sets default values
AAController::AAController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAController::BeginSimulate()
{
	AACProjectGameMode* gm = Cast<AACProjectGameMode>(GetWorld()->GetAuthGameMode());
	if (gm != nullptr)
	{
		gm->GameControlBegin = true;
	}
}

void AAController::ResetSimulate()
{
	AACProjectGameMode* gm = Cast<AACProjectGameMode>(GetWorld()->GetAuthGameMode());
	if (gm != nullptr)
	{
		gm->GameControlReset = true;
	}
}

