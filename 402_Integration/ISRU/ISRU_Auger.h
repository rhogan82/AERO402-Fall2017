#pragma once

struct out { double water; double sulfer; double soil; };

class ISRU_Auger
{
public:
	ISRU_Auger();
	void load(double amount);
	out unload();
	double contents; //in kg
};