// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridCluster.generated.h"

class AScoringRing;
class AGrid;
class AGridClusterManager;

UCLASS()
class AGridCluster : public AActor {
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	AGridClusterManager* Manager;

	UPROPERTY(VisibleAnywhere)
	int32 CurrentRingCount;

public:
	// グリッド集合内のリングの総数
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GridCluster Setting", meta = (ClampMin = "0", ClampMax = "200", UIMin = "0", UIMax = "200"))
	int32 MaxRings;

	// グリッド集合に属するグリッドの配列
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GridCluster Setting", meta = (ClampMin = "0", ClampMax = "200", UIMin = "0", UIMax = "200"))
	TArray<AGrid*> Grids;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	AGridCluster();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetManager(AGridClusterManager* InManager) { Manager = InManager; }
	int32 GetCurrentRingCount() const { return CurrentRingCount; }

	bool TrySpawnRing(TSubclassOf<AScoringRing> InRing);
	void OnRingDestroyed();
};
