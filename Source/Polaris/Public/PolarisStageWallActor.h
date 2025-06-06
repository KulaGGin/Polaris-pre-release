#pragma once
#include "CoreMinimal.h"
#include "PolarisStageGroundActor.h"
#include "PolarisStageWallActor.generated.h"

UCLASS()
class POLARIS_API APolarisStageWallActor : public APolarisStageGroundActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Polaris|StageWall")
    int32 WallAttribute;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Polaris|StageWall")
    bool IsNoBreak;
    
    APolarisStageWallActor(const FObjectInitializer& ObjectInitializer);

};

