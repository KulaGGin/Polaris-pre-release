// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetsStructs.generated.h"

USTRUCT(BlueprintType)
struct FTopLevelAssetPathInformation {
	GENERATED_BODY()

	UPROPERTY()
	FString AssetName;

	UPROPERTY()
	FString PackageName;
};

USTRUCT(BlueprintType)
struct FAssetInformation {
	GENERATED_BODY()

	UPROPERTY()
	FString AssetClass;

	UPROPERTY()
	FString AssetName;

	UPROPERTY()
	FString PackageName;

	UPROPERTY()
	FString PackagePath;

	UPROPERTY()
	FTopLevelAssetPathInformation FTopLevelAssetPath;
};

USTRUCT(BlueprintType)
struct FAssetsInformation {
	GENERATED_BODY()

	UPROPERTY()
	TArray<FAssetInformation> Assets{};
};
