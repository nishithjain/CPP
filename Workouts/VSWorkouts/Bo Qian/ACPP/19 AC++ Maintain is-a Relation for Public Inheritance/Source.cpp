#include <iostream>
#include <string>

using namespace std;

/************************************************************************
			Maintain is-a Relation for Public Inheritance
Public inheritance -> is-a relation

A derived class should be able to do everything the base class can do.
************************************************************************/

#pragma region Lesson 1
//class dog
//{
//public:
//	virtual void bark(string msg = "just a")
//	{
//		cout << "Woof, I am " << msg << " dog." << endl;
//	}
//};
//
//class yellowdog : public dog
//{
//public:
//	virtual void bark(string msg = "a yellow")
//	{
//		cout << "Inside Yellow Dog!!!" << endl;
//		cout << "Woof, I am " << msg << " dog." << endl;
//	}
//};
//
//int main(void)
//{
//	yellowdog* ptrYellow = new yellowdog;
//	ptrYellow->bark();
//
//	dog* ptrDog = ptrYellow;
//	// When ptrDog->bark is called, still we are calling the yellow 
//	// dog's bark function(See the output). But the it will pickup the
//	// default value of message from Dog's bark function!!!
//	// Lesson: Never override default parameter value of virtual function!!!
//	ptrDog->bark();
//
//	return 0;
//}
///***********************************
//Inside Yellow Dog!!!
//Woof, I am a yellow dog.
//Inside Yellow Dog!!!
//Woof, I am just a dog.
//***********************************/
#pragma endregion Lesson 1


#pragma region Lesson 2
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

class yellowdog : public dog
{
public:
	using dog::bark;
	virtual void bark(string msg = "a yellow")
	{
		cout << "Inside Yellow Dog!!!" << endl;
		cout << "Woof, I am " << msg << " dog." << endl;
	}
};

int main(void)
{
	yellowdog* ptrYellow = new yellowdog;
	// Below code won't compile:
	// Reason: 
	// When the compiler sees the bark function in the yellow dog, it 
	// stops REGARDLESS OF THE PARAMETERS. It won't look up the ladder.
	// We have to use using dog::bark as shown above
	ptrYellow->bark(5);	

	return 0;
}
#pragma endregion Lesson 2

/***********************************
Summary:
1. Precise definition of classes.
2. Don't override non-virtual functions.
3. Don't override default parameter values for virtual functions.
4. Force inheritance of shadowed functions.
***********************************/