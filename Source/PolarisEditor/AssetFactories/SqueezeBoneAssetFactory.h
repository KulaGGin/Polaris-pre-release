// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "SqueezeBoneAsset.h"

#include "SqueezeBoneAssetFactory.generated.h"

UCLASS()
class USqueezeBoneAssetFactory : public UFactory {
	GENERATED_BODY()

	USqueezeBoneAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			USqueezeBoneAsset::StaticClass(),
			FString("Squeeze Bone Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = USqueezeBoneAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<USqueezeBoneAsset>(InParent, InClass, InName, Flags, Context);
	}
};
