// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Engine/World.h"
#include "BombermanGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API ABombermanGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 MapWidth = 19;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 MapHeight = 13;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FVector FirstTileLocation = FVector(1070.0f, -1775.0f, 280.0f);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 TileSize = 200;

	/** Fills map area with destructible walls depending on SpawnChance*/
	UFUNCTION(BlueprintCallable, Category = "Level")
	void GenerateMap(UClass* BreakableWallClass, float SpawnChance);


	
};
