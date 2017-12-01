#pragma once

class ISRU_Rassor
{
public:

public:
	ISRU_Rassor(double cap, double con1, double con2, double pow);

	double capacity; //in kg
	double contents1;
	double contents2;
	double demand; //in kW
	bool full;
	bool powered;

	void Power(double power_supplied);
	double Add(double amount, int hopper);
	double Take(double amount, int hopper);
};
