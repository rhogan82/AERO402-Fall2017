/*************************************************************************
**********************(COPYRIGHT INFORMATION)*****************************
**************************************************************************/

/*************************************************************************
PURPOSE:
	(Provides structure and functions for battery class)
LANGUAGE:
	(C++)
LIBRARY DEPENDENCIES:
	(
	 ()
	)

ASSUMPTIONS AND LIMITATIONS:
	(
	 (Battery charges up to 95% then decharges to 5%)
	)
PROGRAMMERS:
	(
	 ((Max Meyers) (Team Rocket/10) (10/29/17) (changes))
	)
**************************************************************************/

#include "Battery.h"

Battery::Battery(double Cap, double PowReq){
	Capacity = Cap;
	vol=PowReq/(0.95*43.03);
	weight=PowReq/(0.*0.048);
	num_unit=weight/3.65;
	maxcap=PowReq/0.95;
	pluggedin = false;
	ifcharging = false;
	ifdecharging = true;
	bound = 0.95;
}

void Battery::Charge_Check(double time, double inputPow){
	if (pluggedin){
		if (Capacity/maxcap <= bound){
			ifcharging = true;
			ifdecharging = false;
			bound = 0.95;
		}
		else if (capacity/maxcap > bound){
			ifcharging = false;
			ifdecharging = true;
			bound = 0.05;
		}
		if (ifcharging){
			Capacity = Capacity + inputPow*time;
		}
		else if (ifdecharging) {
			outputpow = 270*num_unit;
			Capacity = Capacity - outputpow*time;
		}
		else {
			return;
		}
	}
	else {
		return;
	}
}

void Battery::Is_Plugged(bool plug){
	pluggedin = plug;
	return;
}
