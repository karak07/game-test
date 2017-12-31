// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ParticleDefinitions.h"
#include "ParticleHelper.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"

#include "BombBase.generated.h"


UCLASS()
class BOMBERMAN_API ABombBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABombBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Explode();

	/** Broadcasts whenever the bomb explodes */
	DECLARE_EVENT(ABombBase, FExplodedEvent)
	FExplodedEvent& OnExploded() { return ExplodedEvent; }

	UFUNCTION()
	void SetBombRange(int NewRange);

private:
	/** Broadcasts whenever the bomb explodes */
	FExplodedEvent ExplodedEvent;

	UFUNCTION()
	void OnFinished(UParticleSystemComponent* PSystem);

	//Helper to get static mesh component defined in Editor
	USceneComponent* GetStaticMeshComponent();

	UParticleSystemComponent* ExplosionParticleSystem;

	int BombRange;
};
