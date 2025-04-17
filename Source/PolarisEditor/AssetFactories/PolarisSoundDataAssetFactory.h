// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "PolarisSoundDataAsset.h"

#include "PolarisSoundDataAssetFactory.generated.h"

UCLASS()
class UPolarisSoundDataAssetFactory : public UFactory {
	GENERATED_BODY()

	UPolarisSoundDataAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UPolarisSoundDataAsset::StaticClass(),
			FString("Polaris Sound Data Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UPolarisSoundDataAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UPolarisSoundDataAsset>(InParent, InClass, InName, Flags, Context);
	}
};
