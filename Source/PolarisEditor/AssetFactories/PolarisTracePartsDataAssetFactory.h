// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "PolarisTracePartsDataAsset.h"

#include "PolarisTracePartsDataAssetFactory.generated.h"

UCLASS()
class UPolarisTracePartsDataAssetFactory : public UFactory {
	GENERATED_BODY()

	UPolarisTracePartsDataAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UPolarisTracePartsDataAsset::StaticClass(),
			FString("Polaris Trace Parts Data Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UPolarisTracePartsDataAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UPolarisTracePartsDataAsset>(InParent, InClass, InName, Flags, Context);
	}
};
