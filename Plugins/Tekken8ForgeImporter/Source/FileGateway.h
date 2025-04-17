// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetsStructs.h"
#include "FileHelper.h"
#include "JsonObjectConverter.h"
#include "UObject/NoExportTypes.h"
#include "FileGateway.generated.h"

/**
 * 
 */
UCLASS()
class TEKKEN8FORGEIMPORTER_API UFileGateway : public UObject {
	GENERATED_BODY()
public:
	static FString ReadFile(FString FilePath) {
		bool FileExists = FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath);
		if(!FileExists)
			UE_LOG(LogTemp, Warning, TEXT("File %s doesn't exist."), *FilePath);

		FString FileText;

		bool FileReadSuccess = FFileHelper::LoadFileToString(FileText, *FilePath);
		if(!FileReadSuccess)
			UE_LOG(LogTemp, Warning, TEXT("Reading file %s was not successful."), *FilePath);

		return FileText;
	}

	static void WriteFile(FString FilePath, FString FileText) {
		bool FileWriteSuccess = FFileHelper::SaveStringToFile(FileText, *FilePath);

		if(!FileWriteSuccess)
			UE_LOG(LogTemp, Warning, TEXT("Writing file %s was not successful."), *FilePath);
	}

	static FAssetsInformation DeserializeAssetsFromJsonString(FString FilePath) {
		FAssetsInformation FAssetsInformation{};

		FString AssetsText = ReadFile(FilePath);

		bool Success = FJsonObjectConverter::JsonObjectStringToUStruct(AssetsText, &FAssetsInformation);

		if(!Success) {
			UE_LOG(LogTemp, Warning, TEXT("Couldn't serialize FAssetsInformation from json string. Json string is probably incorrect."));
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Serialized FAssetsInformation successfully."));
		}

		return FAssetsInformation;
	}

	template<typename Struct>
	static void SerializeStructToFileJson(const Struct& StructObject, FString FilePath) {
		FString JsonString;
		bool Success = FJsonObjectConverter::UStructToJsonObjectString<Struct>(StructObject, JsonString);
		if(!Success)
			UE_LOG(LogTemp, Warning, TEXT("Couldn't parse struct and generate json string."));
		
		WriteFile(FilePath, JsonString);
	}
};
