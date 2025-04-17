// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EPolarisGenericItemEvent.h"
#include "Engine/DataAsset.h"
#include "Animation/AnimSequence.h"
#include "GenericItemEventDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FGenericItemEventAnimationInfoStruct
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
	int32 REV;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
	EPolarisGenericItemEvent EventType;                                         

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
	TMap<FName, UAnimSequence*> AnimationMap; 
};

/**
 * 
 */
UCLASS()
class POLARIS_API UGenericItemEventDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
	TArray<struct FGenericItemEventAnimationInfoStruct> EventDatas;
};
