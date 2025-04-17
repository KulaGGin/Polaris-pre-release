// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "LobbyAvatarData.h"

#include "LobbyAvatarDataFactory.generated.h"

UCLASS()
class ULobbyAvatarDataFactory : public UFactory {
	GENERATED_BODY()

	ULobbyAvatarDataFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			ULobbyAvatarData::StaticClass(),
			FString("Lobby Avatar Data"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = ULobbyAvatarData::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<ULobbyAvatarData>(InParent, InClass, InName, Flags, Context);
	}
};
