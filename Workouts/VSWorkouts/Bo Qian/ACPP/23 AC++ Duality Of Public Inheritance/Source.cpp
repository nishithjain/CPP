/************************************************************************
		Duality Of Public Inheritance - Interface & Implementation
	- Inheritance of interface
	- Inheritance of implementation
************************************************************************/
#include <iostream>
#include <string>

using namespace std;

class Dog
{
public:
	virtual void bark() = 0;
	void run() { cout << "Woof, I am running." << endl; }
	virtual void eat() { cout << "I am eating" << endl; }		// impure virtual function
protected:
	void sleep() { cout << "I am sleeping" << endl; }
};

class Yellowdog : public Dog
{
public:
	// Interface only inheritance
	virtual void bark() { cout << "Woof, I am yellow dog." << endl; }
	
	// A non virtual function should not be overridden!!!!
	// Yellow dog inherits interface of dog function as 
	// well as the implementation of run function.

	// Since the function is protected, yellow dog inherits the function
	// It only inherits the implementation but not the interface.
	// To provide a service for sleep, it has to provide its own version.
	void iSleep() { sleep(); }

};

/************************************************************************
Summary:

1. Pure virtual public function - inherits interface only.
2. Non-virtual public function - inherits both interface and implementation.
3. Impure virtual public function - inherits interface and default implementation.
4. Protected functions - inherits implementation only.

Interface inheritance
1. Sub-typing.
2. Polymorphism.

Pitfall:
- Be careful of interface bloat.
- Interface do not reveal implementation.

Implementation inheritance:
1. Increase code complexity.
2. Not encouraged.

Guidelines of implementation inheritance
1. Do not use inheritance for code reuse, use composition.
2. Minimize the implementation in base classes. Base classes should be thin.
3. Minimize the level of hierarchies in implementation inheritance.
************************************************************************/
int main(void)
{
	Yellowdog aDog;
	aDog.bark();
	return 0;
}