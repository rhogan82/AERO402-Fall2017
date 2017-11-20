#include <iostream>
#include "ISRU_Tank.h"
#include "ISRU_Rassor.h"
#include "ISRU_Plant.h"
#include <cmath>
using namespace std;


int main()
{
	ISRU_Tank tank_1(100,0,5, 63.0493);
	cout << "The capacity is " << tank_1.Get_Capacity() << endl;
	cout << "The contents are " << tank_1.Get_Contents() << endl;
	cout << "The power demand is " << tank_1.Get_Demand() << endl;
	
	cout << endl << endl;
	
	tank_1.Power(5);
	cout << "Add 65.5 Kg of LOx to the tank" << endl;
	double overflow = tank_1.Add(65.5);
	
	cout << "There is now " << tank_1.Get_Contents() << " Kg of LOx in the tank" << endl;
	cout << overflow << " kg was not transfered to the tank" << endl;
	
	cout << "Take 70 Kg of LOx to the tank" << endl;
	double shortage = tank_1.Take(70);
	
	
	cout << "There is now " << tank_1.Get_Contents() << " Kg of LOx in the tank" << endl;
	cout << shortage << " kg was transfered from the tank" << endl;	


	cout << endl << endl;

	ISRU_Rassor rassor_1(50,0, 0, 25);

	rassor_1.Power(30);

	cout << "The rassor picks up 50 kg of dirt" << endl;
	rassor_1.Add(50,1);
	cout << "there is " << rassor_1.contents1 << " kg of dirt in the rassor" << endl;
	cout << "Empty the rassor" << endl;
	rassor_1.Take(rassor_1.contents1,1);
	cout << "There is now " << rassor_1.contents1 << " kg of dirt in the rassor" << endl;

	ISRU_Plant plant_1(3, 30);

	cout << endl << "The plant requires " << plant_1.demand << " kW to operate at a max rate of " << plant_1.max_rate << " kg/hr" << endl;
        cout << "Attempt to read the out put of the plant: The plant is outputting " << plant_1.Output(30) << " kg/hr" << endl;
        cout << "See how not enough power effects plant output rates by only supplying half of the power: The plant is outputting " << plant_1.Output(15) << " kg/hr" << endl;
}




