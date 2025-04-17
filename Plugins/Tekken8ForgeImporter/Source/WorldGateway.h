// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WorldGateway.generated.h"

/**
 * 
 */
UCLASS()
class TEKKEN8FORGEIMPORTER_API UWorldGateway : public UObject {
	GENERATED_BODY()
public:
	template<typename Type, typename = typename TEnableIf<TIsDerivedFrom<Type, AActor>::Value>::Type>
	static Type* TrySpawnActor(UWorld* World, UClass* Class) {
		Type* Actor = World->SpawnActor<Type>(Class);
		if(!Actor)
			UE_LOG(LogTemp, Warning, TEXT("Couldn't spawn Actor of class %s"), *Actor->GetName());

		return Actor;
	}
};
