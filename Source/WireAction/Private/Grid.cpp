// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid.h"

// Sets default values
AGrid::AGrid() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bHasRing = true;
	Ring = nullptr;

	RingBaseLocalLocation = FVector(0.f, 0.f, 1000.f);
	VerticalRandomRange = 200.f;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RingSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("RingSpawnPoint"));
	RingSpawnPoint->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AGrid::BeginPlay() {
	Super::BeginPlay();

}

// Called every frame
void AGrid::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

bool AGrid::HasActiveRing() const {
	return Ring != nullptr;
}

FTransform AGrid::GetRingSpawnTransform() const {
	FTransform SpawnTransform = RingSpawnPoint->GetComponentTransform();

	FVector SpawnLocation = SpawnTransform.GetLocation() + RingBaseLocalLocation;
	SpawnLocation.Z += FMath::FRandRange(-VerticalRandomRange, VerticalRandomRange);

	SpawnTransform.SetLocation(SpawnLocation);
	return SpawnTransform;
}

void AGrid::NotifyRingDestroyed() {
	Ring = nullptr;

	if (Cluster) {
		Cluster->OnRingDestroyed();
	}
}

