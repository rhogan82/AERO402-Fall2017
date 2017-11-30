#ifndef AUGER_H
#define AUGER_H

struct out{double water; double sulfer; double soil};

class ISRU_Auger
{
public:
	ISRU_Auger();
	void load(double);
	out unload();
	double contents;
};

#endif
