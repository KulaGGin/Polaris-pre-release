// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "BaseEyeItem.h"

#include "BaseEyeItemFactory.generated.h"

UCLASS()
class UBaseEyeItemFactory : public UFactory {
	GENERATED_BODY()

	UBaseEyeItemFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UBaseEyeItem::StaticClass(),
			FString("Base Eye Item"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UBaseEyeItem::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UBaseEyeItem>(InParent, InClass, InName, Flags, Context);
	}
};
