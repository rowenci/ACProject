// Fill out your copyright notice in the Description page of Project Settings.


#include "MyNewBFL.h"

#include "HAL/IPlatformFileLogWrapper.h"

bool UMyNewBFL::SaveTextArray(FString Directory, FString FileName, TArray<FString> TextArray, bool OverWrite)
{
	// 覆盖文件
	if (!OverWrite)
	{
		// 如果文件存在
		if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*(Directory + "/" + FileName)))
		{
			return false;
		}
	}
	
	return FFileHelper::SaveStringArrayToFile(TextArray, *Directory);
}

TArray<FString> UMyNewBFL::ReadTextArray(FString Directory, FString FileName)
{
	TArray<FString> TextArray;
	FFileHelper::LoadFileToStringArray(TextArray, *(Directory + "/"+ FileName));
	return TextArray;
}
