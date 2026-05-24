// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grid.generated.h"

class AScoringRing;
class AGridCluster;

UCLASS()
class AGrid : public AActor {
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	AGridCluster* Cluster;

	UPROPERTY(VisibleAnywhere)
	AScoringRing* Ring;

public:
	// リングの有無
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Setting")
	bool bHasRing;

	// リングの生成原点
	UPROPERTY()
	USceneComponent* RingSpawnPoint;

	// リングの生成位置
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Setting", meta = (ClampMin = "0.0", ClampMax = "10000.0", UIMin = "0.0", UIMax = "10000.0"))
	FVector RingBaseLocalLocation;
	// z軸のランダム範囲
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Setting", meta = (ClampMin = "0.0", ClampMax = "10000.0", UIMin = "0.0", UIMax = "10000.0"))
	float VerticalRandomRange;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	AGrid();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetCluster(AGridCluster* InCluster) { Cluster = InCluster; }

	void SetRing(AScoringRing* InRing) { Ring = InRing; }

	bool HasActiveRing() const;

	FTransform GetRingSpawnTransform() const;

	void NotifyRingDestroyed();
};
