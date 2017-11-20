#ifndef PLANT_H
#define PLANT_H

class ISRU_Plant
{
public:
	ISRU_Plant(double, double);
	void Power(double);
	double Output(double);

	double capacity;
	double contents;
	double demand; // in kW
	double max_rate; //Rate at which plant will produce resources if fully powered (kg/hr)
	bool full;
	bool powered;
	bool high_pressure;
	bool low_pressure;

};

#endif