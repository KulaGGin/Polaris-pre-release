// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "MobAnimationSet.h"

#include "MobAnimationSetFactory.generated.h"

UCLASS()
class UMobAnimationSetFactory : public UFactory {
	GENERATED_BODY()

	UMobAnimationSetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UMobAnimationSet::StaticClass(),
			FString("Mob Animation Set"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UMobAnimationSet::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UMobAnimationSet>(InParent, InClass, InName, Flags, Context);
	}
};
