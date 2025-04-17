// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "PolarisWeaponEffectDataAsset.h"

#include "PolarisWeaponEffectDataAssetFactory.generated.h"

UCLASS()
class UPolarisWeaponEffectDataAssetFactory : public UFactory {
	GENERATED_BODY()

	UPolarisWeaponEffectDataAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UPolarisWeaponEffectDataAsset::StaticClass(),
			FString("Polaris Weapon Effect Data Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UPolarisWeaponEffectDataAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UPolarisWeaponEffectDataAsset>(InParent, InClass, InName, Flags, Context);
	}
};
