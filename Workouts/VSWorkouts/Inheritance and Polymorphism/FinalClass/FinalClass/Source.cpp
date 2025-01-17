#include <iostream>
using namespace std;

/************************************************************************
	final Keyword
	- Specifies that a virtual function can not be overridden in a 
	derived class or that a class cannot be inherited from.
************************************************************************/
class BaseClass
{
public:
	virtual void foo() final { cout << "In Class BaseClass" << endl; };		// BaseClass::foo is final
	//void bar() final;														// Error: non-virtual function cannot be final
};

class DerivedClass final : public BaseClass									// class DerivedClass is final
{
public:
	//void foo();															// Error: foo cannot be overridden as it's final in BaseClass
	void function(void){ cout << "In Class DerivedClass" << endl; }
};

//class DerivedFormDerivedClass : public DerivedClass						// Error: DerivedClass is final
//{
//public:
//	void function(void) { cout << "In Class DerivedFormDerivedClass" << endl; }
//};

int main(void)
{
	BaseClass b;
	b.foo();
	DerivedClass d;
	d.foo();
	d.function();
	return 0;
}