/*************************************************************************
**********************(COPYRIGHT INFORMATION)*****************************
**************************************************************************/

/*************************************************************************
PURPOSE:
	(This class is used to simulate the physics of an object undergoing 
	 one dimensional motion with a constant force, g.)
LANGUAGE:
	(C++)
LIBRARY DEPENDENCIES:
	(
	 ()
	)
REFERENCES:
	(
	 (None.)
	)
ASSUMPTIONS AND LIMITATIONS:
	(
	 (Constant acceleration and no drag. One dimensional motion is simulated
	  in this class.)
	)
PROGRAMMERS:
	(
	 ((Robert Hogan) (AERO 402) (11/14/2017) (Initial implementation))
	)
**************************************************************************/


#include "stdafx.h"
#include "TAS_StateOfObject.h"


TAS_StateOfObject::TAS_StateOfObject(double position, double velocity)
{
	pos0 = position;
	vel0 = velocity;
	pos = pos0;
	vel = vel0;
}


TAS_StateOfObject::~TAS_StateOfObject()
{
}


void TAS_StateOfObject::Update_State(double timespan, double g) {
	pos = pos + vel*timespan + 1/2*g*timespan*timespan;
	vel = vel + g*timespan;
}