// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BombermanBFL.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API UBombermanBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	
	/** Formats time in seconds from integer to MM:SS string format */
	UFUNCTION(BlueprintCallable, Category = "StringHelpers")
	static FString FormatAsTime(int timeSeconds);
	
};

