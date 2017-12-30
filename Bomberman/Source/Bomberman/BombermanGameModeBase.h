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
	
	

	/** Fills 19x13 area with destructible walls depending on SpawnChance*/
	UFUNCTION(BlueprintCallable, Category = "Level")
	void GenerateMap(UClass* BreakableWallClass, float SpawnChance);
	
};
