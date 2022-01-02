// Fill out your copyright notice in the Description page of Project Settings.


#include "AObj.h"

// Sets default values
AAObj::AAObj()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AAObj::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAObj::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

