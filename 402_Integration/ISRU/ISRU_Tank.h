#pragma once

class ISRU_Tank
{
	public:
		ISRU_Tank(double cap, double con, double pow, double mass_of_tank);

	private:
		double mass; //in kg
		double capacity; //in kg
		double contents;
		double tempature; //in K
		double demand; // in kW
		bool full;
		bool powered;
		bool high_pressure;
		bool low_pressure;

		void Power(double power_suplied);
		double Add(double amount); //in kg
		double Take(double amount); //in kg

		// Accesor functions
		double Get_Total_Mass();
		double Get_Capacity();
		double Get_Contents();
		double Get_Demand();
};