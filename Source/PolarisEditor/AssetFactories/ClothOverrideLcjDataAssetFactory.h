// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "ClothOverrideLcjDataAsset.h"

#include "ClothOverrideLcjDataAssetFactory.generated.h"

UCLASS()
class UClothOverrideLcjDataAssetFactory : public UFactory {
	GENERATED_BODY()

	UClothOverrideLcjDataAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UClothOverrideLcjDataAsset::StaticClass(),
			FString("Cloth Override Lcj Data Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UClothOverrideLcjDataAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UClothOverrideLcjDataAsset>(InParent, InClass, InName, Flags, Context);
	}
};
