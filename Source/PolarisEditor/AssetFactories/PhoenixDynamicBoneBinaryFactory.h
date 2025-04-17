// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "PhoenixDynamicBoneBinary.h"

#include "PhoenixDynamicBoneBinaryFactory.generated.h"

UCLASS()
class UPhoenixDynamicBoneBinaryFactory : public UFactory {
	GENERATED_BODY()

	UPhoenixDynamicBoneBinaryFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UPhoenixDynamicBoneBinary::StaticClass(),
			FString("Phoenix Dynamic Bone Binary"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UPhoenixDynamicBoneBinary::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UPhoenixDynamicBoneBinary>(InParent, InClass, InName, Flags, Context);
	}
};
