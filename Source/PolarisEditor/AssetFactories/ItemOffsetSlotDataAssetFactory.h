// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "ItemOffsetSlotDataAsset.h"

#include "ItemOffsetSlotDataAssetFactory.generated.h"

UCLASS()
class UItemOffsetSlotDataAssetFactory : public UFactory {
	GENERATED_BODY()

	UItemOffsetSlotDataAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UItemOffsetSlotDataAsset::StaticClass(),
			FString("Item Offset Slot Data Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UItemOffsetSlotDataAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UItemOffsetSlotDataAsset>(InParent, InClass, InName, Flags, Context);
	}
};
