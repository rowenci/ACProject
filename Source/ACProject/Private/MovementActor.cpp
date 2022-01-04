// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementActor.h"

#include "ACProjectGameMode.h"
#include "AObj.h"
#include "APlane.h"
#include "ATrackLine.h"
#include "DrawDebugHelpers.h"
#include "EngineUtils.h"
#include "Components/LineBatchComponent.h"

// Sets default values
AMovementActor::AMovementActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	frame = 900;
	frame_count = 1;
	Directory = "D:\\code\\codes\\Data\\print";
	
	LineLifeTime = 100.f;
}



// Called when the game starts or when spawned
void AMovementActor::BeginPlay()
{
	Super::BeginPlay();
	gm = Cast<AACProjectGameMode>(GetWorld()->GetAuthGameMode());
}

// Called every frame
void AMovementActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	flag = gm->ActorGenerated;
	LineBatch = GetWorld()->PersistentLineBatcher;	//GetDebugLineBatcher(GetWorld(), bPersistentLines, LifeTime, (DepthPriority == SDPG_Foreground));
	if(flag)
	{
		if (frame_count <= frame)
		{
			TArray<FString> dataLine;
			FFileHelper::LoadFileToStringArray(dataLine, *(Directory + "\\" + FString::FromInt(frame_count) + ".txt"));
			frame_count++;

			for (auto dataOrigin : dataLine)
			{
				// 获取数据
				TArray<FString> dataNew;
				dataOrigin.ParseIntoArray(dataNew, TEXT(" "), false);


				int id = FCString::Atoi(*dataNew[0]);
				FVector location = FVector(FCString::Atof(*dataNew[3]) * 200, FCString::Atof(*dataNew[1]) * 200, 3000.0f);
				float direction = -FCString::Atof(*dataNew[4]);
				FRotator rotator = FRotator(.0f, direction, .0f);

				
				// GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::FromInt(id) + " " + location.ToString() + " " + FString::SanitizeFloat(direction));

				// 是飞机
				if(gm->PlaneIdArray.Find(FString::FromInt(id)) != INDEX_NONE)
				{
					// 获取所有的飞机actor
					TActorIterator<AAPlane> planeItr = TActorIterator<AAPlane>(GetWorld());
					// 遍历飞机actor来找到对应id的actor
					for (planeItr; planeItr; ++planeItr) {
						if (planeItr) {
							// 获取该飞机上一帧的坐标
							FVector lastLocation = gm->LastPlaneLocationMap[id];
							// 设置第一辆生成的飞机的位置
							if (planeItr->GetName() == "MyAPlane_C_" + FString::FromInt(id)) {
								planeItr->SetActorLocation(location);
								// GetWorld()->SpawnActor<AATrackLine>(TrackLineType, location, FRotator::ZeroRotator);
								planeItr->SetActorRotation(rotator);

								// 画线
								if (LineBatch != nullptr)
								{
									// LineBatch->DrawLine(lastLocation, location, FLinearColor::Blue, 10, 50.0f, LineLifeTime);
									// DrawDebugLine(GetWorld(), lastLocation, location, FColor::Blue, false, LineLifeTime, 10, 50.0f);
									DrawDebugPoint(GetWorld(), location, 10.0f, FColor::Blue,  false, LineLifeTime, 10);
								}
								// 画完后更改对应的坐标
								gm->LastPlaneLocationMap[id] = location;
							}
						}
					}
				}
				else
				{
					// 是障碍物
					if(gm->ObjectIdArray.Find(FString::FromInt(id)) != INDEX_NONE)
					{
						// 获取所有的障碍物actor
						TActorIterator<AAObj> objItr = TActorIterator<AAObj>(GetWorld());
						// 遍历障碍物actor来找到对应id的actor
						for (objItr; objItr; ++objItr) {
							if (objItr) {
								// 设置第一辆生成的障碍物的位置
								if (objItr->GetName() == "MyAObj_C_" + FString::FromInt(id)) {
									objItr->SetActorLocation(location);
									// GetWorld()->SpawnActor<AATrackLine>(TrackLineType, location, FRotator::ZeroRotator);
									objItr->SetActorRotation(rotator);
								}
							}
						}
					}
				}
			}
			//GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMovementActor::Delay, 1.0f, true);
			//FPlatformProcess::Sleep(0.05f);
		}
	}

}

void AMovementActor::Delay()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}
