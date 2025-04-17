// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetToolsModule.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "UObject/NoExportTypes.h"
#include "AssetsGateway.generated.h"

/**
 * 
 */
UCLASS()
class TEKKEN8FORGEIMPORTER_API UAssetsGateway : public UObject {
	GENERATED_BODY()
public:

	static TArray<FAssetData> GetAllAssets() {
		FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
		IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

		TArray<FAssetData> AllAssets;
		AssetRegistry.GetAllAssets(AllAssets);

		return AllAssets;
	}

	template<typename Type>
	static Type* TryLoadAsset(FString AssetPath) {
		FSoftObjectPath SoftObjectPath(AssetPath);

		Type* LoadedAsset = Cast<Type>(SoftObjectPath.TryLoad());
		auto Package = LoadedAsset->GetPackage();
		if(!LoadedAsset)
			UE_LOG(LogTemp, Warning, TEXT("Couldn't load Asset with path: %s"), *AssetPath);

		return LoadedAsset;
	}

	// Loads C++ or a blueprint class from soft class path
	// For blueprint classes soft class path looks like /Game/Stage/Common/Blueprints/BP_PolarisFloor.BP_PolarisFloor_C
	// For C++ classes soft class path looks like /Script/Polaris.PolarisStageFloorActor
	template<typename BaseType>
	__declspec(noinline) static UClass* TryLoadClass(FString SoftClassPath) {
		UClass* Class = FSoftClassPath(SoftClassPath).TryLoadClass<BaseType>();
		if(!Class)
			UE_LOG(LogTemp, Warning, TEXT("Couldn't load class from soft class path %s"), *SoftClassPath);

		return Class;
	}

	static UObject* CreateAsset(FString AssetPath, UClass* AssetClass, UFactory* Factory) {
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();

		UObject* NewAsset = AssetTools.CreateAsset(FPaths::GetBaseFilename(AssetPath), FPaths::GetPath(AssetPath), AssetClass, Factory);
		if(!NewAsset)
			UE_LOG(LogTemp, Warning, TEXT("Couldn't create asset of class %s at path %s"), *AssetClass->GetName(), *AssetPath);
		

		return NewAsset;
	}

	static UObject* CreateAsset(FString AssetPath, UClass* AssetClass) {
		UFactory* Factory = GetFactoryForClass(AssetClass);

		if(!Factory)
			return nullptr;

		return CreateAsset(AssetPath, AssetClass, Factory);
	}

	static UFactory* GetFactoryForClass(UClass* Class) {
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();

		for(UFactory* CurrentFactory : AssetTools.GetNewAssetFactories()) {
			if(CurrentFactory->SupportedClass == Class)
				return CurrentFactory;
		}

		UE_LOG(LogTemp, Warning, TEXT("Couldn't find factory for class %s in IAssetTools"), *Class->GetName());

		for(TObjectIterator<UClass> ClassIt; ClassIt; ++ClassIt) {
			UClass* CurrentClass = *ClassIt;
			if(CurrentClass->IsChildOf(UFactory::StaticClass()) && CurrentClass != UFactory::StaticClass()) {
				if(CurrentClass->ClassFlags & CLASS_Abstract)
					continue;
				UFactory* CurrentFactory = NewObject<UFactory>(GetTransientPackage(), CurrentClass);
				if(CurrentFactory->SupportedClass == Class)
					return CurrentFactory;
			}
		}

		UE_LOG(LogTemp, Warning, TEXT("Couldn't find factory for class %s"), *Class->GetName());

		return nullptr;
	}
};
