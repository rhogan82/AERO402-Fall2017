/**********************************************************************************************************************************************/

/***********************************************************************
PURPOSE:
	(
	The purpose of this class is to provide the amount of power required to move the pressurized rover.
	)
LANGUAGE:
	(C++)
LIBRARY DEPENDENCIES:
	(
	 ()
	)
REFERENCES:
	(
	 1. 
	)
ASSUMPTIONS AND LIMITATIONS:
	(
	 1. 
	)
PROGRAMMERS:
	(
	 Maura Cadigan, Surface Mobility (Mars Cars, Inc.), mcadig1@tamu.edu
	 Steven De La Cruz, Surface Mobility (Mars Cars, Inc.), stevendelacruz79@tamu.edu
	 Daniel Green, Surface Mobility (Mars Cars, Inc.), danielgreen17@tamu.edu
	 
	 Change Log: 
	 11/5/2017 - Model created. (Steven De La Cruz)
	 11/5/2017 - Conversion of file to correct format. (Maura Cadigan)
	)
***********************************************************************/

#pragma once
#include <cmath>

#define PI = 3.14159

/*Forward declarations of classes used by header*/
class SMS_CallRoverMotionPower;

class SMS_RoverMotionPower {
public:
	SMS_RoverMotionPower();  //constructor
	~SMS_RoverMotionPower(); //destructor
    					  /*Define your public variables here. These can be accessed outside
	 				    of the class and in other functions not defined in this scope*/

	//double time;			/* s Model time */
	double Length, Width, Velocity, Incline, Mass;
	void Motion_Power(double, double, double, double, double);
	
	double Weight_Rover()
	{
		double Weight = Mass * Mars_Gravity();
		return Weight;
	}
	
	double Area_Rover()
	{
		double Area = Length * Width;
		return Area;
	}
	
	double Force_Gravity()
	{
		double Gravity = Weight_Rover() * sin(Incline * PI / 180);
		return Gravity;
	}
	
	double Force_Friction()
	{
		double Friction = Weight_Rover() * Mars_Nu() * cos(Incline * PI / 180);
		return Friction;
	}
	
	double Force_Air()
	{
		double Air = 0.5 * Rho_Mars() * Area_Rover() * pow(Velocity,2);
		return Air;
	}
	
	double Motion_Power()
	{
		double Power = (Force_Gravity() + Force_Friction() + Force_Air()) * Velocity;
	}
	SMS_CallRoverMotionPower* SMS_RoverMotionPower = nullptr; //pointer to class calling this class


private:
	static double Rho_Mars()
	{
		return 0.02;
	}
	
	static double Mars_Gravity()
	{
		return 3.71;
	}
	
	static double Mars_Nu()
	{
		return 0.25;
	}

};			

