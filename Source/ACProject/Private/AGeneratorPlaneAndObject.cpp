// Fill out your copyright notice in the Description page of Project Settings.


#include "AGeneratorPlaneAndObject.h"

#include "ACProjectGameMode.h"
#include "AObj.h"
#include "APlane.h"

// Sets default values
AAGeneratorPlaneAndObject::AAGeneratorPlaneAndObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AAGeneratorPlaneAndObject::BeginPlay()
{
	Super::BeginPlay();
	AACProjectGameMode* gm = Cast<AACProjectGameMode>(GetWorld()->GetAuthGameMode());
	if(gm != nullptr)
	{
		// 尚未生成
		if(!gm->ActorGenerated)
		{
			// 开始生成
			// 读取第一个文件的数据
			TArray<FString> dataLine;
			FString FileName = "D:\\code\\codes\\Data\\print\\0.txt";
			FFileHelper::LoadFileToStringArray(dataLine, *FileName);
			// 遍历文件中的数据来生成飞机和障碍物
			for (auto dataOrigin : dataLine)
			{
				TArray<FString> dataNew;
				dataOrigin.ParseIntoArray(dataNew, TEXT(" "), false);

				// 对数据进行格式化，并用不同变量进行存储
				int id = FCString::Atoi(*dataNew[0]);	// 物体id
				FVector location = FVector(FCString::Atof(*dataNew[3]) * 200, FCString::Atof(*dataNew[1]) * 200, 3000.0f);	// 该帧物体所在的位置
				float direction = -FCString::Atof(*dataNew[4]);	// 该帧物体的朝向
				FRotator rotator = FRotator(.0f, direction, .0f);	// 变成ue中使用的rotator

				// 飞机
				if(gm->PlaneIdArray.Find(dataNew[0]) != INDEX_NONE)
				{
					Generator(id, location, rotator, true);
					// 存储第一帧的位置，用来在接下来飞机移动时进行轨迹展示
					gm->LastPlaneLocationMap[id] = location;
				}
				else
				{
					// 障碍物
					if(gm->ObjectIdArray.Find(dataNew[0]) != INDEX_NONE)
					{
						Generator(id, location, rotator, false);
					}
					else
					{
						GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString(TEXT("error : no such id")));
						gm->ActorGenerated = false;
					}
				}
			}
			gm->ActorGenerated = true;
		}
	}
}

// Called every frame
void AAGeneratorPlaneAndObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AAGeneratorPlaneAndObject::Generator(int id, FVector location, FRotator rotator, bool isPlane)
{
	if(isPlane)
	{
		// 生成AActor实例使用SpawnActor
		GetWorld()->SpawnActor<AAPlane>(PlaneType, location, rotator);
	}
	else
	{
		GetWorld()->SpawnActor<AAObj>(CarType, location, rotator);
	}
	return true;
}
