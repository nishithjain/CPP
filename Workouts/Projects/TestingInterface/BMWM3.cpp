#include "BMWM3.h"



BMWM3::~BMWM3()
{
}

void BMWM3::StartTheCar(void)
{
	cout << "Starting BMW M3" << endl;
}

void BMWM3::PressAccelerator(double howFar)
{
	cout << "Accelerating the car..." << endl;
}

std::string BMWM3::getMake(void)
{
	Make = "BMW";
	return Make;
}

std::string BMWM3::getModel(void)
{
	Model = "M3";
	return Model;
}

int BMWM3::getYear(void)
{
	Year = 2014;
	return Year;
}
