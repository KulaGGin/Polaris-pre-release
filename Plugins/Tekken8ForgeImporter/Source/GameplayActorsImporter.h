// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetsGateway.h"
#include "AssetToolsModule.h"
#include "Button.h"
#include "EditableTextBox.h"
#include "EditorUtilityWidget.h"
#include "FileGateway.h"
#include "JsonObjectConverter.h"
#include "LevelSequence.h"
#include "PolarisBattlePlayerStart.h"
#include "PolarisStageFloorActor.h"
#include "PolarisStageWallActor.h"
#include "WorldGateway.h"
#include "Misc/FileHelper.h"
#include "GameplayActorsImporter.generated.h"

USTRUCT(BlueprintType)
struct FBoundingSphere {
	GENERATED_BODY()
	FVector Location;
	float Radius;
};

USTRUCT(BlueprintType)
struct FFloat3 {
	GENERATED_BODY()

		UPROPERTY()
		float X{};
	UPROPERTY()
		float Y{};
	UPROPERTY()
		float Z{};

	operator FVector() {
		return FVector{X, Y, Z};
	}

	operator FRotator() {
		return FRotator{X, Y, Z};
	}
};

USTRUCT(BlueprintType)
struct FActorInformation {
	GENERATED_BODY()

		UPROPERTY()
		FString Name;
	UPROPERTY()
		FFloat3 Position {};
	UPROPERTY()
		FFloat3 Rotation {};
	UPROPERTY()
		FFloat3 Scale {};
};

USTRUCT(BlueprintType)
struct FLevelSequenceInformation {
	GENERATED_BODY()

		UPROPERTY()
		FString ObjectPath;
};

USTRUCT(BlueprintType)
struct FPolarisBattlePlayerStartInformation {
	GENERATED_BODY()

		UPROPERTY()
		FString Camera1P;
	UPROPERTY()
		FString Camera2P;
};

USTRUCT(BlueprintType)
struct FPolarisStageForcusCameraInformation {
	GENERATED_BODY()

		UPROPERTY()
		int BattleRound;

	UPROPERTY()
		FString Camera1P;
	UPROPERTY()
		FString Camera2P;
};

USTRUCT(BlueprintType)
struct FPlayerStartInformation {
	GENERATED_BODY()

		UPROPERTY()
		FString SoftClassPath;
	UPROPERTY()
		FString ActorName;
	UPROPERTY()
		FFloat3 Position {};
	UPROPERTY()
		FFloat3 Rotation {};
	UPROPERTY()
		FFloat3 Scale {};

	UPROPERTY()
		int StageSequenceId;
	UPROPERTY()
		int StageBrokenHistory;
	UPROPERTY()
		EStagePositionTypeId StagePositionTypeId;
	UPROPERTY()
		int FloorId;
	UPROPERTY()
		EStageLightType StageLightType;
	UPROPERTY()
		float Distance;
	UPROPERTY()
		bool IsWallAdjust;
	UPROPERTY()
		TArray<FPolarisBattlePlayerStartInformation> RoundStartCameraAssets;
	UPROPERTY()
		TArray<FPolarisStageForcusCameraInformation> StageForcusCameraAssets;
};

USTRUCT(BlueprintType)
struct FFloorInformation {
	GENERATED_BODY()

		UPROPERTY()
		FString SoftClassPath;

	UPROPERTY()
		FString ActorName;

	UPROPERTY()
		FFloat3 Position {};
	UPROPERTY()
		FFloat3 Rotation {};
	UPROPERTY()
		FFloat3 Scale {};

	UPROPERTY()
		bool IsFloorBreakable;
	UPROPERTY()
		bool IsStageDestruction;
	UPROPERTY()
		bool IsDummyBreak;
	UPROPERTY()
		bool IsFloorBlast;

	UPROPERTY()
		EStageGimmickState State;
	UPROPERTY()
		int SetNo;
	UPROPERTY()
		int  FloorNo;
	UPROPERTY()
		int RelatedStageSequenceId;
	UPROPERTY()
		bool IsNextStageSequence;
	UPROPERTY()
		bool TKCollisionEnable;
	UPROPERTY()
		int WallDamageId;
	UPROPERTY()
		int TotalDamage;
	UPROPERTY()
		bool IsDurable;
	UPROPERTY()
		int DestructLevel;
};

USTRUCT(BlueprintType)
struct FWallInformation {
	GENERATED_BODY()

		UPROPERTY()
		FString SoftClassPath;

	UPROPERTY()
		FString ActorName;

	UPROPERTY()
		FString Name;

	UPROPERTY()
		FFloat3 Position {};
	UPROPERTY()
		FFloat3 Rotation {};
	UPROPERTY()
		FFloat3 Scale {};

	UPROPERTY()
		int WallAttribute;
	UPROPERTY()
		bool  IsNoBreak;

	UPROPERTY()
		EStageGimmickState State;
	UPROPERTY()
		int SetNo;
	UPROPERTY()
		int  FloorNo;
	UPROPERTY()
		int RelatedStageSequenceId;
	UPROPERTY()
		bool IsNextStageSequence;
	UPROPERTY()
		bool TKCollisionEnable;
	UPROPERTY()
		int WallDamageId;
	UPROPERTY()
		int TotalDamage;
	UPROPERTY()
		bool IsDurable;
	UPROPERTY()
		int DestructLevel;
};

USTRUCT(BlueprintType)
struct FGameplayActors {
	GENERATED_BODY()

		UPROPERTY()
		TArray<FPlayerStartInformation> PlayerStarts{};
	UPROPERTY()
		TArray<FFloorInformation> Floors{};
	UPROPERTY()
		TArray<FWallInformation> Walls{};
};

/**
 * 
 */
UCLASS()
class TEKKEN8FORGEIMPORTER_API UGameplayActorsImporter : public UEditorUtilityWidget {
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* GameplayActorsPath;

	UPROPERTY(meta = (BindWidget))
	UButton* ImportGameplayActors;

	virtual bool Initialize() override {
		Super::Initialize();
		ImportGameplayActors->OnClicked.AddUniqueDynamic(this, &UGameplayActorsImporter::OnImportGameplayActorsButtonClicked);
		return true;
	}

	UFUNCTION()
	void OnImportGameplayActorsButtonClicked() {
		SpawnGameplayActors();
	}

	void SpawnGameplayActors() {
		FGameplayActors GameplayActors = DeserializeGameplayActorsFromJsonString();

		SpawnPlayerStarts(GameplayActors);
		SpawnFloors(GameplayActors);
		SpawnWalls(GameplayActors);
	}

	void SpawnPlayerStarts(const FGameplayActors& GameplayActors) {
		for(auto PlayerStart : GameplayActors.PlayerStarts) {
			SpawnPlayerStart(PlayerStart);
		}
	}

	void SpawnPlayerStart(FPlayerStartInformation PlayerStartInfo) {
		APolarisBattlePlayerStart* PlayerStartActor = GetWorld()->SpawnActor<APolarisBattlePlayerStart>(PlayerStartInfo.Position, PlayerStartInfo.Rotation, {});
		PlayerStartActor->SetActorLabel(PlayerStartInfo.ActorName);
		PlayerStartActor->StageSequenceId = PlayerStartInfo.StageSequenceId;
		PlayerStartActor->StageBrokenHistory = PlayerStartInfo.StageBrokenHistory;
		PlayerStartActor->StagePositionTypeId = PlayerStartInfo.StagePositionTypeId;
		PlayerStartActor->FloorId = PlayerStartInfo.FloorId;
		PlayerStartActor->StageLightType = PlayerStartInfo.StageLightType;
		PlayerStartActor->Distance = PlayerStartInfo.Distance;
		PlayerStartActor->IsWallAdjust = PlayerStartInfo.IsWallAdjust;

		InitRoundStartCameraAssetsFromPlayerInfo(PlayerStartActor, PlayerStartInfo);
		InitStageForcusCameraAssetsFromPlayerInfo(PlayerStartActor, PlayerStartInfo);
	}

	void InitRoundStartCameraAssetsFromPlayerInfo(
		APolarisBattlePlayerStart* PlayerStartActor,
		FPlayerStartInformation PlayerStartInfo) {
		for(auto ForcusCameraAsset : PlayerStartInfo.RoundStartCameraAssets) {
			auto& [Camera1P, Camera2P] = ForcusCameraAsset;
			ULevelSequence* Camera1LoadedSequence = UAssetsGateway::TryLoadAsset<ULevelSequence>(Camera1P);
			ULevelSequence* Camera2LoadedSequence = UAssetsGateway::TryLoadAsset<ULevelSequence>(Camera2P);

			FPolarisBattlePlayerStartCamera PlayerStartCamera{};
			PlayerStartCamera.Camera1P = Camera1LoadedSequence;
			PlayerStartCamera.Camera2P = Camera2LoadedSequence;
			if(Camera1LoadedSequence || Camera2LoadedSequence)
				PlayerStartActor->RoundStartCameraAssets.Add(PlayerStartCamera);
		}
	}

	void InitStageForcusCameraAssetsFromPlayerInfo(
		APolarisBattlePlayerStart* PlayerStartActor,
		FPlayerStartInformation PlayerStartInfo) {

		for(auto ForcusCameraAsset : PlayerStartInfo.StageForcusCameraAssets) {
			auto& [BattleRound, Camera1P, Camera2P] = ForcusCameraAsset;
			ULevelSequence* Camera1LoadedSequence = UAssetsGateway::TryLoadAsset<ULevelSequence>(Camera1P);
			ULevelSequence* Camera2LoadedSequence = UAssetsGateway::TryLoadAsset<ULevelSequence>(Camera2P);

			FPolarisStageForcusCamera PolarisStageForcusCamera{};
			PolarisStageForcusCamera.BattleRound = BattleRound;
			PolarisStageForcusCamera.Camera1P = Camera1LoadedSequence;
			PolarisStageForcusCamera.Camera2P = Camera2LoadedSequence;
			if(Camera1LoadedSequence || Camera2LoadedSequence)
				PlayerStartActor->StageForcusCameraAssets.Add(PolarisStageForcusCamera);
		}
	}

	void SpawnFloors(const FGameplayActors& GameplayActors) {
		for(auto Floor : GameplayActors.Floors) {
			SpawnFloor(Floor);
		}
	}

	void SpawnFloor(FFloorInformation FloorInformation) {
		UClass* FloorClass = UAssetsGateway::TryLoadClass<APolarisStageFloorActor>(FloorInformation.SoftClassPath);
		APolarisStageFloorActor* FloorActor = UWorldGateway::TrySpawnActor<APolarisStageFloorActor>(GetWorld(), FloorClass);

		FloorActor->SetActorLabel(FloorInformation.ActorName);
		FloorActor->SetActorLocation(FloorInformation.Position);
		FloorActor->SetActorRotation(FloorInformation.Rotation);
		FloorActor->SetActorScale3D(FloorInformation.Scale);

		FloorActor->IsFloorBreakable = FloorInformation.IsFloorBreakable;
		FloorActor->IsStageDestruction = FloorInformation.IsStageDestruction;
		FloorActor->IsDummyBreak = FloorInformation.IsDummyBreak;
		FloorActor->IsFloorBlast = FloorInformation.IsFloorBlast;

		FloorActor->State = FloorInformation.State;
		FloorActor->SetNo = FloorInformation.SetNo;
		FloorActor->FloorNo = FloorInformation.FloorNo;
		FloorActor->RelatedStageSequenceId = FloorInformation.RelatedStageSequenceId;
		FloorActor->IsNextStageSequence = FloorInformation.IsNextStageSequence;
		FloorActor->TKCollisionEnable = FloorInformation.TKCollisionEnable;
		FloorActor->WallDamageId = FloorInformation.WallDamageId;
		FloorActor->TotalDamage = FloorInformation.TotalDamage;
		FloorActor->IsDurable = FloorInformation.IsDurable;
		FloorActor->DestructLevel = FloorInformation.DestructLevel;
	}

	void SpawnWalls(const FGameplayActors& GameplayActors) {
		for(auto Wall : GameplayActors.Walls) {
			SpawnWall(Wall);
		}
	}

	void SpawnWall(FWallInformation WallInformation) {
		UClass* WallClass = UAssetsGateway::TryLoadClass<APolarisStageWallActor>(WallInformation.SoftClassPath);
		APolarisStageWallActor* WallActor = UWorldGateway::TrySpawnActor<APolarisStageWallActor>(GetWorld(), WallClass);

		WallActor->SetActorLabel(WallInformation.ActorName);
		WallActor->SetActorLocation(WallInformation.Position);
		WallActor->SetActorRotation(WallInformation.Rotation);
		WallActor->SetActorScale3D(WallInformation.Scale);

		WallActor->WallAttribute = WallInformation.WallAttribute;
		WallActor->IsNoBreak = WallInformation.IsNoBreak;

		WallActor->State = WallInformation.State;
		WallActor->SetNo = WallInformation.SetNo;
		WallActor->FloorNo = WallInformation.FloorNo;
		WallActor->RelatedStageSequenceId = WallInformation.RelatedStageSequenceId;
		WallActor->IsNextStageSequence = WallInformation.IsNextStageSequence;
		WallActor->TKCollisionEnable = WallInformation.TKCollisionEnable;
		WallActor->WallDamageId = WallInformation.WallDamageId;
		WallActor->TotalDamage = WallInformation.TotalDamage;
		WallActor->IsDurable = WallInformation.IsDurable;
		WallActor->DestructLevel = WallInformation.DestructLevel;
	}

	FGameplayActors DeserializeGameplayActorsFromJsonString() {
		FGameplayActors GameplayActors{};
		FString FileText = UFileGateway::ReadFile(GameplayActorsPath->GetText().ToString());
		bool Success = FJsonObjectConverter::JsonObjectStringToUStruct(FileText, &GameplayActors);
		if(!Success) {
			UE_LOG(LogTemp, Warning, TEXT("Couldn't serialize FGameplayActors from json string. Json string is probably incorrect."));
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Serialized FGameplayActors successfully."));
		}

		return GameplayActors;
	}
};
