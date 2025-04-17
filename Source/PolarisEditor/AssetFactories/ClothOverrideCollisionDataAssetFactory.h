// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "ClothOverrideCollisionDataAsset.h"

#include "ClothOverrideCollisionDataAssetFactory.generated.h"

UCLASS()
class UClothOverrideCollisionDataAssetFactory : public UFactory {
	GENERATED_BODY()

	UClothOverrideCollisionDataAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UClothOverrideCollisionDataAsset::StaticClass(),
			FString("Cloth Override Collision Data Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UClothOverrideCollisionDataAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UClothOverrideCollisionDataAsset>(InParent, InClass, InName, Flags, Context);
	}
};
