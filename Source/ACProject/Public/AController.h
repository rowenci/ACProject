// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ACProjectGameMode.h"
#include "AGeneratorPlaneAndObject.h"
#include "GameFramework/Actor.h"
#include "AController.generated.h"

UCLASS()
class ACPROJECT_API AAController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void BeginSimulate();

	UFUNCTION(BlueprintCallable)
	void ResetSimulate();
};
