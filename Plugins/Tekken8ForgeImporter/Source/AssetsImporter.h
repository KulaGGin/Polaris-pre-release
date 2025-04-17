// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetsGateway.h"
#include "AssetToolsModule.h"
#include "DebugTools.h"
#include "EditableTextBox.h"
#include "EditorUtilityWidget.h"
#include "FileHelpers.h"
#include "IAssetTools.h"
#include "PhysicsEngine/PhysicsAsset.h"
#include "UObject/NoExportTypes.h"
#include "AssetsImporter.generated.h"

/**
 * 
 */
UCLASS()
class UAssetsImporter : public UEditorUtilityWidget {
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* AssetsPath;

	UPROPERTY(meta = (BindWidget))
	UButton* ImportAssetsButton;

	virtual bool Initialize() override {
		Super::Initialize();

		ImportAssetsButton->OnClicked.AddUniqueDynamic(this, &UAssetsImporter::OnImportAssetsButtonClicked);

		return true;
	}

	UFUNCTION()
	void OnImportAssetsButtonClicked() {
		ImportAllPossibleAssets();
	}

	void ImportAllPossibleAssets() {
		FAssetsInformation FAssetsInformation = UFileGateway::DeserializeAssetsFromJsonString(AssetsPath->GetText().ToString());

		for(FAssetInformation Asset : FAssetsInformation.Assets) {
			bool PackageAlreadyExists = FPackageName::DoesPackageExist(Asset.PackageName);
			if(PackageAlreadyExists) {
				UE_LOG(LogTemp, Warning, TEXT("Package %s already exists"), *Asset.PackageName);
				continue;
			}
			UE_LOG(LogTemp, Warning, TEXT("Creating asset for %s"), *Asset.PackageName);
			auto Class = FindObject<UClass>(ANY_PACKAGE, *Asset.AssetClass);
			if(
				Class == USkeleton::StaticClass() ||
				Class == UPhysicsAsset::StaticClass() ||
				Class == UObjectRedirector::StaticClass()
				) {
				UE_LOG(LogTemp, Warning, TEXT("Can't import asset %s."), *Asset.PackageName);
				continue;
			}
			// If not a package inside the game, just continue
			if(!Asset.PackageName.StartsWith("/Game")) {
				UE_LOG(LogTemp, Warning, TEXT("%s is not a game asset"), *Asset.PackageName);
				continue;
			}

			if(!Class) {
				UE_LOG(LogTemp, Warning, TEXT("Couldn't find class with name %s"), *Asset.AssetClass);
				continue;
			}

			UObject* NewAsset = UAssetsGateway::CreateAsset(Asset.PackageName, Class);
			if(!NewAsset) {
				UE_LOG(LogTemp, Warning, TEXT("Couldn't create asset %s"), *Asset.PackagePath);
				continue;
			}
			UPackage* Package = NewAsset->GetPackage();
			UEditorLoadingAndSavingUtils::SavePackages({Package}, false);
			UEditorLoadingAndSavingUtils::SaveDirtyPackages(true, true);
			NewAsset->ConditionalBeginDestroy();
		}
	}
};
