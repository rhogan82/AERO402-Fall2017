/**********************************************************************************************************************************************/

/***********************************************************************
PURPOSE:
	The purpose of this class is to provide the consumables necessary for a pressurized rover journey.
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
***********************************************************************/

/*Include this in all header files*/
#pragma once

/*includes necessary for the header file. Minimize these if possible*/
#include <cmath>

/*You can define variables this way if you need to, only in the scope of
the class*/
#define SafetyFactor = 1.25

/*Forward declarations of classes used by header*/
class SMS_CallRoverConsumables;

/*TAG refers to a tag you create for your team so there are not naming convention
errors with other groups as we combine all of the projects. Variables inside the
class do not need the tag as they are inside a separate namespace for the class.*/

class SMS_RoverConsumabels { 
public:
	SMS_RoverConsumables();  //constructor
	~SMS_RoverConsumables(); //destructor
    					  /*Define your public variables here. These can be accessed outside
	 				    of the class and in other functions not defined in this scope*/

	//double pos0[3];			/* *i m   Init position of component */
	//double vel0[3];			/* *i m/s Init velocity of component */

					/* The first column is *i or *o or *io for
					   input/output or both */
					/* The second column is the units */
					/* The third component is the description*/

	//double time;			/* s Model time */

	double Water_Required (double NumMale, double NumFemale, double ActivityLevel, double TripDuration)
	{
		double WaterRequiredMale, WaterRequiredFemale;
		double SafetyFactor = 1.25;
		
		if (ActivityLevel == 1)
		{
			double SedentaryMaleWater = 2.32 / 86400 * TripDuration; //kg
			double SedentaryFemaleWater = 1.82 / 86400 * TripDuration; //kg
			WaterRequiredMale = NumMale * SedentaryMaleWater; //kg
			WaterRequiredFemale = NumFemale * SedentaryFemaleWater; //kg
		}
		else if (ActivityLevel == 2)
		{
			double ModerateActiveMaleWater = 3.00 / 86400 * TripDuration; //kg
			double ModerateActiveFemaleWater = 2.35 / 86400 * TripDuration; //kg
			WaterRequiredMale = NumMale * ModerateActiveMaleWater; //kg
			WaterRequiredFemale = NumFemale * ModerateActiveFemaleWater; //kg
		}
		else if (ActivityLevel == 3)
		{
			double ExtremeActiveMaleWater = 3.68 / 86400 * TripDuration; //kg
			double ExtremeActiveFemaleWater = 2.88 / 86400 * TripDuration; //kg
			WaterRequiredMale = NumMale * ExtremeActiveMaleWater; //kg
			WaterRequiredFemale = NumFemale * ExtremeActiveFemaleWater; //kg
		}
		
		double TotalRoverDrinkingWaterRequired = (WaterRequiredMale + WaterRequiredFemale) * SafetyFactor;
		return TotalRoverDrinkingWaterRequired;
	}

	double Calories_Required (double NumMale, double NumFemale, double ActivityLevel, double TripDuration)
	{
		double CaloriesRequiredMale, CaloriesRequiredFemale;
	
		if (ActivityLevel == 1)
		{
			double SedentaryMaleCalories = 2323.85 / 86400 * TripDuration; //cal
			double SedentaryFemaleCalories = 1820.12 / 86400 * TripDuration; //cal
			CaloriesRequiredMale = NumMale * SedentaryMaleCalories; //cal
			CaloriesRequiredFemale = NumFemale * SedentaryFemaleCalories; //cal
		}
		else if (ActivityLevel == 2)
		{
			double ModerateActiveMaleCalories = 3001.64 / 86400 * TripDuration; //cal
			double ModerateActiveFemaleCalories = 2350.99 / 86400 * TripDuration; //cal
			CaloriesRequiredMale = NumMale * ModerateActiveMaleCalories; //cal
			CaloriesRequiredFemale = NumFemale * ModerateActiveFemaleCalories; //cal
		}
		else if (ActivityLevel == 3)
		{
			double ExtremeActiveMaleCalories = 3679.43 / 86400 * TripDuration; //cal
			double ExtremeActiveFemaleCalories = 2881.86 / 86400 * TripDuration; //cal
			CaloriesRequiredMale = NumMale * ExtremeActiveMaleCalories; //cal
			CaloriesRequiredFemale = NumFemale * ExtremeActiveFemaleCalories; //cal
		}
	
		double TotalRoverCaloriesRequired = (CaloriesRequiredMale + CaloriesRequiredFemale) * SafetyFactor;
		return TotalRoverCaloriesRequired;
	}

	SMS_CallRoverConsumables * SMS_RoverConsumables = nullptr; //pointer to class calling this class
	//NOT 100% SURE THIS IS CORRECT


private:
/*Define your private variables here. These can only be accessed from within this class instance*/

};

