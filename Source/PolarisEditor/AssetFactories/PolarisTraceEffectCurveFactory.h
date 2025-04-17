// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "PolarisTraceEffectCurve.h"

#include "PolarisTraceEffectCurveFactory.generated.h"

UCLASS()
class UPolarisTraceEffectCurveFactory : public UFactory {
	GENERATED_BODY()

	UPolarisTraceEffectCurveFactory() {
			UAssetsActionsRegistrator::AddTypeActionsToRegister(
			UPolarisTraceEffectCurve::StaticClass(),
			FString("Polaris Trace Effect Curve"),
			FColor::Cyan,
			UAssetsActionsRegistrator::GetAssetCategory()
		);
		SupportedClass = UPolarisTraceEffectCurve::StaticClass();
		bCreateNew = true;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override {
		return NewObject<UPolarisTraceEffectCurve>(InParent, InClass, InName, Flags, Context);
	}
};
