#include <iostream>
#include <string>

using namespace std;


/************************************************************************
								CASTING
Type Conversion:
	1. Implicit Type Conversion
	2. Explicit Type Conversion - also called CASTING
************************************************************************/

class Dog
{
public:
	Dog(string name){ cout << "Inside Dog constructor" << endl; }
	operator string() { return "Hello"; }
	virtual ~Dog(){}
};

class Yellowdog : public Dog
{
public:
	Yellowdog(): Dog("Hello") { cout << "Inside Yellow dog constructor" << endl; }
};


int main(void)
{

#pragma region StaticCast
	{
		// Static Cast will work as long as type converter's are defined for those types.
		int i = 9;
		float f = static_cast<float> (i);
		Dog d1 = static_cast<Dog> (string("BOB"));	// Type converter is defined here
		Dog* ptrDog = static_cast<Dog*> (new Yellowdog());
	}
#pragma endregion StaticCast

#pragma region DynamicCast
	/************************************************************************
		1. Dynamic cast can work only on pointers or reference, it can't work 
		on objects.
		2. It converts one type to a related type (Typically used in Down cast)
		3. Does run-time type check. If not compatible, then returns nullptr.
		4. Ti requires the two types to be polymorphic.
	************************************************************************/
	{
		Dog* ptrDog = new Yellowdog();
		Yellowdog* ptrYelloDog = dynamic_cast<Yellowdog*>(ptrDog);
	}
#pragma endregion DynamicCast

#pragma region ConstCast
	/************************************************************************
		1. Works only on pointers or references can't work on objects.
		2. Only works on same type.
		3. To cast away constness of the object being pointed to.
	************************************************************************/
	{
		const char* str = "Hello World";
		char* modifiable = const_cast<char*>(str);
	}
#pragma endregion ConstCast

#pragma region ReinterpretCast
	/************************************************************************
		1. Works only on pointers or references can't work on objects.
		2. Can work on any type!!!!
	************************************************************************/
	{
		long p = 51110900;
		Dog* dd = reinterpret_cast<Dog*>(p);
	}
#pragma endregion ReinterpretCast

#pragma region C-StyleCasting
	// Mixture of static_cast, const_cast and reinterpret_cast
	{
		short a = 2000;
		int i = (int)a;		// C-Like cast notation
		int j = int(a);		// Functional notation
	}
#pragma endregion C-StyleCasting

	/************************************************************************
	Generally C++ style of casts are preferred over C-Style, because:
	1. Easier to identify in the code.
	2. Less usage error.
		a. Narrowly specified purpose for each cast.
		b. Run-time type check capability.
	************************************************************************/

	return 0;
}