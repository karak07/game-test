// Fill out your copyright notice in the Description page of Project Settings.

#include "BombermanGameModeBase.h"




void ABombermanGameModeBase::GenerateMap(UClass* BreakableWallClass, float SpawnChance)
{
	FVector Location = FVector(1070.0f, -1775.0f, 280.0f);
	FRotator Rotate = FRotator(0.0f,0.0f,0.0f);
	FActorSpawnParameters SpawnInfo;
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if ((j < 2 && i < 2) || (j > 16 && i > 10))
			{
				continue;
			}
			if (FMath::RandRange(0.0f, 1.0f) <= SpawnChance)
			{
				GetWorld()->SpawnActor<AActor>(BreakableWallClass, Location + FVector(-200.0f*i, 200.0f*j, 0.0f), Rotate, SpawnInfo);
			}
			if (i % 2 == 0) 
			{
				j++; 
			}
		}
	}
}
