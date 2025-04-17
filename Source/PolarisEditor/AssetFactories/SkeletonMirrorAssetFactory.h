// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "SkeletonMirrorAsset.h"

#include "SkeletonMirrorAssetFactory.generated.h"

UCLASS()
class USkeletonMirrorAssetFactory : public UFactory {
	GENERATED_BODY()

	USkeletonMirrorAssetFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			USkeletonMirrorAsset::StaticClass(),
			FString("Skeleton Mirror Asset"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = USkeletonMirrorAsset::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<USkeletonMirrorAsset>(InParent, InClass, InName, Flags, Context);
	}
};
