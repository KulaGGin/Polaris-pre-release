// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "PolarisTraceKindDataAsset.h"

#include "PolarisTraceKindDataAssetFactory.generated.h"

UCLASS()
class UPolarisTraceKindDataAssetFactory : public UFactory {
	GENERATED_BODY()

	UPolarisTraceKindDataAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UPolarisTraceKindDataAsset::StaticClass(),
			FString("Polaris Trace Kind Data Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UPolarisTraceKindDataAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UPolarisTraceKindDataAsset>(InParent, InClass, InName, Flags, Context);
	}
};
