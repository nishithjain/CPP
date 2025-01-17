#include <iostream>

using namespace std;

/*********************************************
			Perfect Forwarding
- 2nd usage of rvalue reference is "Perfect Forwarding"
**********************************************/

#pragma region Perfect Forwarding
//
//class boVector
//{
//	int size_;
//	double* arr_;	// A big array
//public:
//	boVector() = default;
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
//boVector createBoVector(){ boVector a; return a; }	// Creates a boVector
//
//void foo(boVector arg)
//{
//
//}
//
//template<typename T>
//// We have a function relay which take an argument and pass it
//// to foo function. This is called argument forwarding!!!
///*********************************************
//1. No costly and unnecessary copy construction of boVector is made;
//2. rvalue is forwarded as rvalue, lvalue is forwarded as lvalue.
//**********************************************/
////void relay(T arg)
////{
////	foo(arg);
////}
//
//// To achieve perfect forwarding,
//template<typename T>
//void relay(T&& arg)
//{
//	foo(std::forward<T>(arg));
//}
//
//
//int main(void)
//{
//	boVector reusable = createBoVector();
//
//	relay(reusable);			// lvalue is passed
//
//	relay(createBoVector());	// rvalue is passed
//
//	return 0;
//}
#pragma endregion Perfect Forwarding

#pragma region Reference Collapsing Rules
///*********************************************
//C++11 defines reference collapsing rules for
//type deduction.
//1.	T&	&	==>		T&	// We can't write a code like this, but compiler 
//						// generates code like the above and deduce the type
//2.	T&	&&	==>		T&	
//3.	T&&	&	==>		T&
//4.	T&&	&&	==>		T&&
//**********************************************/
//int main(void)
//{
//	return 0;
//}

#pragma endregion Reference Collapsing Rules

#pragma region Remove Reference
//template< typename T>
//struct remove_reference;	// It removes reference on type T
//
//// T is int&
//remove_reference<int&>::type i;	// int i;
//// T is int
//remove_reference<int>::type i;	// int i;
#pragma endregion Remove Reference

#pragma region Universal Reference

template<typename T>
void relay(T&& arg)
{

}
/*********************************************
rvalue reference is specified with type&&
	type&& is rvalue reference?
Answer: No. The type of type&& depends on how the 
arg is initialized.

If arg is initialized with rvalue, then T&& is rvalue reference
If arg is initialized with lvalue, then T&& is lvalue reference

How does this happen?

Example 1:
relay(9);	=> T = int&& => T&& = int&& = int&&
1. 9 rvalue is integer, then T is replaced with int&&.
2. Then T&& will become int&& &&.
3. Applying reference collapsing rule, int&& && will become int &&

Example 2:
int x = 9;
relay(x);	=> T = int&	=>	T&& = int& && = int&

1. x is lvalue and is integer, then T is replaced with int&
2. Then T&& will become int& &&.
3. Applying reference collapsing rule, int& && will become int&

	- T&& is universal reference, this means it can take
	rvalue, lvalue, const, non-const etc...
	- T&& will be universal reference if and only if the following 
	conditions are met:
1. T is a template type.
2. Type deduction (reference collapsing) happens to T.
	- T is a function template type, not class template type.
In any other case, apart from the above, wherever we see T&&, it is 
rvalue reference!!!.
**********************************************/
#pragma endregion Universal Reference

#pragma region Perfect Forwarding Problem

template< typename T>
// relay() function is taking universal reference of arg
void relay(T&& arg)	
{
	// Perform forward on arg
	foo(std::forward<T>(arg));
}

// What does the forward() function does?
template< typename T>
T&& forward(typename remove_reference<T>::type& _Arg)
{
	return static_cast<T&&>(arg);
}

/*********************************************
std::move<T>(arg);		// Turns arg into an rvalue type
std::forward<T>(arg);	// Turns arg to type T&&
**********************************************/
#pragma endregion Perfect Forwarding Problem
