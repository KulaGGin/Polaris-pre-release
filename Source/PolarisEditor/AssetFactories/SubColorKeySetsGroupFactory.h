// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "SubColorKeySetsGroup.h"

#include "SubColorKeySetsGroupFactory.generated.h"

UCLASS()
class USubColorKeySetsGroupFactory : public UFactory {
	GENERATED_BODY()

	USubColorKeySetsGroupFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			USubColorKeySetsGroup::StaticClass(),
			FString("Sub Color Key Sets Group"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = USubColorKeySetsGroup::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<USubColorKeySetsGroup>(InParent, InClass, InName, Flags, Context);
	}
};
