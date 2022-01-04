// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AObj.h"
#include "APlane.h"
#include "GameFramework/Actor.h"
#include "AGeneratorPlaneAndObject.generated.h"

UCLASS()
class ACPROJECT_API AAGeneratorPlaneAndObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGeneratorPlaneAndObject();

	// 用来指定生成的是哪个类
	UPROPERTY(EditAnywhere)
	TSubclassOf<AAPlane> PlaneType;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AAObj> CarType;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	bool Generator(int id, FVector location, FRotator rotator, bool isPlane);


};
