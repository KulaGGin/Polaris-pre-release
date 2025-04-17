// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "BaseMakeItem.h"

#include "BaseMakeItemFactory.generated.h"

UCLASS()
class UBaseMakeItemFactory : public UFactory {
	GENERATED_BODY()

	UBaseMakeItemFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UBaseMakeItem::StaticClass(),
			FString("Base Make Item"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UBaseMakeItem::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UBaseMakeItem>(InParent, InClass, InName, Flags, Context);
	}
};
