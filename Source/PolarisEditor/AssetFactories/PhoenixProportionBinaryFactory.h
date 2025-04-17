// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "PhoenixProportionBinary.h"

#include "PhoenixProportionBinaryFactory.generated.h"

UCLASS()
class UPhoenixProportionBinaryFactory : public UFactory {
	GENERATED_BODY()

	UPhoenixProportionBinaryFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UPhoenixProportionBinary::StaticClass(),
			FString("Phoenix Proportion Binary"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UPhoenixProportionBinary::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UPhoenixProportionBinary>(InParent, InClass, InName, Flags, Context);
	}
};
