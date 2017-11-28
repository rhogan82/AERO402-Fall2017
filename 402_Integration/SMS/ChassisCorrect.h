/**********************************************************************************************************************************************/

/***********************************************************************
PURPOSE:
	The purpose of this class is to return the mass, and volume of the chassis of the pressurized rover.
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
**************************************************************************/

/*Include this in all header files*/
#pragma once

/*includes necessary for the header file. Minimize these if possible*/


/*You can define variables this way if you need to, only in the scope of
the class*/
#define PI = 3.14159

/*Forward declarations of classes used by header*/
class SMS_CallChassisDimensions;

/*TAG refers to a tag you create for your team so there are not naming convention
errors with other groups as we combine all of the projects. Variables inside the
class do not need the tag as they are inside a separate namespace for the class.*/

class SMS_ChassisDimensions { 
public:
	SMS_ChassisDimensions();  //constructor
	~SMS_ChassisDimensions(); //destructor
    					  /*Define your public variables here. These can be accessed outside
	 				    of the class and in other functions not defined in this scope*/

	//double time;			/* s Model time */
	double Length, Width, Height, Density, Thick; //Do these variables need to be declared somewhere? Like given values?
	
	void Mass_Chassis_Declare(double, double, double, double, double); //Not sure why this is here.
	
	double Volume_Chassis() 
	{ 
		double Volume = ((Length*Width*Height) - (Length - 2 * Thick)*(Width - 2 * Thick)*(Height - Thick - Thick_Floor()))
		return Volume; 
	}
	
	double Mass_Chassis() 
	{ 
		Mass = Volume_Chassis() * Density;
		return Mass; 
	}

	SMS_CallChassisDimensions * SMS_ChassisDimensions = nullptr; //pointer to class calling this class


private:
	static double Thick_Floor()
	{
		return 0.0254/8;
	}

};			

