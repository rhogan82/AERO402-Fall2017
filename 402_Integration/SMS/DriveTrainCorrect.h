/*************************************************************************
***************************************************
***********************************************************************/

/***********************************************************************
PURPOSE:
	(
	The purpose of this class is to calculate the dimensions of the drive train.
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

/*Include this in all header files*/
#pragma once

/*includes necessary for the header file. Minimize these if possible*/
#include <cmath>

/*You can define variables this way if you need to, only in the scope of
the class*/
#define PI = 3.14159

/*Forward declarations of classes used by header*/
class SMS_CallDriveTrainSize;

class SMS_DriveTrainSize {
public:
	SMS_DriveTrainSize();  //constructor
	~SMS_DriveTrainSize(); //destructor
	
	double Radius, ThicknessWheels, WidthWheels, Motors, Floor;
	
	void Mass_Suspension(double, double, double, double, double);
	
	double Volume_Wheels()
	{
		double Volume = ((PI*Radius^2) - (PI * (Radius - ThicknessWheels)^2)) * WidthWheels;
		return Volume;
	}
	
	double Mass_Wheels()
	{
		double Mass = Motors * 2 * VolumeWheels() * Density_Wheel();
		return Mass;
	}

	SMS_CallDriveTrainSize* SMS_DriveTrainSize = nullptr; //pointer to class calling this class


private:
	static double Density_Floor()
	{
		return 4500; /* kg/m^3 density of titanium */
	}
	
	static double Density_Wheel()
	{
		return 2700; /* kg/m^3 density of aluminum */
	}
};			

