#include "Maruti.h"


Maruti::Maruti()
{
}


Maruti::~Maruti()
{

}

void Maruti::StartTheCar(void)
{
	cout << "Starting Maruti :-(" << endl;
}

void Maruti::PressAccelerator(double howFar)
{
	cout << "Pressing the accelerator, car not moving!!! :-(" << endl;
}

std::string Maruti::getMake(void)
{
	Make = "Maruti";
	return Make;
}

std::string Maruti::getModel(void)
{
	Model = "800";
	return Model;
}

int Maruti::getYear(void)
{
	Year = 1980;
	return Year;
}
