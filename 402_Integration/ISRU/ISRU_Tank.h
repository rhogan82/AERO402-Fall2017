#pragma once

class ISRU_Tank
{
	public:
		ISRU_Tank(double cap, double con, double pow, double mass_of_tank);

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

		void Power(double power_suuplied);
		double Add(double amount);
		double Take(double amount);

		// Accesor functions
		double Get_Total_Mass();
		double Get_Capacity();
		double Get_Contents();
		double Get_Demand();
};