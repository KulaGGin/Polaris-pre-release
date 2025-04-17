// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "GFurAsset.h"

#include "GFurAssetFactory.generated.h"

UCLASS()
class UGFurAssetFactory : public UFactory {
	GENERATED_BODY()

	UGFurAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UGFurAsset::StaticClass(),
			FString("GFur Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UGFurAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UGFurAsset>(InParent, InClass, InName, Flags, Context);
	}
};
