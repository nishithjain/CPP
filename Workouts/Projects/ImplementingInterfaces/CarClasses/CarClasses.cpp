// This is the main DLL file.

#include "stdafx.h"

#include "CarClasses.h"

using namespace CarClasses;

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