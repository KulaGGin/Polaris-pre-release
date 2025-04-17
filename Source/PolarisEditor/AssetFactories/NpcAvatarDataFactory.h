// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "NpcAvatarData.h"

#include "NpcAvatarDataFactory.generated.h"

UCLASS()
class UNpcAvatarDataFactory : public UFactory {
	GENERATED_BODY()

	UNpcAvatarDataFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UNpcAvatarData::StaticClass(),
			FString("Npc Avatar Data"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UNpcAvatarData::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UNpcAvatarData>(InParent, InClass, InName, Flags, Context);
	}
};
