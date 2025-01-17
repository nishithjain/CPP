#include <iostream>
#include <string>

using namespace std;

/************************************************************************
			Inheritance - Public, Protected, and Private
************************************************************************/

class Base 
{
public:
	void f_Public(){ cout << "f_Public() is called " << endl; }
protected:
	void f_Protected(){ cout << "f_Protected is called " << endl; }
private:
	void f_Private(){ cout << "f_Private is called " << endl; }
};

class Derived_Public : public Base 
{
public:
	void aFunction()
	{
		f_Public();		// OK, f_Public is Derived_Public's public function
		f_Protected();	// OK, f_Protected is Derived_Public's public function
		//f_Private();	// ERROR, f_Private is Base's private function
	}
};

class Derived_Protected : protected Base 
{
public:
	void aFunction()
	{
		f_Public();		// OK, f_Public is Derived_Protected's protected function
		f_Protected();	// OK, f_Protected is Derived_Protected's protected function
		//f_Private();	// ERROR, f_Private is Base's private function
	}
};

class Derived_Private : private Base 
{
public:
	void aFunction()
	{
		f_Public();		// OK, f_Public is Derived_Private's private function
		f_Protected();	// OK, f_Protected is Derived_Private's private function
		//f_Private();	// ERROR, f_Private is Base's private function
	}
};

/************************************************************************
	private, protected and public keywords specifies different access control 
from the derived class to the base class.

Access control:
1. None of the derived class can access anything that is private in Base.
2. Derived_Public inherits public members of Base as public and the protected
members of Base as protected.
3. Derived_Private inherits the public and protected members of Base as private.
4. Derived_Protected inherits the public and protected members of Base as protected.

Casting point of view:
1. Anyone can cast a Derived_Public* to Base*. Derived_Public is a special kind of Base.
2. Derived_Private's members and friends can cast a Derived_Private* to Base*.
3. Derived_Protected's member, friends and children can cast a Derived_Protected* to Base*.
************************************************************************/

int main(void)
{
	Derived_Public d1;
	d1.f_Public();		// OK. f_Public is Derived_Public's public function.

	Derived_Protected d2;
	//d2.f_Public();	// ERROR. f_Public is Derived_Protected's protected function.
	
	Base* ptrBase = &d1;
	//ptrBase = &d2;	// ERROR!!!

	return 0;
}