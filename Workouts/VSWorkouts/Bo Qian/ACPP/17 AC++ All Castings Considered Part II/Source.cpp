#include <iostream>
#include <string>
using namespace std;

#pragma region TheProblem
//class Dog
//{
//public:
//	Dog(){ /*cout << "Inside Dog constructor" << endl;*/ }
//	virtual ~Dog(){}
//};
//
//class Yellowdog : public Dog
//{
//	int age_;
//public:
//	Yellowdog(){ /*cout << "Inside Yellow dog constructor" << endl;*/ }
//	void bark(){ cout << "Woof...Woof..." << endl; }
//};
//
//int main(void)
//{
//	Dog* ptrDog = new Dog;
//	
//	// We are casting Dog to Yellow Dog...
//	Yellowdog* ptrYellowDog = dynamic_cast<Yellowdog*> (ptrDog);
//	// YellowDog will print nullptr here, and causes undefined behavior.
//	// Since we are not accessing any member variable inside bark, this function
//	// can be treated as static function and still this call will print Woof...Woof
//	ptrYellowDog->bark();
//
//	// YellowDog will print nullptr here
//	cout << "ptrYellowDog = " << ptrYellowDog << endl;
//	cout << "ptrDog = " << ptrDog << endl;
//
//	return 0;
//}
#pragma endregion TheProblem

#pragma region AnotherProblem
//class Dog
//{
//public:
//	Dog(){ /*cout << "Inside Dog constructor" << endl;*/ }
//	virtual ~Dog(){}
//};
//
//class Yellowdog : public Dog
//{
//	int age_;
//public:
//	Yellowdog(){ age_ = 0;/*cout << "Inside Yellow dog constructor" << endl;*/ }
//	void bark(){ cout << "Woof...Woof..." << age_ << endl; }
//};
//
//int main(void)
//{
//	Dog* ptrDog = new Dog;
//
//	// We are casting Dog to Yellow Dog... All yellow dogs are dogs, but all
//	// dogs are not yellow dogs.
//	Yellowdog* ptrYellowDog = dynamic_cast<Yellowdog*> (ptrDog);
//	// YellowDog will be nullptr here, and when we try to access the member variable of 
//	// Yellow Dog, the program CRASHES!!!!!!!!!!.
//	ptrYellowDog->bark();
//
//	// YellowDog will print nullptr here
//	cout << "ptrYellowDog = " << ptrYellowDog << endl;
//	cout << "ptrDog = " << ptrDog << endl;
//
//	return 0;
//}
#pragma endregion AnotherProblem

#pragma region Using StaticCast
//class Dog
//{
//public:
//	Dog(){ /*cout << "Inside Dog constructor" << endl;*/ }
//	virtual ~Dog(){}
//};
//
//class Yellowdog : public Dog
//{
//	int age_;
//public:
//	Yellowdog(){ age_ = 0;/*cout << "Inside Yellow dog constructor" << endl;*/ }
//	void bark(){ cout << "Woof...Woof..." << age_ << endl; }
//};
//
//int main(void)
//{
//	Dog* ptrDog = new Dog;
//
//	// static_cast will always succeed 
//	Yellowdog* ptrYellowDog = static_cast<Yellowdog*> (ptrDog);
//	ptrYellowDog->bark();
//
//	cout << "ptrYellowDog = " << ptrYellowDog << endl;
//	cout << "ptrDog = " << ptrDog << endl;
//
//	return 0;
//}
#pragma endregion Using StaticCast

#pragma region Solution 1
//class Dog
//{
//public:
//	Dog(){ /*cout << "Inside Dog constructor" << endl;*/ }
//	virtual ~Dog(){}
//};
//
//class Yellowdog : public Dog
//{
//	int age_;
//public:
//	Yellowdog(){ age_ = 0;/*cout << "Inside Yellow dog constructor" << endl;*/ }
//	void bark(){ cout << "Woof...Woof..." << age_ << endl; }
//};
//
//int main(void)
//{
//	Dog* ptrDog = new Dog;
//
//	Yellowdog* ptrYellowDog = dynamic_cast<Yellowdog*> (ptrDog);
//
//	if (ptrYellowDog)
//		ptrYellowDog->bark();
//
//	cout << "ptrYellowDog = " << ptrYellowDog << endl;
//	cout << "ptrDog = " << ptrDog << endl;
//
//	return 0;
//}
#pragma endregion Solution 1

#pragma region Better Solution
//class Dog
//{
//public:
//	Dog(){ /*cout << "Inside Dog constructor" << endl;*/ }
//	virtual ~Dog(){}
//	// Better solution is to add the virtual bark function in the base class
//	virtual void bark(){}
//};
//
//class Yellowdog : public Dog
//{
//	int age_;
//public:
//	Yellowdog(){ age_ = 0;/*cout << "Inside Yellow dog constructor" << endl;*/ }
//	void bark(){ cout << "Woof...Woof..." << age_ << endl; }
//};
//
//int main(void)
//{
//	Dog* ptrDog = new Dog;
//	Yellowdog* ptrYellowDog;
//	//Yellowdog* ptrYellowDog = dynamic_cast<Yellowdog*> (ptrDog);
//	//if (ptrYellowDog)
//	ptrYellowDog->bark();
//
//	cout << "ptrYellowDog = " << ptrYellowDog << endl;
//	cout << "ptrDog = " << ptrDog << endl;
//
//	return 0;
//}
#pragma endregion Better Solution

class Dog
{
public:
	string name_;
	Dog() : name_("Bruce") { /*cout << "Inside Dog constructor" << endl;*/ }
	
	// Literally a function can't be const. Then who is const here in the 
	// below code? Answer: *this is const
	void bark() const 
	{
		cout << "My name is " << name_ << endl;
		const_cast<Dog*>(this)->name_ = "Henry";
	}
};

int main(void)
{
	Dog aDog;

	aDog.bark();
	cout << "Now my name is: " << aDog.name_ << endl;

	return 0;
}


/************************************************************************
****************************C++ Style Casting****************************

						Generate Code?	Generate Data?	Risky	Data Type
Object Casting
	static_cast				Yes				Yes			  2		Any types(As long as type 
																conversion is defined)


Pointer/Reference	
	static_cast				No				No			  4		Related types	
					|It will tell the |
					|compiler to	  |
					|interpret the	  |
					|pointer in		  |
					|different way	  |

	dynamic_cast			Yes				No			  3		Related types(Down-casting)
	const_cast				No				No			  1		Same type
	reinterpret_cast		No				No			  5		Any type

*****************************C Style Casting*****************************
					Generate Code?	Generate Data?	Risky	Data Type
Object Casting			Yes				Yes			  5		Any Types(As long as type 
															conversion is defined)

Pointer/Reference		No				No			  5		Any Types
************************************************************************/