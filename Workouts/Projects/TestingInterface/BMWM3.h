#pragma once
#include "ICar.h"


class BMWM3 : public ICar
{
public:
	BMWM3(){}

	virtual ~BMWM3();

	virtual void StartTheCar(void);

	virtual void PressAccelerator(double howFar);

	virtual string getMake(void);

	virtual string getModel(void);

	virtual int getYear(void);

};

