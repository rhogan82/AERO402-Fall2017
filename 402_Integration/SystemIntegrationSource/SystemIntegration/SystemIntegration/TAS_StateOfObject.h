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

#pragma once

class TAS_StateOfObject
{
public:
	TAS_StateOfObject(double position, double velocity);
	~TAS_StateOfObject();

	double pos0;
	double vel0;
	double pos;
	double vel;

	void Update_State(double timespan, double g);
};

