#include <iostream>
#include <string>

using namespace std;


#pragma region ReuseWithInheritance
//class Dog
//{
//public:
//	// Common activities
//	void bark(int age)
//	{
//		cout << "I am " << age << " years old" << endl;
//	}
//};
//
//class Bulldog : public Dog
//{
//public:
//	// Calls common activities to perform more tasks.
//
//};
//
//class ShepheredDog : public Dog
//{
//public:
//	// Calls common activities to perform more tasks.
//};
//
//int main(void)
//{
//
//	return 0;
//}
#pragma endregion ReuseWithInheritance

#pragma region ReuseWithComposition
class ActivityManager
{
	// Common activities
	void bark(int age)
	{
		cout << "I am " << age << " years old" << endl;
	}
};

class Dog
{
public:

};

class Bulldog : public Dog
{
public:
	ActivityManager* ptrActMgr;
	// Calls common activities to perform more tasks.

};

class ShepheredDog : public Dog
{
public:
	ActivityManager* ptrActMgr;
	// Calls common activities to perform more tasks.
};

int main(void)
{

	return 0;
}
#pragma endregion ReuseWithComposition

/************************************************************************
Composition is better than inheritance

1. Less code coupling between reused code and re-user of the code
	In case of inheritance....
	a. Child class automatically inherits ALL parent class's public members.
	b. Child class can access parent's protected members.
		- Inheritance breaks encapsulation.
2. Dynamic binding
	a. Inheritance is bound at compile time.
	b. Composition can be bound either at compile time or at run time.

3. Flexible code construct
	Dog				ActivityManager

	BullDog			OutDoorActivityManager
	ShepherdDog		InDoorActivityManager
	...				...
************************************************************************/