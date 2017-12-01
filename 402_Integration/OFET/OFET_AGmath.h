/*************************************************************************
**********************(COPYRIGHT INFORMATION)*****************************
**************************************************************************/

/*************************************************************************
PURPOSE:
.h file. Math model for AG system. Inputs are desired gforce, radius of AG, and number of crew in AG. Outputs power requirement to run and start, and angular velocity (thetadot) of AG.
LANGUAGE:
(C++)
LIBRARY DEPENDENCIES:
(
()
)
ASSUMPTIONS AND LIMITATIONS:
(
Mass of system is found via stress analysis in Matlab model to be 4725 kg.
3.14159 is used for pi.
assumes constant power draw while starting.
)
PROGRAMMERS:
(
((Name) (Company/Team) (Date) (changes))
)
**************************************************************************/

#pragma once

/**
 * 
 */
class OFET_AG_API OFET_AGmath
{
public:
	OFET_AGmath();
	~OFET_AGmath();
	double RPM(double g, double r);
	double Frictiontorque(double g, double r, double crew);
	double RunPower(double Frictiontorque, double RPM);
	double StartPower = 2.55;
	double thetadot(double RPM);
};
