// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerBase.h"


// Sets default values
APlayerBase::APlayerBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<UBlueprint> BPBomb(TEXT("Blueprint'/Game/BombermanBP/Blueprints/BP_Bomb.BP_Bomb'"));
	NormalBombClass = BPBomb.Object->GeneratedClass;
	ConstructorHelpers::FObjectFinder<UBlueprint> BPRemoteBomb(TEXT("Blueprint'/Game/BombermanBP/Blueprints/BP_RemoteBomb.BP_RemoteBomb'"));
	RemoteBombClass = BPRemoteBomb.Object->GeneratedClass;
}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
	BombCount = 1;
	BombRange = 1;
	RemoteBomb = nullptr;
}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerBase::BombExplodedHandler()
{
	BombCount++;
	if (RemoteBomb)
	{
		RemoteBomb = nullptr;
	}
}

void APlayerBase::IncrementBombCount()
{
	BombCount++;
}

void APlayerBase::IncrementBombRange()
{
	BombRange++;
}

void APlayerBase::SetRemoteDetonatorActive(bool Active)
{
	RemoteDetonatorActive = Active;
}


void APlayerBase::SpawnBomb()
{
	if (BombCount > 0 && !RemoteBomb)
	{
		FVector Location = GetActorLocation() + GetActorForwardVector()*80.0f;
		FRotator Rotate = FRotator();
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		SpawnInfo.Instigator = this;
		ABombBase* SpawnedBomb;
		if (RemoteDetonatorActive)
		{
			SpawnedBomb = GetWorld()->SpawnActor<ABombBase>(RemoteBombClass, Location, Rotate, SpawnInfo);
			RemoteBomb = SpawnedBomb;
		}
		else
		{
			SpawnedBomb = GetWorld()->SpawnActor<ABombBase>(NormalBombClass, Location, Rotate, SpawnInfo);
		}
		SpawnedBomb->SetBombRange(BombRange);
		SpawnedBomb->OnExploded().AddUObject(this, &APlayerBase::BombExplodedHandler);
		BombCount--;
	}
	else if (RemoteBomb)
	{
		RemoteBomb->Explode();
	}
}

