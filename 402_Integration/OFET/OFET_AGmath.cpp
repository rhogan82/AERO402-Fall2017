/*************************************************************************
**********************(COPYRIGHT INFORMATION)*****************************
**************************************************************************/

/*************************************************************************
PURPOSE:
Cpp file. Math model for AG system. Inputs are desired gforce, radius of AG, and number of crew in AG. Outputs power requirement to run and start, and angular velocity (thetadot) of AG.
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

#include "OFET_AGmath.h"
#include "cmath"

OFET_AGmath::OFET_AGmath()
{
}

OFET_AGmath::~OFET_AGmath()
{
}

double OFET_AGmath::RPM(double g, double r) {
	double RPM = sqrt(g*r) / r / 2 / 3.14125 * 60;
	return RPM;
}

double OFET_AGmath::Frictiontorque(double g, double r, double crew) {
	double Frictiontorque = g*(5000 + 75 * crew)*0.005*(r / 2);
	return Frictiontorque;
}

double OFET_AGmath::RunPower(double Frictiontorque, double RPM) {
	double RunPower = Frictiontorque * RPM / 1000;
	return RunPower;
}

double OFET_AGmath::thetadot(double RPM) {
	double thetadot = RPM * 2 * 3.14159 / 60;
	return thetadot;
}
