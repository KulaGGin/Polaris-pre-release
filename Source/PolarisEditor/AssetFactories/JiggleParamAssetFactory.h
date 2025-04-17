// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "JiggleParamAsset.h"

#include "JiggleParamAssetFactory.generated.h"

UCLASS()
class UJiggleParamAssetFactory : public UFactory {
	GENERATED_BODY()

	UJiggleParamAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UJiggleParamAsset::StaticClass(),
			FString("Jiggle Param Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UJiggleParamAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UJiggleParamAsset>(InParent, InClass, InName, Flags, Context);
	}
};
