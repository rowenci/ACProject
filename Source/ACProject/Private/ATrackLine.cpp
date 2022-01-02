// Fill out your copyright notice in the Description page of Project Settings.


#include "ATrackLine.h"

// Sets default values
AATrackLine::AATrackLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetupAttachment(RootComponent);
	

}

// Called when the game starts or when spawned
void AATrackLine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AATrackLine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

