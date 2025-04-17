// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "PolarisCharacterMotionOverrideData.h"

#include "PolarisCharacterMotionOverrideDataFactory.generated.h"

UCLASS()
class UPolarisCharacterMotionOverrideDataFactory : public UFactory {
	GENERATED_BODY()

	UPolarisCharacterMotionOverrideDataFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UPolarisCharacterMotionOverrideData::StaticClass(),
			FString("Polaris Character Motion Override Data"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UPolarisCharacterMotionOverrideData::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UPolarisCharacterMotionOverrideData>(InParent, InClass, InName, Flags, Context);
	}
};
