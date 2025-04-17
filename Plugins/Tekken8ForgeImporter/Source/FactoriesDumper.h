// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetsGateway.h"
#include "AssetsStructs.h"
#include "AssetToolsModule.h"
#include "Button.h"
#include "EditableTextBox.h"
#include "EditorUtilityWidget.h"
#include "FileGateway.h"
#include "IAssetTools.h"
#include "FactoriesDumper.generated.h"

/**
 * 
 */
UCLASS()
class TEKKEN8FORGEIMPORTER_API UFactoriesDumper : public UEditorUtilityWidget {
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* AssetsPath;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* FactoryTemplatePath;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* FactoriesOutputFolder;

	UPROPERTY(meta = (BindWidget))
	UButton* DumpFactoriesButton;

	virtual bool Initialize() override {
		Super::Initialize();

		DumpFactoriesButton->OnClicked.AddUniqueDynamic(this, &UFactoriesDumper::OnDumpFactoriesButtonClicked);

		return true;
	}

	UFUNCTION()
	void OnDumpFactoriesButtonClicked() {
		DumpFactories();
	}

	// Class path name *Class->GetClassPathName().GetPackageName().ToString()
	void DumpFactories() {
		FAssetsInformation FAssetsInformation = UFileGateway::DeserializeAssetsFromJsonString(AssetsPath->GetText().ToString());
		TSet<FString> UniqueClassNames = GetUniqueClassNames(FAssetsInformation);
		FString FactoryTemplate = UFileGateway::ReadFile(FactoryTemplatePath->GetText().ToString());

		for(FString AssetClassName : UniqueClassNames) {
			auto Class = FindObject<UClass>(ANY_PACKAGE, *AssetClassName);
			if(!Class) {
				UE_LOG(LogTemp, Warning, TEXT("Couldn't find class with name %s"), *AssetClassName);
				continue;
			}

			// Check if class is a game class:
			FString ClassPath = Class->GetClassPathName().GetPackageName().ToString();

			// If not game class, just continue
			if(!ClassPath.StartsWith("/Script/Polaris")) continue;


			UFactory* Factory = UAssetsGateway::GetFactoryForClass(Class);

			if(!Factory)
				DumpFactoryForClass(Class, FactoryTemplate);
		}
	}

	void DumpFactoryForClass(UClass* Class, FString FactoryTemplate) {
		FString ClassName = Class->GetName();
		FString FactoryFileName = ClassName + TEXT("Factory.h");
		FString FactoryFilePath = FactoriesOutputFolder->GetText().ToString() + TEXT("\\") + FactoryFileName;


		FString ConcreteFactoryCode = FactoryTemplate;

		FString HeaderName = *ClassName;
		FString ClassNameWithPrefix = TEXT("U") + ClassName;
		FString FactoryHeaderName = *(ClassName + TEXT("Factory"));
		FString FactoryClassNameWithPrefix = *ClassName;

		ConcreteFactoryCode = ConcreteFactoryCode.Replace(TEXT("{AssetClassHeaderName}"), *ClassName);
		ConcreteFactoryCode = ConcreteFactoryCode.Replace(TEXT("{AssetClassName}"), *(TEXT("U") + ClassName));
		ConcreteFactoryCode = ConcreteFactoryCode.Replace(TEXT("{AssetClassNameDisplay}"), *FName::NameToDisplayString(ClassName, false));
		ConcreteFactoryCode = ConcreteFactoryCode.Replace(TEXT("{FactoryClassHeaderName}"), *(ClassName + TEXT("Factory")));
		ConcreteFactoryCode = ConcreteFactoryCode.Replace(TEXT("{FactoryClassName}"), *(TEXT("U") + ClassName + TEXT("Factory")));
		ConcreteFactoryCode = ConcreteFactoryCode.Replace(TEXT("{FactoryConstructorName}"), *(TEXT("U") + ClassName + TEXT("Factory")));

		UFileGateway::WriteFile(FactoryFilePath, ConcreteFactoryCode);
	}

	TSet<FString> GetUniqueClassNames(const FAssetsInformation& AssetsInformation) {
		TSet<FString> ClassNames;

		for(FAssetInformation Asset : AssetsInformation.Assets) {
			ClassNames.Add(Asset.AssetClass);
		}

		return ClassNames;
	}
};
