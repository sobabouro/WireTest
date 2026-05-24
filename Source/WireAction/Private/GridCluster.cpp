// Fill out your copyright notice in the Description page of Project Settings.


#include "GridCluster.h"

// Sets default values
AGridCluster::AGridCluster() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	MaxRings = 10;
	CurrentRingCount = 0;
}

// Called when the game starts or when spawned
void AGridCluster::BeginPlay() {
	Super::BeginPlay();

	for (AGrid* grid : Grids) {
		if (grid) {
			grid->SetCluster(this);
		}
	}
}

// Called every frame
void AGridCluster::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

bool AGridCluster::TrySpawnRing(TSubclassOf<AScoringRing> InRing) {
	return false;
}

void AGridCluster::OnRingDestroyed() {}

