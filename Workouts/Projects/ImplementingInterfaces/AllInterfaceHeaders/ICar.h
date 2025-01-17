#pragma once
#include <string>
#include <iostream>

using namespace std;
class ICar
{
protected:
	string Make;
	string Model;
	int Year;
public:
	virtual void StartTheCar(void) = 0;
	virtual void PressAccelerator(double howFar) = 0;
	virtual string getMake(void) = 0;
	virtual string getModel(void) = 0;
	virtual int getYear(void) = 0;
	virtual ~ICar() {}
};

