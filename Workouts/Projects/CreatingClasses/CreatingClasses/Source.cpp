#include <iostream>
#include "Power.h"

using namespace std;

class MyClass
{

public:
	MyClass() { cout << "Constructor is getting called" << endl; }
	MyClass(const MyClass& rhs)
	{
		cout << "Copy Constructor is getting called" << endl;
	}
};


int main(void) 
{ 
	//Power aPowerData;
	//aPowerData.externalPowerSource.setDelayOffWhenDisconnected(5000);



	return 0; 
}