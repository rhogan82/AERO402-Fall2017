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
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Robonaut.generated.h"

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
	double RunningTime;
	
	
};
