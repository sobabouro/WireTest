// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grid.generated.h"

UCLASS()
class AGrid : public AActor {
	GENERATED_BODY()

public:
	// リングの有無
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Setting")
	bool bHasRing;

	// リングの基準生成位置
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Setting")
	FVector RingBaseLocation;
	// z軸のランダム範囲
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Setting")
	float VerticalRandomRange;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	AGrid();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
