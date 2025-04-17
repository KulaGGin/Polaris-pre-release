// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "EffectCharacterItem.h"

#include "EffectCharacterItemFactory.generated.h"

UCLASS()
class UEffectCharacterItemFactory : public UFactory {
	GENERATED_BODY()

	UEffectCharacterItemFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UEffectCharacterItem::StaticClass(),
			FString("Effect Character Item"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UEffectCharacterItem::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UEffectCharacterItem>(InParent, InClass, InName, Flags, Context);
	}
};
