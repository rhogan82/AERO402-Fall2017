// Fill out your copyright notice in the Description page of Project Settings.

#include "Robonaut.h"
#include <math.h>

// Sets default values
ARobonaut::ARobonaut()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARobonaut::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARobonaut::ROB_Pathing()// Find distance to goal
{

	//Hard Code Object Locations since Object Detection Does not work
	//Object 1:
	ObjectLocation[0][0] = 10;
	ObjectLocation[0][1] = 10;
	ObjectLocation[0][2] = 0;
	//Object 2:
	ObjectLocation[1][0] = 4;
	ObjectLocation[1][1] = 5;
	ObjectLocation[1][2] = 0;
	//Object 3:
	ObjectLocation[2][0] = 10;
	ObjectLocation[2][1] = 10;
	ObjectLocation[2][2] = 0;	
	//Object 4:
	ObjectLocation[3][0] = 10;
	ObjectLocation[3][1] = 10;
	ObjectLocation[3][2] = 0;
	//Object 5:
	ObjectLocation[4][0] = 10;
	ObjectLocation[4][1] = 10;
	ObjectLocation[4][2] = 0;
	//Object 6:
	ObjectLocation[5][0] = 10;
	ObjectLocation[5][1] = 10;
	ObjectLocation[5][2] = 0;
	//Object 7:
	ObjectLocation[6][0] = 10;
	ObjectLocation[6][1] = 10;
	ObjectLocation[6][2] = 0;
	//Object 8:
	ObjectLocation[7][0] = 10;
	ObjectLocation[7][1] = 10;
	ObjectLocation[7][2] = 0;
	//Object 9:
	ObjectLocation[8][0] = 10;
	ObjectLocation[8][1] = 10;
	ObjectLocation[8][2] = 0;
	//Object 10:
	ObjectLocation[9][0] = 10;
	ObjectLocation[9][1] = 10;
	ObjectLocation[9][2] = 0;

	//Hard Code End Goal

	ROBGoal[0] = 15;
	ROBGoal[1] = 15;
	ROBGoal[2] = 0;

	double p_goal[3];
	p_goal[0] = ROBGoal[0] - ROBLocation[0];
	p_goal[1] = ROBGoal[1] - ROBLocation[1];
	p_goal[2] = ROBGoal[2] - ROBLocation[2];

	double d_goal = sqrt(pow(p_goal[2], 2.) + pow(p_goal[3], 2.) + pow(p_goal[4], 2.));
	// Calculate attractive potential
	
	double p_a = 1 / 2.0*zeta*pow(d_goal, 2.0);
	// Calculate attractive gradient
	double p_a_gradient[3];
	p_a_gradient[0] = zeta*(-p_goal[0]);
	p_a_gradient[1] = zeta*(-p_goal[1]);
	p_a_gradient[2] = zeta*(-p_goal[2]);

	double PV[3][10]; // hard code in number of objects
	double ObjectLocation[3][10];
	double Distance[10];
	double p_r_gradient[3][10];
	for (int q = 1; q <= 10; q++)
	{
		// Find position vector.

		PV[0][q] = ObjectLocation[0][q] - ROBLocation[0];
		PV[1][q] = ObjectLocation[1][q] - ROBLocation[1];
		PV[2][q] = ObjectLocation[2][q] - ROBLocation[2];
		// Find distance for each object

		Distance[q] = sqrt(pow(PV[0][q], 2.) + pow(PV[1][q], 2.) + pow(PV[2][q], 2.));
		// Calculate repulsive gradient
		if (Distance[q] <= Q_Star)
		{



			p_r_gradient[0][q] = eta*(1.0 / Q_Star - 1.0 / Distance[q])*1.0 / pow(Distance[q], 2.0)*PV[0][q];
			p_r_gradient[1][q] = eta*(1.0 / Q_Star - 1.0 / Distance[q])*1.0 / pow(Distance[q], 2.0)*PV[1][q];
			p_r_gradient[2][q] = eta*(1.0 / Q_Star - 1.0 / Distance[q])*1.0 / pow(Distance[q], 2.0)*PV[2][q];
		}
	}

	//Calculate new direction vector (velocity is change in distance/1 sec -> change in distance
	double TotalP_r_gradient[3];
	for (int q = 1; q <= 10; q++)
	{
		TotalP_r_gradient[0] = TotalP_r_gradient[0] + p_r_gradient[0][q];
		TotalP_r_gradient[1] = TotalP_r_gradient[1] + p_r_gradient[1][q];
		TotalP_r_gradient[2] = TotalP_r_gradient[2] + p_r_gradient[2][q];
	}

	// Add repulive and attractive -> direction vector
	double velvect[3];
	velvect[0] = TotalP_r_gradient[0] + p_a_gradient[0];
	velvect[1] = TotalP_r_gradient[1] + p_a_gradient[1];
	velvect[2] = TotalP_r_gradient[2] + p_a_gradient[2];
	// Normalize the velocity vector so that the robot can only move in the direction by up to its max speed.
	// = Velocity Vector/mag(velocityvector) * vmax 
	//float ROB_velocity[5];
	ROBvelocity[0] = -(velvect[0] / sqrt(pow(velvect[0], 2.0) + pow(velvect[1], 2.0) + pow(velvect[2], 2.0))*vmax);
	ROBvelocity[1] = -(velvect[1] / sqrt(pow(velvect[0], 2.0) + pow(velvect[1], 2.0) + pow(velvect[2], 2.0))*vmax);
	ROBvelocity[2] = -(velvect[2] / sqrt(pow(velvect[0], 2.0) + pow(velvect[1], 2.0) + pow(velvect[2], 2.0))*vmax);


}
// Called every frame
void ARobonaut::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector ROBLocation = GetActorLocation();
	
	ROB_Pathing();

	ROBLocation[0] += ROBvelocity[0];
	ROBLocation[1] += ROBvelocity[1];
	ROBLocation[2] += ROBvelocity[2];
}

