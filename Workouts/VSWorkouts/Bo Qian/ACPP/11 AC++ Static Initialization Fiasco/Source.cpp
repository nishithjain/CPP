#include <iostream>
#include <string>
#include "Dog.h"
#include "Cat.h"
#include "Singleton.h"

using namespace std;

/************************************************************************
				Static Initialization Fiascoo Problem
	- A subtle problem that can crash the program.
************************************************************************/

#pragma region The Problem
//Dog d("Gunner");
//
//int main(void)
//{
//	d.bark(); // Inside bark(), I am calling cat's meow method.
///************************************************************************
//Dog born with name Bruce
//I am just a cat. My name is ----->	// Cat's method is called. Undefined behavior
//Cat born with name Smokey			// To eliminate this, we use singleton design pattern
//I am just a dog. My name is Bruce
//Dog born with name Gunner
//I am just a cat. My name is Smokey
//I am just a dog. My name is Gunner
//************************************************************************/
//	return 0;
//}
#pragma endregion The Problem

#pragma region SolutionToTheProblem

int main(void)
{
	SingleTon s;

	SingleTon::getCat()->meow();

	return 0;
}
#pragma endregion SolutionToTheProblem