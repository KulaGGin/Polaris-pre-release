// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "ItemPrefab.h"

#include "ItemPrefabFactory.generated.h"

UCLASS()
class UItemPrefabFactory : public UFactory {
	GENERATED_BODY()

	UItemPrefabFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UItemPrefab::StaticClass(),
			FString("Item Prefab"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UItemPrefab::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UItemPrefab>(InParent, InClass, InName, Flags, Context);
	}
};
