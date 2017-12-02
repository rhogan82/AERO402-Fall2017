// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Robonaut.generated.h"
#include <math.h>
UCLASS()
class ROBONAUTTEST_API ARobonaut : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARobonaut();

	double ObjectLocation[3][10];	/* i m	position (X,Y,Z coordinates)*/
	double ROBLocation[3];			/*i m	X,Y,Z coordinates*/
	double ROBGoal[3];				/*i m	X,Y,Z coordinates*/
	double ROBvelocity[3];				/*o m/s The change in robots position per second in X,Y,Z*/
	void ROB_Pathing();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:

	double vmax = 1.0; //set maximum velocity for robot
	double Q_Star = 5.0; //Set distance at which objects start "affecting" robot path
	double eta = 1.0; //weight for objects
	double zeta = 2.0; //Weight factor for goal
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float RunningTime;
	
	
};
