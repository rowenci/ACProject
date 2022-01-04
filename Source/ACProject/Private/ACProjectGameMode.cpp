// Fill out your copyright notice in the Description page of Project Settings.


#include "ACProjectGameMode.h"

#include "Kismet/KismetSystemLibrary.h"

AACProjectGameMode::AACProjectGameMode()
{
	ActorGenerated = false;
	/*
	 * 游戏开始时获取飞机ID与障碍物ID
	 * 存储在PlaneIdArray和ObjectIdArray当中
	 */
	FString PlaneIds;
	FString ObjectIds;
	FString PlaneFileName = "D:\\code\\codes\\Data\\print\\index_plane.txt";
	FString ObjectFileName = "D:\\code\\codes\\Data\\print\\index_ob.txt";
	
	FFileHelper::LoadFileToString(PlaneIds, *(PlaneFileName));
	FFileHelper::LoadFileToString(ObjectIds, *(ObjectFileName));

	PlaneIds.ParseIntoArray(PlaneIdArray, TEXT(" "), false);
	ObjectIds.ParseIntoArray(ObjectIdArray, TEXT(" "), false);
	PlaneIdArray.RemoveAt(PlaneIdArray.Num() - 1);
	ObjectIds.RemoveAt(ObjectIdArray.Num() - 1);

	for (auto PlaneId : PlaneIdArray)
	{
		LastPlaneLocationMap.Add(FCString::Atoi(*PlaneId), FVector::ZeroVector);
	}
}
