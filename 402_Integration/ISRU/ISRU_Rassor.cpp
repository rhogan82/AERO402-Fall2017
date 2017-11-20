#include "ISRU_Rassor.h"

ISRU_Rassor::ISRU_Rassor(double cap, double con1, double con2, double pow)
{
	capacity = cap;
	contents1 = con1;
	contents2 = con2;
	demand = pow;
}

void ISRU_Rassor::Power(double power_supplied)
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

double ISRU_Rassor::Add(double amount, int hopper)
{
	if (powered) {
		if (hopper == 1) {
			if (capacity - contents1 >= amount) {
				contents1 = contents1 + amount;
				full = false;
				return 0;
			}
			else {
				contents1 = capacity;
				full = true;
				return (amount - (capacity - contents1));
			}
		}
		if (hopper == 2) {
			if (capacity - contents2 >= amount) {
				contents2 = contents2 + amount;
				full = false;
				return 0;
			}
			else {
				contents2 = capacity;
				full = true;
				return (amount - (capacity - contents2));
			}
		}
	}
	else {
		return amount;
	}
}

double ISRU_Rassor::Take(double amount, int hopper)
{
	if (powered) {
		if (hopper ==1){
			if (contents1 >= amount) {
				contents1 = contents1 - amount;
				full = false;
				return amount;
			}
			else {
				double temp;
				temp = contents1;
				contents1 = 0;
				full = false;
				return temp;
			}
		}
		if (hopper == 2) {
			if (contents2 >= amount) {
				contents2 = contents2 - amount;
				full = false;
				return amount;
			}
			else {
				double temp;
				temp = contents2;
				contents2 = 0;
				full = false;
				return temp;
			}
		}
	}
	else {
		return 0;
	}
}