#include <iostream>
using namespace std;

class X 
{
	static const int m1 = 7;	        // ok
	const int m2 = 7;                	// error: not static
	//static int m3 = 7;				// error: not const
	//static const int m4 = var;       	// error: initializer not constant expression
	//static const string m5 = "odd";	// error: not integral type
};

class myClass 
{
public:
	myClass() : a(7), b(5), hash_algorithm("MD5"), s("class A example") {}
	myClass(int a_val) : a(a_val), b(5), hash_algorithm("MD5"), s("Constructor run") {}
	int a, b;
private:
	string hash_algorithm;
	string s;
};

class anotherClass 
{
public:
	anotherClass() : a(7), b(5) {}
	anotherClass(int a_val) : a(a_val), b(5) {}
	int a, b;
private:
	string hash_algorithm = "MD5";		// Non-static data member initializer
	string s = "Constructor run";		// Non-static data member initializer
};

int main(void)
{
	return 0;
}