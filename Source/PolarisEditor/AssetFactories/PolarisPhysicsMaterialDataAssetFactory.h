// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "PolarisPhysicsMaterialDataAsset.h"

#include "PolarisPhysicsMaterialDataAssetFactory.generated.h"

UCLASS()
class UPolarisPhysicsMaterialDataAssetFactory : public UFactory {
	GENERATED_BODY()

	UPolarisPhysicsMaterialDataAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UPolarisPhysicsMaterialDataAsset::StaticClass(),
			FString("Polaris Physics Material Data Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UPolarisPhysicsMaterialDataAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UPolarisPhysicsMaterialDataAsset>(InParent, InClass, InName, Flags, Context);
	}
};
