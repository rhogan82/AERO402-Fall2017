/*************************************************************************
**********************(COPYRIGHT INFORMATION)*****************************
**************************************************************************/

/*************************************************************************
PURPOSE:
	The purpose of this class is to calculate the dimensions of the drive train.
LANGUAGE:
	(C++)
LIBRARY DEPENDENCIES:
	(
	 ()
	)
REFERENCES:
	(
	 (Reference #1)
	 (Reference #n)
	)
ASSUMPTIONS AND LIMITATIONS:
	(
	 (Assumption #1)
	 (Assumption #n)
	)
PROGRAMMERS:
	(
	 ((Name) (Company/Team) (Date) (changes))
	)
**************************************************************************/

/*Include this in all header files*/
#pragma once

/*includes necessary for the header file. Minimize these if possible*/
#include <string>
#include <stdio.h>

/*You can define variables this way if you need to, only in the scope of
the class*/
#define PI = 3.14159

/*Forward declarations of classes used by header*/
class TAG_ClassCalledByThisClass;

/*TAG refers to a tag you create for your team so there are not naming convention
errors with other groups as we combine all of the projects. Variables inside the
class do not need the tag as they are inside a separate namespace for the class.*/

class TAG_NameYourClassLikeThis { /*Use capital letters for beginning of words,
								  no undersores (_)*/
public:
	TAG_NameYourClassLikeThis();  //constructor
	~TAG_NameYourClassLikeThis(); //destructor
    					  /*Define your public variables here. These can be accessed outside
	 				    of the class and in other functions not defined in this scope*/

	double pos0[3];			/* *i m   Init position of component */
	double vel0[3];			/* *i m/s Init velocity of component */

					/* The first column is *i or *o or *io for
					   input/output or both */
					/* The second column is the units */
					/* The third component is the description*/

	double time;			/* s Model time */

	void Get_Velocity();		/* function that returns a void. This function does something and then 
					   does not use a return value. */
					/* Naming convention for member functions includes underscores to
					   differentiate from classes */
					/* Enum classes will be all caps with underscores: ENUM_CLASS_NAME */

	double Get_Length();    	/* function returning double value */

	TAG_ClassCalledByThisClass* ParentClass = nullptr; //pointer to class calling this class


private:
					/*Define your private variables here. These can only be accessed
					  from within this class instance*/

};			/*End of class*/

