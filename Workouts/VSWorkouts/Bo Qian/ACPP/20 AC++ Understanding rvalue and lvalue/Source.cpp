#include <iostream>
#include <string>

using namespace std;

/************************************************************************
				Understanding rvalue and lvalue
Why do I care?
	1. Understand C++ construct, and decipher compiler errors or warnings.
	2. C++11 introduces rvalue reference.
What are they?
	lvalue - An object that occupies some identifiable location in memory.
	rvalue - An object that is not a lvalue.
************************************************************************/

class dog
{
public:
	void bark(int age)
	{
		cout << "I am " << age << " years old" << endl;
	}
	virtual void bark(string msg = "just a")
	{
		cout << "Woof, I am " << msg << " dog." << endl;
	}
};

int sum(int x, int y) { return x + y; }
int myGlobal = 0;
int& foo(void){ return myGlobal; }

int main(void)
{
	{	// lvalue examples
		int i;				// i is a lvalue.
		int* ptr = &i;		

		dog d1;				// lvalue of user defined type.
	}
	{	// rvalue examples

		int x = 2;		// 2 is an rvalue.
		//x+2 = 8;		// (i+2) is rvalue
	}

	{	// Reference (or lvalue reference)
		int i;
		int& r = i;	

		//int& y = 6; //ERROR!!!
		//Exception is, const lvalue reference can be assigned a rvalue.
		const int& rr = 5;
	}

	{	//Misconception 1: Functions or operator always yields rvalue
		int x = 4 + 5;
		int y = sum(x, 8);
		foo() = 50;		// function yielding lvalue!!!
		int arr[4];
		arr[2] = 4;		// Operator [] almost always generates lvalue
	}

	{	//Misconception 2: lvalues are modifiable.
		const int c = 1;
		//c = 9;	// ERROR!!!
	}

	{	//Misconception 3: rvalues are not modifiable.
		dog().bark();		// bark() may change the state of dog!!!
	}

	return 0;
}
/************************************************************************
Summary:
	1. Every C++ expression yields either an lvalue or an rvalue.
	2. If the expression has an identifiable memory address, it's lvalue.
************************************************************************/