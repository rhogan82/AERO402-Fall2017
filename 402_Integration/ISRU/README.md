![alt text](https://github.tamu.edu/cyberguy/isru/blob/master/ISRU_Logo.png "ISRU")

# Goals

Create class for

- Tanks 
- Rassors
- Plants
- Augers 

# Documentation

## Tank

### tank(double capacity, double contents, double power requirements, double mass of the tank)
Creates an instance of the tank class with the given variables. 


### Add(double amount)
adds amount to tank and returns the quantity that was not transferred as a double

### Power(double power_supplied)
send power_supplied to the tank. If power_supplied is less then demand tank will not power.

### Take(double amount)
takes amount from tank, returns the quantity that is transferred as a double.

### accessors for tank class

#### double Get_Total_Mass();

#### double Get_Capacity();

#### double Get_Contents();

#### double Get_Demand();


## Rassor

Public values

```cpp
	double capacity;
	double contents_1;
	double contents_2;
	double demand; //in kW
	bool full;
	bool powered;
```

### tank(double capacity, double conntents_1, double contents_2, double power requirments)
Creates an instance of the rassor class with the given variables. 

### power(double power_supplied)
send power_supplied to the rassor. If power_supplied is less then demand rassor will not power.

### take(double amount, int hopper)
takes amount from rassor's specified hopper, returns the quantity that is transferred as a double.

### add(double amount, int hopper)
adds amount to rassor's specified hopper and returns the quantity that was not transferred as a double

## Plant

Public values
```cpp
	double capacity;	
	double contents;	
	double demand; // in kW
	double max_rate; //Rate at which plant will produce resources if fully powered (kg/hr)
	bool full;
	bool powered;
	bool high_pressure;
	bool low_pressure;
```

### plant(double max, double pow)
creates an instance of the plant class max is the rate of production and pow is the power required.

### power(double power_supplied)
send power_supplied to the plant. If power_supplied is less then demand plant will not power.

### output()
If powered returns a double of what ever the plant produces.
