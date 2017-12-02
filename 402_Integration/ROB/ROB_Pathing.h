/*************************************************************************
**********************(COPYRIGHT INFORMATION)*****************************
**************************************************************************/

/*************************************************************************
PURPOSE:
This class performs path planning calculations, and then sets the new location for the robot/actor using the algorithim

LANGUAGE:
(C++)
LIBRARY DEPENDENCIES:
(
#include "CoreMinimal.h" // Unreal Library
#include "Robonaut.generated.h" //Actor applied to
#include <math.h>	// for calculations
)
REFERENCES:
(
//References: A potential Field approach to path planning, Hwang and Ahuja
// https://wiki.unrealengine.com/Iterators:_Object_%26_Actor_Iterators,_Optional_Class_Scope_For_Faster_Search
)
ASSUMPTIONS AND LIMITATIONS:
(
Assumption/Limitation 1: The robot always can always sense and locate an object or obstacle. 
For this code, the object detection sub model was unavailable, so the object locations are known and hard coded in.

Assumption 2: Given a new coordinate to move to, the object (robot) can perform all the necessary translations and rotations to move itself to the new l
location.

Assumption 3: The robot receives an end point/goal to travel to, and is able to precisely determine its relative position to that of the end point.

)
PROGRAMMERS:
(
((Nicholas Beal) (Robotics and Teleoperation/Team 9) (12/1) (Removed the Unreal Detection submodel from code, new position is now returned to any actor that calls this math model))
)
**************************************************************************/

// NOTE: Format changes and a couple of bugs are still being worked on.
/*Include this in all header files*/
#pragma once

/*includes necessary for the header file. Minimize these if possible*/
#include <string>
#include <stdio.h>
#include "CoreMinimal.h"
#include "Robonaut.generated.h"
#include <math.h>
/**
 * 
 */
 /*Forward declarations of classes used by header*/

class MYPROJECT2_API ROB_Pathing
{
public:
	ROB_Pathing();
	~ROB_Pathing();

	float ObjectLocation[5][10];	/* i m	X,Y,Z coordinates*/ 
	float ROBLocation[5];			/*i m	X,Y,Z coordinates*/
	float ROBGoal[5];				/*i m	X,Y,Z coordinates*/
	float velocity[5];				/*o m/s The change in robots position per second in X,Y,Z*/

	float Pathing(ObjectLocation, RobLocation, RobGoal);


private:
	float vmax = 1.0; //set maximum velocity for robot

	float Q_Star = 5.0; //Set distance at which objects start "affecting" robot path 
	float p_goal[3]; // vector distance to goal
	float d_goal; // magnitude of distance vector to goal
	float zeta; //Weight factor
	float p_a; //Attractive potential
	float p_a_gradient[3]; //Gradient of attractive potential
	float PV[3][10]; // Position vector to each object
	float Distance[10]; // List of magnitude of distances between each object

	float p_r_gradient[3][10]; //Repulsive gradient vector
	int q; //counter
	float eta = 1.0; //weight for objects
	float TotalP_r_gradient[3]; // The combined total repulsive gradient
	float velvect[3]; //The repulsive and attractive gradients together
	
};
