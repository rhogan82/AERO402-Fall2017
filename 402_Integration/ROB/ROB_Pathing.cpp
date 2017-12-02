// Fill out your copyright notice in the Description page of Project Settings.

#include "ROB_Pathing.h"
#include <math.h>
#pragma once


ROB_Pathing::ROB_Pathing()
{
}

ROB_Pathing::~ROB_Pathing()
{
}

float ROB_Pathing::Pathing(ObjectLocation[5][10], RobLocation[5], RobGoal[5])
{ 
	



	// Find distance to goal
	float p_goal[3];
	p_goal[0] = RobGoal[2] - RobLocation[2];
	p_goal[1] = RobGoal[3] - RobLocation[3];
	p_goal[2] = RobGoal[4] - RobLocation[4];

	float d_goal = sqrt(pow(p_goal[2], 2.) + pow(p_goal[3], 2.) + pow(p_goal[4], 2.));
	// Calculate attractive potential
	float zeta = 2.0; //Weight factor
	float p_a = 1/2.0*zeta*pow(d_goal,2.0);
	// Calculate attractive gradient
	float p_a_gradient[3];
	p_a_gradient[0] = zeta*(-p_goal[0]);
	p_a_gradient[1] = zeta*(-p_goal[1]);
	p_a_gradient[2] = zeta*(-p_goal[2]);
	
	float PV[3][10]; // hard code in number of objects
	float ObjectLocation[3][10];
	float Distance[10];
	float p_r_gradient[3][10];
	for (int q = 1; q <= 10; q++)
	{
		// Find position vector.
		
		PV[0][q]= ObjectLocation[0][q] - RobLocation[0];
		PV[1][q] = ObjectLocation[1][q] - RobLocation[1];
		PV[2][q] = ObjectLocation[1][q] - RobLocation[2];
		// Find distance for each object
		
		Distance[q] = sqrt(pow(PV[0][q], 2.) + pow(PV[1][q], 2.) + pow(PV[2][q], 2.));
		// Calculate repulsive gradient
		if (Distance[q] <= Q_Star)
		{
			float eta = 1.0; //weight for objects

			
			p_r_gradient[0][q] = eta*(1.0 / Q_Star - 1.0 / Distance[q])*1.0 / pow(Distance[q], 2.0)*PV[0][q];
			p_r_gradient[1][q] = eta*(1.0 / Q_Star - 1.0 / Distance[q])*1.0 / pow(Distance[q], 2.0)*PV[1][q];
			p_r_gradient[2][q] = eta*(1.0 / Q_Star - 1.0 / Distance[q])*1.0 / pow(Distance[q], 2.0)*PV[2][q];
		}
	}

	//Calculate new direction vector (velocity is change in distance/1 sec -> change in distance
	float TotalP_r_gradient[3];
		for (int q = 1; q <= 10; q++)
		{
			int j = q;
			TotalP_r_gradient[0] = TotalP_r_gradient + p_r_gradient[0][j];
			TotalP_r_gradient[1] = TotalP_r_gradient + p_r_gradient[1][j];
			TotalP_r_gradient[2] = TotalP_r_gradient + p_r_gradient[2][j];
		}

	// Add repulive and attractive -> direction vector
	float velvect[3];
	velvect[0] = TotalP_r_gradient[0] + p_a_gradient[0];
	velvect[1] = TotalP_r_gradient[1] + p_a_gradient[1];
	velvect[2] = TotalP_r_gradient[2] + p_a_gradient[2];
	// Normalize the velocity vector so that the robot can only move in the direction by up to its max speed.
	// = Velocity Vector/mag(velocityvector) * vmax 
	float velocity[5];
	velocity[0] = 'i';
	velocity[1] = 'm/s';
	velocity[2] = velvect[0]/sqrt(pow(velvect[0], 2.0) + pow(velvect[1], 2.0) + pow(velvect[2], 2.0))*vmax;
	velocity[3] = velvect[1]/sqrt(pow(velvect[0], 2.0) + pow(velvect[1], 2.0) + pow(velvect[2], 2.0))*vmax;
	velocity[4] = velvect[2] / sqrt(pow(velvect[0], 2.0) + pow(velvect[1], 2.0) + pow(velvect[2], 2.0))*vmax;		
}