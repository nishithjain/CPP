#include <iostream>

using namespace std;

/*********************************************
	Rvalue Reference - Move Semantics
1. Moving Semantics
2. Perfect Forwarding
**********************************************/

#pragma region Introduction
//void printInt(int& i) { cout << "lvalue reference " << i << endl; }
//void printInt(int&& i){ cout << "rvalue reference " << i << endl; }
////void printInt(int i){}	// Will not work with above overloads!!!
//
//int main(void)
//{
//	int a = 5;	// a is lvalue
//	int& b = a;	// b is lvalue reference
//	//int&& c;	// c is rvalue reference
//
//	printInt(a);	// Will call printInt(int& i)
//	printInt(6);	// Will call printInt(int&& i)
//	
//	return 0;
//}
#pragma endregion Introduction

#pragma region The Problem
//class boVector
//{
//	int size_;
//	double* arr_;	// A big array
//public:
//	boVector(const boVector& rhs)	// Copy constructor
//	{
//		size_ = rhs.size_;
//		arr_ = new double[size_];
//		for (int i = 0; i < size_; ++i)
//		{
//			arr_[i] = rhs.arr_[i];
//		}
//	}
//	~boVector(){ delete arr_; }
//};
//
//void foo(boVector v);
//boVector createBoVector();	// Creates a boVector
//
//int main(void)
//{
//	boVector resuable = createBoVector();
//	
//	// This will invoke the costly copy constructor!!!
//	foo(resuable);	
//
//	// createBoVector returns rvalue(temporary), what's the 
//	// use of copying a temporary while passing it foo function
//	// since that temporary is going to be destroyed!!!
//	foo(createBoVector());
//	return 0;
//}
#pragma endregion The Problem

#pragma region Move Constructor
//class boVector
//{
//	int size_;
//	double* arr_;	// A big array
//public:
//	boVector(const boVector& rhs)	// Copy constructor
//	{
//		size_ = rhs.size_;
//		arr_ = new double[size_];
//		for (int i = 0; i < size_; ++i)
//		{
//			arr_[i] = rhs.arr_[i];
//		}
//	}
//
//	boVector(boVector&& rhs)		// Move constructor
//	{
//		size_ = rhs.size_;
//		arr_ = rhs.arr_;
//		rhs.arr_ = nullptr;
//	}
//	~boVector(){ delete arr_; }
//};
//
//void foo(boVector v);
//boVector createBoVector();	// Creates a boVector
//
//int main(void)
//{
//	boVector resuable = createBoVector();
//
//	// This will invoke the costly copy constructor!!!
//	foo(resuable);
//
//	// Calls Move constructor!!!
//	foo(createBoVector());
//	return 0;
//}
#pragma endregion Move Constructor

#pragma region std::move
class boVector
{
	int size_;
	double* arr_;	// A big array
public:
	boVector() = default;
	boVector(const boVector& rhs)	// Copy constructor
	{
		size_ = rhs.size_;
		arr_ = new double[size_];
		for (int i = 0; i < size_; ++i)
		{
			arr_[i] = rhs.arr_[i];
		}
	}

	boVector(boVector&& rhs)		// Move constructor
	{
		size_ = rhs.size_;
		arr_ = rhs.arr_;
		rhs.arr_ = nullptr;
	}
	~boVector(){ delete arr_; }
};

void foo(boVector v){}
boVector createBoVector(){ boVector a; return a; }	// Creates a boVector
void foo_by_reference(boVector& v){}
int main(void)
{
	boVector reusable = createBoVector();

	/*********************************************
		The situation that we are dealing now is,
	once the foo(reusable) is called, reusable object
	will be destroyed. since foo(reusable) calls
	copy constructor and we know that it is costly.
	Why to call a copy constructor on an object which
	is going to be destroyed soon (reusable)?

		Standard provides a special construct for 
	this kind of situation. It is std::move
	**********************************************/
	//foo(reusable);

	// This will move the object to foo with the move
	// constructor!!! We need to be very careful cos 
	// once we call the std::move, reusable.arr will
	// be nullptr.

	foo(std::move(reusable));	

	// Calls Move constructor!!!
	foo(createBoVector());

	/*
	foo_by_reference(reusable);	- Calls no constructor
	foo(std::move(reusable));	- Calls move constructor
	foo(reusable);				- Calls copy constructor
	Efficiency:
	foo_by_reference(reusable);	- Most Efficient
	foo(std::move(reusable));	- All most efficient as pass by reference
	foo(reusable);				- Most expensive!!!
	*/
	return 0;
}

/*********************************************
Note 1:
The most useful place for rvalue reference is overloading 
copy constructor and copy assignment operator to achieve 
move semantics.

X& X::operator=(X const& rhs);	// Copy Assignment
X& X::operator=(X&& rhs);		// Move assignment

Note 2:
Move semantics is implemented for all STL container. This means
1. Move to C++11, your code will be faster without changing a thing.
2. Passing-by-value can always be used for STL container.
**********************************************/
#pragma endregion std::move