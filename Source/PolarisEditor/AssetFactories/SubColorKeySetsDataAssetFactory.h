// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "SubColorKeySetsDataAsset.h"

#include "SubColorKeySetsDataAssetFactory.generated.h"

UCLASS()
class USubColorKeySetsDataAssetFactory : public UFactory {
	GENERATED_BODY()

	USubColorKeySetsDataAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			USubColorKeySetsDataAsset::StaticClass(),
			FString("Sub Color Key Sets Data Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = USubColorKeySetsDataAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<USubColorKeySetsDataAsset>(InParent, InClass, InName, Flags, Context);
	}
};
