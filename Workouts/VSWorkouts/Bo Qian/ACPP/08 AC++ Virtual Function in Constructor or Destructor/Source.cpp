#include <iostream>

using namespace std;

/************************************************************************
	Pitfall in calling Virtual Function in Constructor and Destructor
************************************************************************/


class Dog
{
public:
	Dog()
	{ 
		cout << "Dog born" << endl; 
		// Invoking bark function
		// Behaves like non virtual function since the Yellow dog is not yet born
		bark();	
	}
	virtual void bark(void){ cout << "I am just a dog!!!" << endl; }
	void seeCat(void){ bark(); }

	// Invoking bark function
	// Behaves like non virtual function since the Yellow dog is already destroyed
	~Dog() { bark(); }
};

class YellowDog : public Dog
{
public:
	YellowDog(){ cout << "Yellow dog born" << endl; }
	virtual void bark(){ cout << "I am an yellow dog" << endl; }
};

int main(void)
{
	YellowDog yd;
	yd.seeCat();

	return 0;
}