

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "Button.h"
#include "PolarisStageGroundActor.h"
#include "UObject/NoExportTypes.h"
#include "AssetsGateway.h"
#include "Engine/StaticMeshActor.h"
#include "Kismet/GameplayStatics.h"
#include "SimpleWallSpawner.generated.h"


/**
 * 
 */
UCLASS()
class TEKKEN8FORGEIMPORTER_API USimpleWallSpawner : public UEditorUtilityWidget {
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	UButton* SpawnSimpleWallsButton;

	virtual bool Initialize() override {
		Super::Initialize();

		SpawnSimpleWallsButton->OnClicked.AddUniqueDynamic(this, &USimpleWallSpawner::OnSpawnSimpleWallsButtonClicked);

		return true;
	}

	UFUNCTION()
	void OnSpawnSimpleWallsButtonClicked() {
		UStaticMesh* CubeMesh = UAssetsGateway::TryLoadAsset<UStaticMesh>(TEXT("/Engine/BasicShapes/Cube"));
		TArray<AActor*> AllStageGroundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), APolarisStageGroundActor::StaticClass(), AllStageGroundActors);
		for(AActor* StageGroundActor : AllStageGroundActors) {
			AStaticMeshActor* CubeActor = GetWorld()->SpawnActor<AStaticMeshActor>();
			CubeActor->SetActorLocation(StageGroundActor->GetActorLocation());
			CubeActor->SetActorRotation(StageGroundActor->GetActorRotation());
			CubeActor->SetActorScale3D(StageGroundActor->GetActorScale3D());

			UStaticMeshComponent* StaticMeshComponent = CubeActor->GetStaticMeshComponent();
			StaticMeshComponent->SetStaticMesh(CubeMesh);
		}
	}
};
