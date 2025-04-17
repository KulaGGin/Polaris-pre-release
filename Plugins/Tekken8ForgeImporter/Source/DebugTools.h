// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetsGateway.h"
#include "AssetsStructs.h"
#include "Button.h"
#include "EditableTextBox.h"
#include "EditorUtilityWidget.h"
#include "FileGateway.h"
#include "JsonObjectConverter.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "UObject/UObjectGlobals.h"
#include "UObject/ConstructorHelpers.h"
#include "PolarisBattleEventManager.h"
#include "DebugTools.generated.h"



USTRUCT()
struct FClassInformation {
	GENERATED_BODY()

	UPROPERTY()
	FString ClassSoftObjectPath;

	UPROPERTY()
	FString ParentSoftObjectPath;
};

USTRUCT()
struct FClassesInformation {
	GENERATED_BODY()

	UPROPERTY()
	TArray<FClassInformation> ClassesInformation;
};


UCLASS()
class TEKKEN8FORGEIMPORTER_API UDebugTools : public UEditorUtilityWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	UButton* LogAssetsButton;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* AssetsPathTextBox;

	UPROPERTY(meta = (BindWidget))
	UButton* CountAssetInstancesButton;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* BlueprintClassesPath;
	UPROPERTY(meta = (BindWidget))
	UButton* LogBlueprintClassesButton;

	virtual bool Initialize() override {
		Super::Initialize();

		LogAssetsButton->OnClicked.AddUniqueDynamic(this, &UDebugTools::OnLogAssetsButtonClicked);
		CountAssetInstancesButton->OnClicked.AddUniqueDynamic(this, &UDebugTools::OnCountAssetInstancesButton);
		LogBlueprintClassesButton->OnClicked.AddUniqueDynamic(this, &UDebugTools::LogBlueprintClasses);


		return true;
	}

	UFUNCTION()
	void OnLogAssetsButtonClicked() {
		LogAssets();
	}

	UFUNCTION()
	void OnCountAssetInstancesButton() {
		CountInstancesOfAssets();
	}


	void LogAssets() {
		TArray<FAssetData> AllAssets = UAssetsGateway::GetAllAssets();

		for(auto CurrentAsset : AllAssets) {
			UClass* AssetClass = CurrentAsset.GetClass();
			FString AssetPath = CurrentAsset.PackagePath.ToString();
			if(!AssetClass) {
				UE_LOG(LogTemp, Warning, TEXT("Couldn't get class for asset: %s"), *AssetPath);
				continue;
			}
			UE_LOG(LogTemp, Warning, TEXT("Asset at path: %s has class: %s"), *AssetPath, *AssetClass->GetName());
		}
	}

	void CountInstancesOfAssets() {
		TMap<FString, int> ClassesAndInstancesNumber;
		FAssetsInformation FAssetsInformation = UFileGateway::DeserializeAssetsFromJsonString(AssetsPathTextBox->GetText().ToString());

		for(FAssetInformation Asset : FAssetsInformation.Assets) {
			auto AssetClassName = Asset.AssetClass;
			if(!ClassesAndInstancesNumber.Contains(AssetClassName))
				ClassesAndInstancesNumber.Add(AssetClassName, 0);

			ClassesAndInstancesNumber[Asset.AssetClass]++;
		}

		TArray<TPair<FString, int>> SortedArray;

		for(const TPair<FString, int32>& Elem : ClassesAndInstancesNumber) {
			SortedArray.Add(Elem);
		}

		SortedArray.Sort([](const TPair<FString, int>& A, const TPair<FString, int>& B) {
			return A.Value > B.Value; // Sort by value (descending order)
			});

		for(TPair<FString, int> ClassInstanceNumber : SortedArray) {
			UE_LOG(LogTemp, Warning, TEXT("%s %i"), *ClassInstanceNumber.Key, ClassInstanceNumber.Value);
		}
	}

	void LogFactoryClasses() {
		for(TObjectIterator<UClass> ClassIt; ClassIt; ++ClassIt) {
			UClass* Class = *ClassIt;
			if(Class->IsChildOf(UFactory::StaticClass()) && Class != UFactory::StaticClass()) {
				auto ClassPackage = Class->GetClassPathName().GetPackageName().ToString();
				if(ClassPackage.StartsWith("/Game"))
					NewObject<UObject>(GetTransientPackage(), Class);
				UE_LOG(LogTemp, Warning, TEXT("Factory %s is at path %s"), *Class->GetName(), *ClassPackage);
			}
		}
	}

	UFUNCTION()
	void LogBlueprintClasses() {
		FString AssetPath = TEXT("/Game/Blueprints/BP_PolarisBattleEventManager");
		UClass* FindOrLoadClassClass = ConstructorHelpersInternal::FindOrLoadClass(AssetPath, UObject::StaticClass());
		FTopLevelAssetPath ClassPath(FindOrLoadClassClass);
		FTopLevelAssetPath PolarisBattleEventManagerPath(APolarisBattleEventManager::StaticClass());
		FString PolarisBattleEventManagerClassPath = PolarisBattleEventManagerPath.GetPackageName().ToString();
		UClass* PolarisBattleEventManagerClass = ConstructorHelpersInternal::FindOrLoadClass(PolarisBattleEventManagerClassPath, UObject::StaticClass());
		FString PolarisBattleEventManagerClassName = PolarisBattleEventManagerClass->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *PolarisBattleEventManagerClassName);

		FString ClassesString = FindOrLoadClassClass->GetName();
		for(UClass* Class = FindOrLoadClassClass->GetSuperClass(); Class; Class = Class->GetSuperClass()) {
			ClassesString = ClassesString + TEXT(":") + Class->GetName();
		}

		UE_LOG(LogTemp, Warning, TEXT("%s"), *ClassesString);

		for(UClass* Class = FindOrLoadClassClass; Class; Class = Class->GetSuperClass()) {
			FString ClassName = Class->GetName();
			bool BlueprintClass = (bool)Class->ClassGeneratedBy;
			UE_LOG(LogTemp, Warning, TEXT("%s is blueprint: %i"), *Class->GetName(), BlueprintClass);
		}
	}
};
