// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "CustomizeSet.h"

#include "CustomizeSetFactory.generated.h"

UCLASS()
class UCustomizeSetFactory : public UFactory {
	GENERATED_BODY()

	UCustomizeSetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UCustomizeSet::StaticClass(),
			FString("Customize Set"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UCustomizeSet::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UCustomizeSet>(InParent, InClass, InName, Flags, Context);
	}
};
