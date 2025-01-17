#include <iostream>
#include <string>
using namespace std;

int globalI;
/************************************************************************
						   +------------+
					+----->| Expression |<------+
					|      +------------+       |
					|                           |
					|                           |
				+--------+                  +--------+
		+------>| gValue |<-------+    +--->| rValue |<-----+
		|       +--------+        |    |    +--------+      |
		|                         |    |                    |
		|                         |    |                    |
	+--------+                  +--------+             +---------+
	| lValue |                  | xValue |             | prValue |
	+--------+                  +--------+             +---------+

							______ ______
						   /      X      \
						  /      / \      \
						 |   l  | x |  pr  |
						  \      \ /      /
						   \______X______/
						   |  gl  |   r  |
						   ---------------
/************************************************************************/


class MyClass
{
	string name;
public:
	// The expression move(some_name)  is an xvalue, because move returns
	// an rvalue reference (string&&). 
	// Every xvalue is also both a glvalue and an rvalue.
	MyClass(string some_name) : name(move(some_name)) { }
	string& originalName() { return name; }
	string copyOfName() const { return name; }
};

int main(void)
{
	{
	/************************************************************************
	LVALUES:
	An lvalue is an expression that refers to a memory location and allows
	us to take the address of that memory location via the & operator.
	************************************************************************/
		int i = 42;
		i = 43;				// Ok, i is an lvalue
		int* p = &i;		// Ok, i is an lvalue

		int& foo();
		foo() = 42;			// Ok, foo() is an lvalue
		int* p1 = &foo();	// Ok, foo() is an lvalue

	/************************************************************************
	RVALUES:
	An rvalue is an expression that is not an lvalue.
	************************************************************************/
		int foobar();
		int j = 0;
		j = foobar();			// Ok, foobar() is an rvalue
		//int* p2 = &foobar();	// ERROR, cannot take the address of an rvalue
		j = 42;					// Ok, 42 is an rvalue
	}
	{
		class A
		{
			public:
				A(){}
				~A(){}
			private:
		};

		A a;
		A& a_ref1 = a;  // an lvalue reference

		// An rvalue reference is formed by placing an && after some type.
		A a1;
		//A&& a_ref2 = a1;  // an rvalue reference

		// An rvalue reference behaves just like an lvalue reference except that 
		// it can bind to a temporary(an rvalue), whereas you can not bind 
		// a(non const) lvalue reference to an rvalue.
		A&  a_ref3 = A();  // Error!
		A&& a_ref4 = A();  // Ok
	}

	{
		MyClass temp("Nishith");
		// Below expression is is an prvalue. copyOfName() returns an object 
		// (string), not a reference. 
		// Every prvalue is also an rvalue. (Rvalues are more general.)
		string aString = temp.copyOfName();

		// Below expression is is an lvalue. originalName() returns an 
		// lvalue reference (string&). 
		// Every lvalue is also a glvalue. (Glvalues are more general.)
		temp.originalName() = "Jain";
	}
}
int foobar(void) { return 10; }
int& foo(void) { return globalI; }