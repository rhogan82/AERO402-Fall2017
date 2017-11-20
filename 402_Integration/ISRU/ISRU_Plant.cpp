#include "ISRU_Plant.h"

ISRU_Plant :: ISRU_Plant(double max, double pow)
{
	max_rate = max;
	demand = pow;
}

void ISRU_Plant :: Power(double power_supplied)
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

double ISRU_Plant :: Output(double power_supplied)
{
	if (power_supplied >= demand)
	{
		return max_rate; //in kg/hr
	}

	if (power_supplied < demand)
	{
		return max_rate * (power_supplied / demand); // in kg/hr
	}

	else {
		return 0;
	}
}



