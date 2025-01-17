#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <deque>

using namespace std;

/************************************************************************
								Functors
	What is the benefit of defining a a function? Why don't we use 
	regular function?
	Benefits of functors:
	1. Smart function that can do more than a regular function. For example
	the class object can declare a data member which can remember the state.
	2. Functor can have its own type.
************************************************************************/

#pragma region Functor Intruducton
//class X
//{
//public:
//	// Overloading operator ()
//	// For functor, we have to put the type before the keyword operator
//	void operator()(string str)
//	{
//		cout << "Calling functor X with parameter: " << str << endl;
//	}
//
//	// This is type conversion function!!!
//	// For type conversion function, we have to put the type after the 
//	// keyword operator
//	operator string () const { return "X"; }
//};
//
//int main(void)
//{	
//	X foo;	// Instance of X
//
//	// 
//	foo("Hi there");
//
//	return 0;
//}
#pragma endregion Functor Intruducton

#pragma region Problem
//// add2 function is used to add 2 to each element in the vector.
//// What if we want to add 3 instead of 2?
//void add2(int i) { cout << i + 2 << " "; }
//
//int main(void)
//{	
//	vector<int> vec{ 1, 3, 5, 6, 8, 4, 7 };
//	cout << "Original vector" <<endl;
//	for (int i : vec)cout << i << " ";
//	cout << endl;
//	for_each(vec.begin(), vec.end(), add2);
//
//	return 0;
//}
#pragma endregion Problem

#pragma region Solution 1 - Not Applicable

//// Now we can change the val to any value we like. But template variable
//// is resolved at compile time.
//template<int val>
//void addVal(int i) { cout << i + val << " "; }
//
//int main(void)
//{
//	vector<int> vec{ 1, 3, 5, 6, 8, 4, 7 };
//	cout << "Original vector" << endl;
//	for (int i : vec)cout << i << " ";
//	cout << endl;
//	for_each(vec.begin(), vec.end(), addVal<2>);
//	
//	// Since the template is resolved at compile time, below code won't compile.
//	//int x = 2;
//	//for_each(vec.begin(), vec.end(), addVal<x>);
//
//	return 0;
//}
#pragma endregion Solution 1 - Not Applicable

#pragma region Best Solution - Functors
//
//class AddValue
//{
//	int value_;
//public:
//	AddValue(int j) :value_(j) { }
//	void operator()(int i)
//	{
//		cout << i + value_ << endl;
//	}
//};
//
//int main(void)
//{
//	vector<int> vec{ 1, 3, 5, 6, 8, 4, 7 };
//	cout << "Original vector" << endl;
//	for (int i : vec)cout << i << " ";
//	cout << endl;
//
//	int x = 2;
//	for_each(vec.begin(), vec.end(), AddValue(x));
//
//	return 0;
//}
#pragma endregion Best Solution - Functors

#pragma region Built-in Functors
///************************************
//STL provides built-in functors...
//less, greater, greater_equal, less_equal, not_equal_to
//logical_and, logical_not, logical_or
//multiplies, minus, plus, divides, modulus, negate
//*************************************/
//int main(void)
//{
//	int x = multiplies<int>()(3, 4);
//	cout << "Value of X: " << x << endl;
//
//	if (not_equal_to<int>() (x, 10))
//		cout << "X Not equal to 10" << endl;
//	return 0;
//}
#pragma endregion Built-in Functors

#pragma region Parameter Binding
//int main(void)
//{
//	set<int> mySet{ 2, 3, 4, 5 };
//	vector<int> vec;
//
//	// We want to multiply each element of set by 10 and
//	// store the result in vector.
//
//	transform(mySet.begin(), mySet.end(),	// Source
//		back_inserter(vec),					// Destination
//		// transform takes functor. But multiplies takes 2 parameters (multiplies<int>()(3, 4);)
//		// bind function can be used to bind and placeholders::_1 is the place holder
//		// for the first argument for multiplies functor and will be substituted
//		// for each element in mySet.
//		bind(multiplies<int>(), placeholders::_1, 10) // Functor
//		);
//
//	for (int i : vec)	// vec: { 20, 30, 40, 50 };
//		cout << i << " ";
//	cout << endl;
//
//
//	return 0;
//}
#pragma endregion Parameter Binding

#pragma region Function to Functor

//double Pow(double x, double y) { return pow(x, y); }
//
//int main(void)
//{
//	set<int> mySet{ 3, 1, 25, 7, 12 };
//	deque<int> d;
//
//	// We want to raise every element of mySet to power of 2
//	// and save the result in deque d.
//
//	// function is used to convert regular function Pow into 
//	// functor f!!!
//	auto f = function<double(double, double)>(Pow);	// in C++11
//
//	transform(mySet.begin(), mySet.end(),
//		back_inserter(d),
//		bind(f, placeholders::_1, 2)
//		);
//
//	for (int i : d)	// d: { 1, 9, 49, 144, 625 };
//		cout << i << " ";
//	cout << endl;
//
//	return 0;
//}
#pragma endregion Function to Functor

#pragma region Need for Functor in STL

////bool lsb_less(int x, int y) { return (x % 10) < (y % 10); }
//
//class Lsb_less
//{
//public:
//	bool operator()(int x, int y)
//	{
//		return (x % 10) < (y % 10);
//	}
//};
//
//int main(void)
//{
//
//	set<int> mySet{ 3, 1, 25, 7, 12 };	// mySet is automatically sorted { 1, 3, 7, 12, 25 }
//
//	cout << "mySet is: ";
//	for (int i : mySet)
//		cout << i << " ";
//	cout << endl;
//
//	set<int, less<int>> mySet1 = { 3, 1, 25, 7, 12 };
//
//	cout << "mySet1 is: ";
//	for (int i : mySet1)
//		cout << i << " ";
//	cout << endl;
//
//	set<int, Lsb_less> leastSigByteSet = { 3, 1, 25, 7, 12 };
//
//	cout << "leastSigByteSet is: ";
//	for (int i : leastSigByteSet)
//		cout << i << " ";
//	cout << endl;
//
//
//	return 0;
//}
#pragma endregion Need for Functor in STL

#pragma region Predicate

/************************************************************************
								Predicate
	A function or a functor that
	1. Returns a boolean or something that can be converted to bool.
	2. Doesn't modify the data.
************************************************************************/

class NeedCopy
{
public:
	bool operator()(int x)
	{
		return (x > 20) || (x < 5);
	}
};

int main(void)
{
	set<int> mySet{ 3, 1, 25, 7, 12 };
	deque<int> d;

	cout << "My set is: ";
	for (int i : mySet) { cout << i << " "; }
	cout << endl;

	transform(mySet.begin(), mySet.end(),		// Source
		back_inserter(d),						// Destination
		NeedCopy()
		);

	cout << "My deque is: ";
	for (int i : d) { cout << i << " "; }
	cout << endl;

	return 0;
}
#pragma endregion Predicate