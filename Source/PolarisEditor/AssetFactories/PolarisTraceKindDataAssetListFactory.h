// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "PolarisTraceKindDataAssetList.h"

#include "PolarisTraceKindDataAssetListFactory.generated.h"

UCLASS()
class UPolarisTraceKindDataAssetListFactory : public UFactory {
	GENERATED_BODY()

	UPolarisTraceKindDataAssetListFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UPolarisTraceKindDataAssetList::StaticClass(),
			FString("Polaris Trace Kind Data Asset List"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UPolarisTraceKindDataAssetList::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UPolarisTraceKindDataAssetList>(InParent, InClass, InName, Flags, Context);
	}
};
