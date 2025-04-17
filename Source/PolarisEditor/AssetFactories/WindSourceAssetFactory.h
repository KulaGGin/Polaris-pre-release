// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "WindSourceAsset.h"

#include "WindSourceAssetFactory.generated.h"

UCLASS()
class UWindSourceAssetFactory : public UFactory {
	GENERATED_BODY()

	UWindSourceAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UWindSourceAsset::StaticClass(),
			FString("Wind Source Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UWindSourceAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UWindSourceAsset>(InParent, InClass, InName, Flags, Context);
	}
};
