// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "DynamicBoneParamAsset.h"

#include "DynamicBoneParamAssetFactory.generated.h"

UCLASS()
class UDynamicBoneParamAssetFactory : public UFactory {
	GENERATED_BODY()

	UDynamicBoneParamAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UDynamicBoneParamAsset::StaticClass(),
			FString("Dynamic Bone Param Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UDynamicBoneParamAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UDynamicBoneParamAsset>(InParent, InClass, InName, Flags, Context);
	}
};
