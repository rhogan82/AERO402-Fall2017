/**********************************************************************************************************************************************/

/*************************************************************************
PURPOSE:
	The purpose of this class is to give the power required for general user functions abroad the pressurized Mars rover.
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
	 11/5/2017 - Creation of file. (Maura Cadigan)
	)
**************************************************************************/

/*Include this in all header files*/
#pragma once

/*includes necessary for the header file. Minimize these if possible*/
#include <cmath>

/*You can define variables this way if you need to, only in the scope of
the class*/
#define SafetyFactor = 1.25;

/*Forward declarations of classes used by header*/
class SMS_CallRoverUserPower;

class RoverUserPower {
public:
	SMS_RoverUserPower();  //constructor
	~SMS_RoverUserPower(); //destructor
    					  /*Define your public variables here. These can be accessed outside
	 				    of the class and in other functions not defined in this scope*/

	//double pos0[3];			/* *i m   Init position of component */
	//double vel0[3];			/* *i m/s Init velocity of component */

					/* The first column is *i or *o or *io for
					   input/output or both */
					/* The second column is the units */
					/* The third component is the description*/

	//double time;			/* s Model time */

	double Communications_Power
	{
		double XBandPower, NumXBand, KaBandPower, NumKaBand, TotalRoverCommPower;
		XBandPower = 50; //Watts
		KaBandPower = 35; //Watts
		NumXBand = 2; //units
		NumKaBand = 2; //units
		TotalRoverCommPower = SafetyFactor*(XBandPower*NumXBand + KaBandPower*NumKaBand); //Watts
		
		return TotalRoverCommPower; //Watts
	}
	
	double LightsComp_Power
	{
		double SmallLightPower, NumSmallLight, MonitorPower, NumMontior, ComputerPower, NumComputer, LEDPower, NumLED, TotalRoverLightsCompPower;
		SmallLightPower = 2; //Watts
		NumSmallLight = 50; //units
		MonitorPower = 40; //Watts
		NumMonitor = 3; //units
		ComputerPower = 200; //Watts
		NumComputer = 3; //units
		LEDPower = 12; //Watts
		NumLED = 4;  //units
		TotalRoverLightsCompPower = SafetyFactor*(SmallLightPower*NumSmallLight + MonitorPower*NumMonitor + ComputerPower*NumComputer + LEDPower*NumLED); //Watts
		return TotalRoverLightsCompPower; //Watts
	}
	
	double GNC_Power
	{
		double GPSPower, NumGPS, TotalRoverGNCPower;
		GPSPower = 2.5; //Watts
		NumGPS = 2; //units
		TotalRoverGNCPower = SafetyFactor * GPSPower * NumGPS; //Watts
		return TotalRoverGNCPower; //Watts
	}

	SMS_CallRoverUserPower* SMS_RoverUserPower = nullptr; 
	//pointer to class calling this class
	//NOT 100% SURE THIS IS CORRECT


private:
/*Define your private variables here. These can only be accessed from within this class instance*/

};

