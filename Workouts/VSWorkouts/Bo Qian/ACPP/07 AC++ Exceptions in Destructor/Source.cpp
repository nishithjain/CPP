#include <iostream>
#include <string>

using namespace std;

/************************************************************************
			Preventing exceptions from leaving destructor
	- Exceptions thrown by destructor should be contained in the 
	destructor and should not be thrown out of destructor.
************************************************************************/

#pragma region Analysis
//class Dog
//{
//public:
//	string _name;
//	Dog(string name) : _name(name) { cout << name << " is born!!!" << endl; }
//	~Dog() { cout << _name << " is destroyed!!!" << endl; }
//	void bark(void) { cout << _name << " is barking!!!" << endl; }
//};
///************************************************************************
//OUTPUT
//Henry is born!!!
//Bob is born!!!
//Bob is destroyed!!!
//Henry is destroyed!!!
//20 is caught
//
//	- Main point here is, before the exception 20 is caught by the catch
//	block, stack unwinding happens and the objects gets destroyed.
//************************************************************************/
//int main(void)
//{
//	try
//	{
//		Dog aDog("Henry");
//		Dog bDog("Bob");
//		throw 20;
//		aDog.bark();
//		bDog.bark();
//	}
//	catch (int e)
//	{
//		cout << e << " is caught" << endl;
//	}
//	return 0;
//}
#pragma endregion Analysis

#pragma region Problem
//class Dog
//{
//	/************************************************************************
//								PROGRAM CRASHES!!!
//	************************************************************************/
//public:
//	string _name;
//	Dog(string name) : _name(name) { cout << name << " is born!!!" << endl; }
//	void bark(void) { cout << _name << " is barking!!!" << endl; }
//
//	// An exception is added in the destructor. 
//	~Dog() 
//	{
//		cout << _name << " is destroyed!!!" << endl; 
//		throw 20;
//	}
//};
//int main(void)
//{
//	// An exception is added in the destructor. 
//	/************************************************************************
//							Why the program crashes?
//		- When the execution reaches the end of try block, stack unwinding happens and
//	 all the local variables needs to be destroyed. So, dDog("Bob")  will be
//	 destroyed first. When the Bob destructor is executed, it throws an
//	 exception. So before the exception is caught by the catch block, aDog("Henry")
//	 also needs to be destroyed. So aDog destructor also executes and also throws
//	 an exception.
//		- As a result, there are 2 exceptions pending at the same time one from Bob
//	and one from Henry. C++ doesn't handle 2 exceptions at the same time so 
//	the program crashes.
//	************************************************************************/
//	try
//	{
//		Dog aDog("Henry");
//		Dog bDog("Bob");
//		aDog.bark();
//		bDog.bark();
//	}
//	catch (int e)
//	{
//		cout << e << " is caught" << endl;
//	}
//	return 0;
//}
#pragma endregion Problem

#pragma region Solution 1
//class Dog
//{
//public:
//	string _name;
//	Dog(string name) : _name(name) { cout << name << " is born!!!" << endl; }
//	void bark(void) { cout << _name << " is barking!!!" << endl; }
//
//	~Dog()
//	{
//		try
//		{
//			cout << _name << " is destroyed!!!" << endl;
//			throw 20;
//		}
//		// Enclose all the exception prone code here
//		catch (/*MYEXCEPTION e*/int e)
//		{
//			cout << "Exception is thrown in the destructor!!! " << e << endl;
//		}
//		catch (...)
//		{
//			cout << "Exception is thrown in the destructor!!!";
//		}
		/*******************************************************
			- Downside of this solution is that the exception is 
			swallowed by the Dog's destructor. The Dog's client 
			will not get the exception and the Dog's client will 
			not know what has happened!!!
		********************************************************/
//	}
//};
//int main(void)
//{
//	try
//	{
//		Dog aDog("Henry");
//		Dog bDog("Bob");
//		aDog.bark();
//		bDog.bark();
//	}
//	catch (int e)
//	{
//		cout << e << " is caught" << endl;
//	}
//	return 0;
//}
#pragma endregion Solution 1

#pragma region Sloution 2 MoveExceptionProneCode
class Dog
{
public:
	string _name;
	Dog(string name) : _name(name) { cout << name << " is born!!!" << endl; }
	void bark(void) { cout << _name << " is barking!!!" << endl; }

	~Dog()
	{
		cout << _name << " is destroyed!!!" << endl;
	}
	void prepareToDestruct()
	{
		cout << "Throwing exception!!!" << endl;
		// Moving the exception prone code to other method
		throw 20;
	}
};
int main(void)
{
	try
	{
		Dog aDog("Henry");
		Dog bDog("Bob");
		aDog.bark();
		bDog.bark();
		aDog.prepareToDestruct();	// Another API needs to be called by Dog's client
		bDog.prepareToDestruct();	// Another API needs to be called by Dog's client
	}
	catch (int e)
	{
		cout << e << " is caught" << endl;
	}
	return 0;
}
#pragma endregion Sloution 2 MoveExceptionProneCode