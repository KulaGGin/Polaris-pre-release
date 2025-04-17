// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "GenericItemEventDataAsset.h"

#include "GenericItemEventDataAssetFactory.generated.h"

UCLASS()
class UGenericItemEventDataAssetFactory : public UFactory {
	GENERATED_BODY()

	UGenericItemEventDataAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UGenericItemEventDataAsset::StaticClass(),
			FString("Generic Item Event Data Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UGenericItemEventDataAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UGenericItemEventDataAsset>(InParent, InClass, InName, Flags, Context);
	}
};
