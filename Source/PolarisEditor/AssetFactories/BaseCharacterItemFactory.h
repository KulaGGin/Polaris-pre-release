// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "BaseCharacterItem.h"

#include "BaseCharacterItemFactory.generated.h"

UCLASS()
class UBaseCharacterItemFactory : public UFactory {
	GENERATED_BODY()

	UBaseCharacterItemFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UBaseCharacterItem::StaticClass(),
			FString("Base Character Item"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UBaseCharacterItem::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UBaseCharacterItem>(InParent, InClass, InName, Flags, Context);
	}
};
