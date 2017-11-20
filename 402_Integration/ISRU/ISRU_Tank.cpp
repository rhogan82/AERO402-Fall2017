#include "ISRU_Tank.h"


//Constructor (capacity of tank, contents of tank, power needed by tank)
ISRU_Tank :: ISRU_Tank(double cap, double con, double pow, double mass_of_tank)
{
	capacity = cap;
	contents = con;
	demand = pow;
	mass = mass_of_tank;
}

//power the tank if power_supplied is >= demand powered is set to true
void ISRU_Tank :: Power(double power_supplied)
{
	if (power_supplied >= demand)
	{
		powered = true;
	}
	else
	{
		powered = false;
	}
}


//Add to the amount to the tank
double ISRU_Tank :: Add(double amount)
{
	if (powered) {										//Check if powered 
		if (capacity - contents >= amount){				//Check for space
			contents = contents + amount;
			full = false;
			return 0;	
		}	
		else{
			contents = capacity;						//If no space set full return remainder 
			full = true;
			return (amount - (capacity - contents));
		}
	}
	else {
		return amount;
	}
}


//take amount from tank
double ISRU_Tank :: Take(double amount)
{
	if (powered) {										//Check if powered
		if (contents >= amount){						//Check to see if there is enough in tank
			contents = contents - amount;
			full = false;
			return amount;								// Return amount taken
		}	
		else{											//if not enough in tank return contents 
			double temp;
			temp = contents;							//set temp so that contentes can be set to zero 
			contents = 0;								//before the contents are returned 
			full = false;
			return temp;
		}
	}
	else {
		return 0;
	}
}

double ISRU_Tank :: Get_Total_Mass()
{
	return contents + mass;
}


double ISRU_Tank :: Get_Capacity()
{
	return capacity;
}


double ISRU_Tank :: Get_Contents()
{
	return contents;
}

double ISRU_Tank :: Get_Demand()
{
	return demand;
}



