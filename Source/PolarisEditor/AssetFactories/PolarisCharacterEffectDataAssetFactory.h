// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "PolarisCharacterEffectDataAsset.h"

#include "PolarisCharacterEffectDataAssetFactory.generated.h"

UCLASS()
class UPolarisCharacterEffectDataAssetFactory : public UFactory {
	GENERATED_BODY()

	UPolarisCharacterEffectDataAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UPolarisCharacterEffectDataAsset::StaticClass(),
			FString("Polaris Character Effect Data Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UPolarisCharacterEffectDataAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UPolarisCharacterEffectDataAsset>(InParent, InClass, InName, Flags, Context);
	}
};
