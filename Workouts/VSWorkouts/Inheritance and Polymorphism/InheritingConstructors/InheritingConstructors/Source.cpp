#include <iostream>
#include <string>
using namespace std;

/************************************************************
	NOTE: This code doesn't work in Visual Studio 2013 as the 
	"InheritingConstructors" feature is not supported.
/************************************************************/
class Base
{
public:
	int _x;
	string _y;
	explicit Base(int x, string y) : _x(x), _y(y){ }
	~Base(){};
};

class Derived : public Base
{
public:
	using Base::Base;
	~Derived() {}
	int _x;
	string _y;
};

int main(void)
{
	Base b(9, "Nishith Jain M R");
	Derived d(10, "Hello");

	cout << "Value of Base::b._x = " << b._x << endl;
	cout << "Value of Base::b._y = " << b._y << endl;
	cout << "Value of Derived::d._x = " << d.Base::_x << endl;
	cout << "Value of Derived::d._y = " << d.Base::_y << endl;

	return 0;
}
/***************OUTPUT*****************
Value of Base::b._x = 9
Value of Base::b._y = Nishith Jain M R
Value of Derived::d._x = 10
Value of Derived::d._y = Hello
***************************************/