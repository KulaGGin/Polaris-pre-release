// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "MissileAnimDataAsset.h"

#include "MissileAnimDataAssetFactory.generated.h"

UCLASS()
class UMissileAnimDataAssetFactory : public UFactory {
	GENERATED_BODY()

	UMissileAnimDataAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UMissileAnimDataAsset::StaticClass(),
			FString("Missile Anim Data Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UMissileAnimDataAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UMissileAnimDataAsset>(InParent, InClass, InName, Flags, Context);
	}
};
