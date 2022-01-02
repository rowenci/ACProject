// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyNewBFL.generated.h"

/**
 * 
 */
UCLASS()
class ACPROJECT_API UMyNewBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	static bool  SaveTextArray(FString Directory, FString FileName, TArray<FString> TextArray, bool OverWrite);
	
	UFUNCTION(BlueprintCallable)
	static TArray<FString>  ReadTextArray(FString Directory, FString FileName);
};
