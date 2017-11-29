/*************************************************************************
**********************(COPYRIGHT INFORMATION)*****************************
**************************************************************************/

/*************************************************************************
PURPOSE:
	(Defines the battery class)
LANGUAGE:
	(C++)
LIBRARY DEPENDENCIES:
	(
	 ()
	)

ASSUMPTIONS AND LIMITATIONS:
	(
	 (Need inputs: time, inputPow, PowReq, and plug)
	)
PROGRAMMERS:
	(
	 ((Max Meyers) (Team Rocket/10) (10/29/17) (changes))
	)
**************************************************************************/

class Battery
{
	public:
		Battery(double Cap, double PowReq);
		~Battery();
		float vol
		float weight
		int num_unit
		double Capacity;
		double maxcap;
		double bound;
		bool pluggedin;
		bool ifcharging;
		bool ifdecharging;
		
		void Charge_Check(double time, double inputPow);
		void Is_Plugged(bool plug);
};
