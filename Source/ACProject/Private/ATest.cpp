// Fill out your copyright notice in the Description page of Project Settings.


#include "ATest.h"

#include "AController.h"
#include "APlane.h"
#include "EngineUtils.h"
#include "Components/LineBatchComponent.h"

// Sets default values
AATest::AATest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AATest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AATest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AATest::TestFunc()
{
	
	//GetWorld()->SpawnBrush();
	/*
	TActorIterator<AAPlane> objItr = TActorIterator<AAPlane>(GetWorld());
	
	for (objItr; objItr; ++objItr)
	{
		if(objItr->GetName() == "MyAPlane_C_" + FString::FromInt(0))
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "hello");
	}
	 */

	LineBatcher = GetWorld()->PersistentLineBatcher;	//GetDebugLineBatcher(GetWorld(), bPersistentLines, LifeTime, (DepthPriority == SDPG_Foreground));
	float LifeTime = 10.f;
	if (LineBatcher != NULL)
	{
		float LineLifeTime = (LifeTime > 0.f) ? LifeTime : LineBatcher->DefaultLifeTime;
		LineBatcher->DrawLine(FVector(-400.f, -2930.f, 3490.f), FVector(2890.f, -2930.f, 3490.f), FLinearColor::Blue, 10, 50.0f, LineLifeTime);
	}

}

