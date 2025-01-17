// CarClasses.h
#include "ICar.h"

#pragma once

//using namespace System;

namespace CarClasses 
{

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

	class Maruti : public ICar
	{
	public:
		Maruti() {}

		virtual ~Maruti();

		virtual void StartTheCar(void);

		virtual void PressAccelerator(double howFar);

		virtual string getMake(void);

		virtual string getModel(void);

		virtual int getYear(void);

	};

}
