#ifndef RASSOR_H
#define RASSOR_H

class ISRU_Rassor
{
public:

public:
	ISRU_Rassor(double, double, double, double);
	void Power(double);
	double Add(double, int);
	double Take(double, int);

	double capacity;
	double contents1;
	double contents2;
	double demand; //in kW
	bool full;
	bool powered;



};

#endif
