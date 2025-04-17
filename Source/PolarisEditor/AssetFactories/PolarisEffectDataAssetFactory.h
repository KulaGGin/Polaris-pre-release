// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "PolarisEffectDataAsset.h"

#include "PolarisEffectDataAssetFactory.generated.h"

UCLASS()
class UPolarisEffectDataAssetFactory : public UFactory {
	GENERATED_BODY()

	UPolarisEffectDataAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UPolarisEffectDataAsset::StaticClass(),
			FString("Polaris Effect Data Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UPolarisEffectDataAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UPolarisEffectDataAsset>(InParent, InClass, InName, Flags, Context);
	}
};
