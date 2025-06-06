#pragma once
#include "CoreMinimal.h"
#include "CollisionLimitDataBase.h"
#include "CapsuleLimitData.generated.h"

USTRUCT(BlueprintType)
struct FCapsuleLimitData : public FCollisionLimitDataBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Length;
    
    KAWAIIPHYSICS_API FCapsuleLimitData();
};

