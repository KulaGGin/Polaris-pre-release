// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "PolarisTracePartsDataAssetList.h"

#include "PolarisTracePartsDataAssetListFactory.generated.h"

UCLASS()
class UPolarisTracePartsDataAssetListFactory : public UFactory {
	GENERATED_BODY()

	UPolarisTracePartsDataAssetListFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UPolarisTracePartsDataAssetList::StaticClass(),
			FString("Polaris Trace Parts Data Asset List"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UPolarisTracePartsDataAssetList::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UPolarisTracePartsDataAssetList>(InParent, InClass, InName, Flags, Context);
	}
};
