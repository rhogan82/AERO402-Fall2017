/***********************************************************************
***********************************************************************/

/***********************************************************************
PURPOSE:
	The purpose of this class is to model the power necessary to run the life support systems as well as the amount of consumables used by life support systems for the pressurized rover. It will also provide the mass of the life support system.
LANGUAGE:
	(C++)
LIBRARY DEPENDENCIES:
	(
	 ()
	)
REFERENCES:
	(
	 1. Air Filter Info (http://industrial.airocide.com/assets/images/Airocide-Literature_edit.pdf)
	 2. Temperature and Humidity Control Info (http://salotti.pagesperso-orange.fr/lifesupport3.pdf)
	 3. Carbon Dioxide Scrubber Info (https://ntrs.nasa.gov/archive/nasa/casi.ntrs.nasa.gov/20000072884.pdf)
	 4. Spacecraft Atmospher Monitor (SAM) Info (http://www.hems-workshop.org/10thWS/Talks/Kidd.pdf)
	 )
ASSUMPTIONS AND LIMITATIONS:
	(
	 1. As of 11/5/2017, life systems are modeled as if they will be running at full power for the duration of the mission, as they will in nonemergency situations. In future versions, models will change to accomodate power saving measures necessary in emergency situations.
	 2. 
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
#define SafetyFactory = 1.25

/*Forward declarations of classes used by header*/
class SMS_CallRoverLifeSupport;
/*SMS = Surface Mobility Systems*/

class SMS_RoverLifeSupport { /*Use capital letters for beginning of words,
								  no undersores (_)*/
public:
	SMS_RoverLifeSupport();  //constructor
	~SMS_RoverLifeSupport(); //destructor
    					  /*Define your public variables here. These can be accessed outside
	 				    of the class and in other functions not defined in this scope*/
	//Everything below in comments, I am unsure if we need. It will be kept in comments until a decision is made.
	/* double pos0[3]; */			/* *i m   Init position of component */
	/* double vel0[3];			 *//* *i m/s Init velocity of component */

					/* The first column is *i or *o or *io for
					   input/output or both */
					/* The second column is the units */
					/* The third component is the description*/

	/* double time; */			/* s Model time */
	double Oxygen_Rover_Req(double NumMale, double NumFemale, double TripDuration, double ActivityLevel)
	{
		double MaleOxygenRequired, FemaleOxygenRequired, TotalLSOxygenRoverReq;
		
		if (ActivityLevel == 1)
		{
			double SedentaryMaleOxygen = 0.9517 / 86400 * TripDuration; //kg
			double SedentaryFemaleOxygen = 0.6069 / 86400 * TripDuration; //kg
			MaleOxygenRequired = NumMale*SedentaryMaleOxygen; //kg
			FemaleOxygenRequired = NumFemale*SedentaryFemaleOxygen; //kg
		}
		else if (ActivityLevel == 2)
		{
			double ModerateActiveMaleOxygen = 2.9741 / 86400 * TripDuration; //kg
			double ModerateActiveFemaleOxygen = 1.7954 / 86400 * TripDuration; //kg
			MaleOxygenRequired = NumMale*ModerateActiveMaleOxygen; //kg
			FemaleOxygenRequired = NumFemale*ModerateActiveFemaleOxygen; //kg
		}
		else if (ActivityLevel == 3)
		{
			double ExtremeActiveMaleOxygen = 4.7586 / 86400 * TripDuration; //kg
			double ExtremeActiveFemaleOxygen = 3.0344 / 86400 * TripDuration; //kg
			MaleOxygenRequired = NumMale*ExtremeActiveMaleOxygen; //kg
			FemaleOxygenRequired = NumFemale*ExtremeActiveFemaleOxygen; //kg
		}
	
		TotalLSOxygenRoverReq = SafetyFactor*(MaleOxygenRequired + FemaleOxygenRequired); //kg
		return TotalLSOxygenRoverReq; //kg
	}
	
	double Nitrogen_Rover_Req
	{
		// Need more info on partial pressures and need to recycle nitrogen. How often does it need to be cycled? Does it need ot be at all for a short duration trip?
		return TotalLSNitrogenRoverReq; //kg
	}
	
	double Mass_Rover_Life_Support
	{
		double SAMMass, CarbonDioxideScrubberMass, AirFilterMass, NumAirFilter, TempHumControlMass, SAMMass, TotalLSMass;
	
		AirMonitorMass = 9.5; //kg
		CarbonDioxideScrubberMass = 0; //kg //NEED INFO
		NumAirFilter = 1; //units
		AirFilter Mass = 8.2 * NumAirFilter; //kg 
		TempHumControlMass = 112; // kg
	
		TotalLSMass = (AirMonitorMass + CarbonDioxideScrubberMass + AirFilterMass + TempHumControlMass) * SafetyFactor;
		
		return TotalLSMass;
	}
	
	double Power_Rover_LifeSupport
	{
		double CarbonDioxideScrubPower, AirFiltration Power, TempHumControlPower,SAMPower;
		CarbonDioxideScrubPower = 1000; //Watts
		AirFiltrationPower = 240; //Watts
		TempHumControlPower = 468; //Watts
		SAMPower = 45; //Watts
		
		TotalLSPower = (CarbonDioxideScrubPower + AirFiltrationPower + TempHumControlPower) * SafetyFactor /1000; //kWatts
		return TotalLSPower;
	}
	
	SMS_CallRoverLifeSupport* SMS_RoverLifeSupport = nullptr; //pointer to class calling this class
	//NOT 100% SURE THIS IS CORRECT

private:
	/*Define your private variables here. These can only be accessed from within this class instance*/

};

