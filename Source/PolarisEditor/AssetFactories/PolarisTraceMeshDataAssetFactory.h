// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "PolarisTraceMeshDataAsset.h"

#include "PolarisTraceMeshDataAssetFactory.generated.h"

UCLASS()
class UPolarisTraceMeshDataAssetFactory : public UFactory {
	GENERATED_BODY()

	UPolarisTraceMeshDataAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UPolarisTraceMeshDataAsset::StaticClass(),
			FString("Polaris Trace Mesh Data Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UPolarisTraceMeshDataAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UPolarisTraceMeshDataAsset>(InParent, InClass, InName, Flags, Context);
	}
};
