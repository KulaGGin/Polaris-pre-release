// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "MobAlpacaActionSet.h"

#include "MobAlpacaActionSetFactory.generated.h"

UCLASS()
class UMobAlpacaActionSetFactory : public UFactory {
	GENERATED_BODY()

	UMobAlpacaActionSetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UMobAlpacaActionSet::StaticClass(),
			FString("Mob Alpaca Action Set"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UMobAlpacaActionSet::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UMobAlpacaActionSet>(InParent, InClass, InName, Flags, Context);
	}
};
