// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "PolarisTraceDataAsset.h"

#include "PolarisTraceDataAssetFactory.generated.h"

UCLASS()
class UPolarisTraceDataAssetFactory : public UFactory {
	GENERATED_BODY()

	UPolarisTraceDataAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UPolarisTraceDataAsset::StaticClass(),
			FString("Polaris Trace Data Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UPolarisTraceDataAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UPolarisTraceDataAsset>(InParent, InClass, InName, Flags, Context);
	}
};
