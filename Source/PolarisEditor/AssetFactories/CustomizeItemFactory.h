// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "CustomizeItem.h"

#include "CustomizeItemFactory.generated.h"

UCLASS()
class UCustomizeItemFactory : public UFactory {
	GENERATED_BODY()

	UCustomizeItemFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UCustomizeItem::StaticClass(),
			FString("Customize Item"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UCustomizeItem::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UCustomizeItem>(InParent, InClass, InName, Flags, Context);
	}
};
