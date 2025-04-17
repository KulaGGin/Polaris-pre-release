// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetsActionsRegistrator.h"
#include "Factories/Factory.h"
#include "AuraCharacterItem.h"

#include "AuraCharacterItemFactory.generated.h"

UCLASS()
class UAuraCharacterItemFactory : public UFactory {
	GENERATED_BODY()

	UAuraCharacterItemFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UAuraCharacterItem::StaticClass(),
			FString("Aura Character Item"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UAuraCharacterItem::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UAuraCharacterItem>(InParent, InClass, InName, Flags, Context);
	}
};
