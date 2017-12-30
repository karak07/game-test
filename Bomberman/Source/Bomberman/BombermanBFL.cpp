// Fill out your copyright notice in the Description page of Project Settings.

#include "BombermanBFL.h"


FString UBombermanBFL::FormatAsTime(int timeSeconds)
{
	return FString::Printf(TEXT("%02d:%02d"), timeSeconds / 60, timeSeconds % 60);
}






