// Fill out your copyright notice in the Description page of Project Settings.

#include "BombBase.h"

// Sets default values
ABombBase::ABombBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ConstructorHelpers::FObjectFinder<UParticleSystem> BombExplosion(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	ExplosionParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("BombExplosion"));

	if (BombExplosion.Succeeded()) {
		ExplosionParticleSystem->Template = BombExplosion.Object;
	}
	ExplosionParticleSystem->bAutoActivate = false;
	ExplosionParticleSystem->SetHiddenInGame(false);
}

USceneComponent* ABombBase::GetStaticMeshComponent()
{
	return Cast<USceneComponent>(FindComponentByClass(UStaticMeshComponent::StaticClass()));
}

// Called when the game starts or when spawned
void ABombBase::BeginPlay()
{
	Super::BeginPlay();
}

void ABombBase::SetBombRange(int NewRange)
{
	BombRange = NewRange;
}

void ABombBase::Explode_Implementation()
{
	ExplosionParticleSystem->ActivateSystem();
	GetStaticMeshComponent()->SetVisibility(false);
	SetActorEnableCollision(false);
	ExplodedEvent.Broadcast();

	FName ExplosionTrace(TEXT("ExplosionTrace"));
	FCollisionQueryParams ExplosionTraceParams = FCollisionQueryParams(ExplosionTrace, false, this);
	GetWorld()->DebugDrawTraceTag = ExplosionTrace;

	TArray<FHitResult> Hits;
	FVector DirVectors[] = { /*Up*/ FVector(1.0f, 0.0f, 0.0f), /*Down*/ FVector(-1.0f, 0.0f, 0.0f), /*Left*/ FVector(0.0f, -1.0f, 0.0f), /*Right*/ FVector(0.0f, 1.0f, 0.0f) };

	for (FVector DirVector : DirVectors)
	{
		//call GetWorld() from within an actor extending class
		GetWorld()->LineTraceMultiByChannel(
			Hits,				   //results
			GetActorLocation(),    //start
			GetActorLocation() + DirVector*BombRange*200.0f, //end
			ECC_GameTraceChannel1, //collision channel
			ExplosionTraceParams
		);

		for (FHitResult hit : Hits)
		{
			AActor* hitActor = hit.GetActor();
			if (hitActor->IsValidLowLevel())
			{
				hit.GetActor()->TakeDamage(1.0f, FDamageEvent(), nullptr, this);
			}
		}
	}
	if (ExplosionParticleSystem->IsValidLowLevel())
	{
		ExplosionParticleSystem->OnSystemFinished.AddDynamic(this, &ABombBase::OnFinished);
	}
}

void ABombBase::OnFinished(UParticleSystemComponent* PSystem)
{
	Destroy();
}
