// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NewActorComponent.generated.h"
class ROB_Power;
class AActor;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT5_API UNewActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNewActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//AActor* GetVelocity();
	//AActor* FVector;
	//AActor* GetVelocity;
	//AActor* F;
	//AActor* ZeroVector;
	ROB_Power* Power_Level;
	//FVector A = { 1,0,0 };
	//FVector B = FVector(0.3);
	double powerlevel;
	double x;
	bool movement;
};
