// Fill out your copyright notice in the Description page of Project Settings.

#include "Robonaut.h"


// Sets default values
ARobonaut::ARobonaut()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	num = 1;

	//Object 1:
	ObjectLocation[0][0] = 800.0;
	ObjectLocation[0][1] = -40400;
	ObjectLocation[0][2] = -59500;
	/*
	//Object 2:
	ObjectLocation[1][0] = 800;
	ObjectLocation[1][1] = -40500;
	ObjectLocation[1][2] = -59500;
	//Object 3:
	ObjectLocation[2][0] = 700;
	ObjectLocation[2][1] = -40500;
	ObjectLocation[2][2] = -5950;
	
	//Object 4:
	ObjectLocation[3][0] = 700;
	ObjectLocation[3][1] = -40500;
	ObjectLocation[3][2] = -5950;
	//Object 5:
	ObjectLocation[4][0] = 700;
	ObjectLocation[4][1] = -40500;
	ObjectLocation[4][2] = -5950;
	//Object 6:
	ObjectLocation[5][0] = 700;
	ObjectLocation[5][1] = -40500;
	ObjectLocation[5][2] = -5950;
	//Object 7:
	ObjectLocation[6][0] = 700;
	ObjectLocation[6][1] = -40500;
	ObjectLocation[6][2] = -5950;
	//Object 8:
	ObjectLocation[7][0] = 700;
	ObjectLocation[7][1] = -40500;
	ObjectLocation[7][2] = -59500;
	//Object 9:
	ObjectLocation[8][0] = 700;
	ObjectLocation[8][1] = -40500;
	ObjectLocation[8][2] = -5950;
	//Object 10:
	ObjectLocation[9][0] = 700;
	ObjectLocation[9][1] = -40500;
	ObjectLocation[9][2] = -5950;
	UE_LOG(LogTemp, Warning, TEXT("ObjectLocation[0][0] %f"),ObjectLocation[0][0])
	*/
}

// Called when the game starts or when spawned
void ARobonaut::BeginPlay()
{
	Super::BeginPlay();
	
}

float ARobonaut::ROB_Pathing() // Find distance to goal
{
	
	FVector ROBLocation = GetActorLocation();
	//Hard Code Object Locations since Object Detection Does not work
	

	//Hard Code End Goal

	ROBGoal[0] = 1300;
	ROBGoal[1] = -40500;
	ROBGoal[2] = -5950;

	float p_goal[3];
	p_goal[0] = ROBGoal[0] - ROBLocation[0];
	p_goal[1] = ROBGoal[1] - ROBLocation[1];
	p_goal[2] = ROBGoal[2] - ROBLocation[2];

	float d_goal = sqrt(pow(p_goal[2], 2.) + pow(p_goal[3], 2.) + pow(p_goal[4], 2.));
	// Calculate attractive potential

	float p_a = 1 / 2.0*zeta*pow(d_goal, 2.0);
	// Calculate attractive gradient
	float p_a_gradient[3];
	p_a_gradient[0] = zeta*(-p_goal[0]);
	p_a_gradient[1] = zeta*(-p_goal[1]);
	p_a_gradient[2] = zeta*(-p_goal[2]);



	

	for (int q = 0; q <= num-1; q++)
	{
		// Find position vector.

		PV[q][0] = ObjectLocation[q][0] - ROBLocation[0];
		PV[q][1] = ObjectLocation[q][1] - ROBLocation[1];
		PV[q][2] = ObjectLocation[q][2] - ROBLocation[2];
		// Find distance for each object

		Distance[q] = sqrt(pow(PV[q][0], 2.) + pow(PV[q][1], 2.) + pow(PV[q][2], 2.));
		// Calculate repulsive gradient
		
		if (Distance[q] <= Q_Star)
		{
			a = eta*(1.0 / Q_Star);
			b = eta*(- 1 / Distance[q]);
			p_r_gradient[q][0] = eta*(1.0 / Q_Star - 1.0 / Distance[q])*(1.0 / pow(Distance[q], 2.0))*PV[q][0];
			p_r_gradient[q][1] = eta*(1.0 / Q_Star - 1.0 / Distance[q])*1.0 / pow(Distance[q], 2.0)*PV[q][1];
			p_r_gradient[q][2] = eta*(1.0 / Q_Star - 1.0 / Distance[q])*1.0 / pow(Distance[q], 2.0)*PV[q][2];
		}
	}

	//Calculate new direction vector (velocity is change in distance/1 sec -> change in distance
	float TotalP_r_gradient[3];
	TotalP_r_gradient[0] = 0;
	TotalP_r_gradient[1] = 0;
	TotalP_r_gradient[2] = 0;
	for (int q = 0; q <= num-1; q++)
	{
		TotalP_r_gradient[0] = TotalP_r_gradient[0] + p_r_gradient[q][0];
		TotalP_r_gradient[1] = TotalP_r_gradient[1] + p_r_gradient[q][1];
		TotalP_r_gradient[2] = TotalP_r_gradient[2] + p_r_gradient[q][2];
	}

	// Add repulive and attractive -> direction vector
	float velvect[3];
	velvect[0] = TotalP_r_gradient[0] + p_a_gradient[0];
	velvect[1] = TotalP_r_gradient[1] + p_a_gradient[1];
	velvect[2] = TotalP_r_gradient[2] + p_a_gradient[2];

	// Normalize the velocity vector so that the robot can only move in the direction by up to its max speed.
	// = Velocity Vector/mag(velocityvector) * vmax 


	ROBvelocity[0] = -(velvect[0] / sqrt(pow(velvect[0], 2.0) + pow(velvect[1], 2.0) + pow(velvect[2], 2.0))*vmax);
	ROBvelocity[1] = -(velvect[1] / sqrt(pow(velvect[0], 2.0) + pow(velvect[1], 2.0) + pow(velvect[2], 2.0))*vmax);
	ROBvelocity[2] = -(velvect[2] / sqrt(pow(velvect[0], 2.0) + pow(velvect[1], 2.0) + pow(velvect[2], 2.0))*vmax);
	/*
	ROBvelocity[0] = 1;
	ROBvelocity[1] = 1;
	ROBvelocity[2] = 1;
	*/
	UE_LOG(LogTemp, Warning, TEXT("Distance to Object %f"), Distance[0]);
	//UE_LOG(LogTemp,Warning,TEXT("Repulsive gradient %f %f %f"), p_r_gradient[0][0], p_r_gradient[0][1], p_r_gradient[0][2])
		
	return ROBvelocity[0], ROBvelocity[1], ROBvelocity[2];
	

}

// Called every frame
void ARobonaut::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector ROBLocation = GetActorLocation();
	


	ROBvelocity[0], ROBvelocity[1], ROBvelocity[2] = ROB_Pathing();


	ROBLocation[0] += ROBvelocity[0];
	ROBLocation[1] += ROBvelocity[1];
	ROBLocation[2] += ROBvelocity[2];
	SetActorLocation(ROBLocation);
}

