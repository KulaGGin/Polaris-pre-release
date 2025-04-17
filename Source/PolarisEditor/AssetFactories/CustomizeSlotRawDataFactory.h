// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "CustomizeSlotRawData.h"

#include "CustomizeSlotRawDataFactory.generated.h"

UCLASS()
class UCustomizeSlotRawDataFactory : public UFactory {
	GENERATED_BODY()

	UCustomizeSlotRawDataFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UCustomizeSlotRawData::StaticClass(),
			FString("Customize Slot Raw Data"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UCustomizeSlotRawData::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UCustomizeSlotRawData>(InParent, InClass, InName, Flags, Context);
	}
};
