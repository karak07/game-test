// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Bombs/BombBase.h"
#include "PlayerBase.generated.h"

UCLASS()
class BOMBERMAN_API APlayerBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void SpawnBomb();

private:

	UFUNCTION()
	void BombExplodedHandler();

	UFUNCTION(BlueprintCallable)
	void IncrementBombCount();

	UFUNCTION(BlueprintCallable)
	void IncrementBombRange();

	UFUNCTION(BlueprintCallable)
	void SetRemoteDetonatorActive(bool Active);

	UClass* NormalBombClass;
	UClass* RemoteBombClass;
	int BombCount;
	int BombRange;
	bool RemoteDetonatorActive;
	ABombBase* RemoteBomb;

};
