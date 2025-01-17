#include <string>
#include <iostream>
#include <vector>

#include "ICar.h"
#include "BMWM3.h"
#include "Maruti.h"

using namespace std;

void PrintCarInformation(ICar* car)
{
	cout << "Car Make: \t" << car->getMake() << endl;
	cout << "Car Model: \t" << car->getModel()<< endl;
	cout << "Car Year: \t" << car->getYear() << endl;
}

int main(void)
{
	vector<ICar*> cars;

	BMWM3* aBMWCar = new BMWM3();
	Maruti* aMaruti = new Maruti();

	cars.push_back(aBMWCar);
	cars.push_back(aMaruti);

	for (auto car : cars)
		PrintCarInformation(car);

	return 0;
}