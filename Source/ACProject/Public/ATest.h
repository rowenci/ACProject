// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATest.generated.h"

UCLASS()
class ACPROJECT_API AATest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AATest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	void TestFunc();

	UPROPERTY(VisibleAnywhere)
	ULineBatchComponent* LineBatcher;

};
