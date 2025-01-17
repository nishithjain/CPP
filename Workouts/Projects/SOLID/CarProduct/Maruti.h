#pragma once
#include "ICar.h"

class Maruti : public ICar
{
public:
	Maruti();

	virtual ~Maruti();

	virtual void StartTheCar(void);

	virtual void PressAccelerator(double howFar);

	virtual string getMake(void);

	virtual string getModel(void);

	virtual int getYear(void);

};

