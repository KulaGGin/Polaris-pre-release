// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "AvatarItemPrefab.h"

#include "AvatarItemPrefabFactory.generated.h"

UCLASS()
class UAvatarItemPrefabFactory : public UFactory {
	GENERATED_BODY()

	UAvatarItemPrefabFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UAvatarItemPrefab::StaticClass(),
			FString("Avatar Item Prefab"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UAvatarItemPrefab::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UAvatarItemPrefab>(InParent, InClass, InName, Flags, Context);
	}
};
