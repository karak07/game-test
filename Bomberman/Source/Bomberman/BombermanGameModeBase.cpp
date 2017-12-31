// Fill out your copyright notice in the Description page of Project Settings.

#include "BombermanGameModeBase.h"




void ABombermanGameModeBase::GenerateMap(UClass* BreakableWallClass, float SpawnChance)
{
	FRotator Rotate = FRotator::ZeroRotator;
	FActorSpawnParameters SpawnInfo;
	for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if ((j < 2 && i < 2) || (j > MapWidth-3 && i > MapHeight-3))
			{
				continue;
			}
			if (FMath::RandRange(0.0f, 1.0f) <= SpawnChance)
			{
				GetWorld()->SpawnActor<AActor>(BreakableWallClass, FirstTileLocation + FVector(-TileSize*i, TileSize*j, 0.0f), Rotate, SpawnInfo);
			}
			if (i % 2 == 0) 
			{
				j++; 
			}
		}
	}
}
