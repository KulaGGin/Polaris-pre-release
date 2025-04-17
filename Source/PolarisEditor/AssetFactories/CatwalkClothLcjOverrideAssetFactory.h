// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "CatwalkClothLcjOverrideAsset.h"

#include "CatwalkClothLcjOverrideAssetFactory.generated.h"

UCLASS()
class UCatwalkClothLcjOverrideAssetFactory : public UFactory {
	GENERATED_BODY()

	UCatwalkClothLcjOverrideAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UCatwalkClothLcjOverrideAsset::StaticClass(),
			FString("Catwalk Cloth Lcj Override Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UCatwalkClothLcjOverrideAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UCatwalkClothLcjOverrideAsset>(InParent, InClass, InName, Flags, Context);
	}
};
