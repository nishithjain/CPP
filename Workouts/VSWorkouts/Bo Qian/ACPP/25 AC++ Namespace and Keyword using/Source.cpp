#include <iostream>
#include <string>


/************************************************************************
					Namespace and Keyword using
1. using directive : to bring all namespace members into current scope
		Example: using namespace std;
	* using directive can only work with namespace.
2. using declaration
	a. Bring one specific namespace member to current scope.
	b. Bring a member from base class to current class's scope.
		Example: using std::cout;
	* using declaration can work with class or with namespace.
	* using declaration for class can be using in class scope only!!!
************************************************************************/

class B 
{
public:
	int fun(int x) 
	{
		using namespace std;	// Local scope
		cout << "From B" << endl;
		return x; 
	}
};
class D :private B
{
public:
	void g()
	{
		using namespace std;	// Local scope
		cout << "From D" << endl;
	}

	void h()
	{
		using std::cout;
		using std::endl;
		cout << "From D" << endl;
	}
	void fun(void) 
	{
		using std::cout;
		using std::endl;
		cout << "From D" << endl;
	}
	using B::fun;	// Class scope
	//using namespace std;	// Illegal
	//using std::cout;		// Illegal
};

namespace //Anonymous namespace
{
	void h() { std::cout << "From h\n"; }
}

int main(void)
{
	D d;
	//d.fun(8); Initially this will not compile because of name hiding
	d.fun(9);	// After using B::fun; this will compile

	// Can only be called within this file. Similar to global static h()
	h();
	return 0;
}