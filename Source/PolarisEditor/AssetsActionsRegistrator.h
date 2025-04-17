// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetToolsModule.h"
#include "AssetTypeActions.h"
#include "AssetTypeCategories.h"
#include "UObjectIterator.h"
#include "Factories/Factory.h"
#include "AssetsActionsRegistrator.generated.h"

/**
 * 
 */
UCLASS()
class UAssetsActionsRegistrator : public UObject {
	GENERATED_BODY()
public:
	static EAssetTypeCategories::Type GetAssetCategory() {
		RegisterAssetCategory();
		return PolarisAssetCategory;
	}

	static void RegisterAssetCategory() {
		static bool AlreadyRegistered{};
		if(AlreadyRegistered) return;
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
		PolarisAssetCategory = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("Polaris")), FText::FromString(TEXT("Polaris")));
	}

	// We can only register type actions that are derived from FAssetTypeActions_Base;
	template<typename Type, typename = typename TEnableIf<TIsDerivedFrom<Type, FAssetTypeActions_Base>::Value>::Type>
	static void AddTypeActionsToRegister() {
		RegisterAssetCategory();
		auto TypeAction = MakeShareable(new Type());
		RegisteredAssetTypeActions.Add(TypeAction);
	}

	static void AddTypeActionsToRegister(
		UClass* AssetClass,
		FString AssetActionName,
		FColor Color = FColor::Cyan,
		EAssetTypeCategories::Type Category = GetAssetCategory()) {
		if(RegisteredAssetTypeActions.Contains(AssetClass)) return;
		auto AssetTypeActions = MakeShared<FAssetTypeActions>(AssetClass, AssetActionName, Color, Category);
		RegisteredAssetTypeActions.Add(AssetClass, AssetTypeActions);
	}

	static void RegisterAllTypeActions() {
		for(TObjectIterator<UClass> ClassIt; ClassIt; ++ClassIt) {
			UClass* Class = *ClassIt;
			if(Class->IsChildOf(UFactory::StaticClass()) && Class != UFactory::StaticClass()) {
				auto ClassPackage = Class->GetClassPathName().GetPackageName().ToString();
				if(ClassPackage.StartsWith("/Script/PolarisEditor"))
					NewObject<UObject>(GetTransientPackage(), Class);
			}
		}

		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
		for(auto RegisteredTypeAction : RegisteredAssetTypeActions)
			AssetTools.RegisterAssetTypeActions(RegisteredTypeAction.Value.ToSharedRef());

	}

	static void UnregisterAllTypeActions() {
		if(!FModuleManager::Get().IsModuleLoaded("AssetTools")) return;
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();

		for(auto AssetTypeAction : RegisteredAssetTypeActions)
			AssetTools.UnregisterAssetTypeActions(AssetTypeAction.Value.ToSharedRef());

		RegisteredAssetTypeActions.Empty();
	}
private:
	UAssetsActionsRegistrator() = default;

	inline static EAssetTypeCategories::Type PolarisAssetCategory;
	inline static TMap<UClass*, TSharedPtr<IAssetTypeActions>> RegisteredAssetTypeActions;
};
