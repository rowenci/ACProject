// Fill out your copyright notice in the Description page of Project Settings.


#include "APlane.h"

#include "DrawDebugHelpers.h"

// Sets default values
AAPlane::AAPlane()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    //RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetupAttachment(RootComponent);

	
}

// Called when the game starts or when spawned
void AAPlane::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAPlane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

