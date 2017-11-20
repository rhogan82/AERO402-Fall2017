#ifndef TANK_H
#define TANK_H

class ISRU_Tank
{
	public:
		ISRU_Tank(double, double, double, double);
		void Power(double);
		double Add(double);
		double Take(double);

		// the accsesors
		double Get_Total_Mass();
		double Get_Capacity();
		double Get_Contents();
		double Get_Demand();

	private:
		double mass;
		double capacity;
		double contents;
		double tempature;
		double demand; // in kW
		bool full;
		bool powered;
		bool high_pressure;
		bool low_pressure;
		
};

#endif