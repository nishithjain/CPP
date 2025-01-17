#include <iostream>
#include <string>

using namespace std;

/************************************************************************
			Koenig Lookup - Argument Dependent Lookup (ADL)
************************************************************************/

#pragma region Example 1
//namespace A
//{
//	struct X {};
//	void g(X){ cout << "Calling A::g()" << endl; }
//}
//
//
//
//int main(void)
//{
//	A::X x1;
//
//	// Even though we have not used the A::g(), compiler will look in
//	// the namespace where the argument type is located. In our case the 
//	// argument X is located in the namespace A. This is called Koenig lookup
//	// or Argument Dependent Lookup (ADL)
//	g(x1);
//
//	return 0;
//}
#pragma endregion Example 1

#pragma region Example 2
//class C
//{
//public:
//	struct Y{ };
//	static void h(Y) { cout << "Calling C::h()" << endl; }
//};
//
//int main(void)
//{
//	C::Y y;
//	//h(y);	// This will not lookup in class. This will be an error
//
//	return 0;
//}
#pragma endregion Example 2

#pragma region Example 3
//namespace A
//{
//	struct X {};
//	void g(X){ cout << "Calling A::g()" << endl; }
//}
//
//namespace C
//{
//	void g(A::X) { cout << "Calling C::g()" << endl; }
//	void j()
//	{
//		A::X x;
//		//g(x);	// Error -ambiguous call to overloaded function
//		// This is because of Koenig lookup, compiler can see 2 g() functions
//	}
//}
//
//int main(void)
//{
//	C::j();	
//
//	return 0;
//}
#pragma endregion Example 3

/************************************************************************
Summary:

With namespaces:
Compiler will search like ---> current scope -> next enclosed scope -> ... -> global scope

With classes
Compiler will search like ---> current class scope -> parent scope -> ... -> global scope

Name hiding will happen when higher priority scope defines a function with 
same name in the lower priority scope.

To override the sequence:
	1. Qualifier or using declaration.
	2. Koenig lookup.
with classes
	- Qualifier or using declaration.

************************************************************************/