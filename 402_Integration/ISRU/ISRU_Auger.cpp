#include "ISRU_Auger.h"

ISRU_Auger::ISRU_Auger(void)
{
}


void ISRU_Auger::load(double amount)
{
	contents = amount;
}

out ISRU_Auger::unload()
{
	out processed;
	processed.water = contents*.03;
	processed.sulfer = contents*.03;
	processed.soil = contents*.96;
	return processed;
}
