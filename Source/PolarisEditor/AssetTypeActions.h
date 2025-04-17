// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"
#include "UObject/NoExportTypes.h"

/**
 * 
 */

class FAssetTypeActions : public FAssetTypeActions_Base {
public:
	FAssetTypeActions(UClass* AssetClass,
		FString AssetActionName,
		FColor Color,
		EAssetTypeCategories::Type Category) {
		this->AssetClass = AssetClass;
		this->AssetActionName = FText::FromString(AssetActionName);
		this->Color = Color;
		this->Category = Category;
	}

	virtual UClass* GetSupportedClass() const override {
		return AssetClass;
	}

	virtual FText GetName() const override {
		return AssetActionName;
	}

	virtual FColor GetTypeColor() const override {
		return Color;
	}

	virtual uint32 GetCategories() override {
		return Category;
	}
private:
	UClass* AssetClass;
	FText AssetActionName;
	FColor Color;
	EAssetTypeCategories::Type Category;
};
