// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "PhoenixSkeletonBinary.h"

#include "PhoenixSkeletonBinaryFactory.generated.h"

UCLASS()
class UPhoenixSkeletonBinaryFactory : public UFactory {
	GENERATED_BODY()

	UPhoenixSkeletonBinaryFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UPhoenixSkeletonBinary::StaticClass(),
			FString("Phoenix Skeleton Binary"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UPhoenixSkeletonBinary::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UPhoenixSkeletonBinary>(InParent, InClass, InName, Flags, Context);
	}
};
