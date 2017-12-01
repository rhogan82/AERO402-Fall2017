#pragma once

class ISRU_Plant
{
public:
	ISRU_Plant(double max, double pow);
	void Power(double power_supplied);
	double Output(double power_supplied);

	double capacity;
	double contents;
	double demand; // in kW
	double max_rate; //Rate at which plant will produce resources if fully powered (kg/hr)
	bool full;
	bool powered;
	bool high_pressure;
	bool low_pressure;

};