#include <iostream>
#include <string>

using namespace std;


/************************************************************************
				User Defined Implicit Type Conversion
Categories of type conversion:
									Implicit		Explicit
Standard Type Conversion				A				B
User Defined Type Conversion			C				D
													(Casting)
************************************************************************/


#pragma region Category A: Implicit Standard Type Conversion

//class Dog
//{
//public:
//	Dog(){ cout << "Inside Dog constructor" << endl; }
//
//};
//
//class Yellowdog : public Dog
//{
//public:
//	Yellowdog(){ cout << "Inside Yellow dog constructor" << endl; }
//};
//
//int main(void)
//{
//	{
//		char c = 'A';
//		int i = c;	// Integral promotion
//
//		char* ptrC = 0;	// int->Null pointer
//
//		void aFunction(int i);
//		aFunction(c);
//
//		Dog* pd = new Yellowdog();
//	}
//
//	return 0;
//}
#pragma endregion Category A: Implicit Standard Type Conversion

#pragma region Category C: Implicit User Define Type Conversion
/************************************************************************
Defined inside class

Method 1: Use constructor that can accept a single parameter and convert
		other types of objects into your class.
Method 2: Use the type conversion function and convert an object of your 
		class into other types.
************************************************************************/

class Dog
{
public:
	// Constructor which takes a single parameter is not just constructor
	// its a constructor + type converter. In the below case, it converts string to Dog
	Dog(string name){ name_ = name; }
	string getName(){ return name_; }

	// Type Conversion Function
	operator string() const { return name_; }
private:
	string name_;
};

class Yellowdog : public Dog
{
public:
	Yellowdog(): Dog("Bruce") { cout << "Inside Yellow dog constructor" << endl; }
};


int main(void)
{
	string dogName = "Bob";
	Dog dog1 = dogName;		// Construction a Dog with string

	// If we don't want to use getName(), then go for Method 2
	cout << "My dog name is :" << dog1.getName() << endl;

	cout << "My dog name is :" << dog1 << endl;

	return 0;
}

/************************************************************************
General guideline:
1. Avoid defining seemingly unexpected conversion.
2. Avoid defining two-way implicit conversion.
************************************************************************/
#pragma endregion Category C: Implicit User Define Type Conversion