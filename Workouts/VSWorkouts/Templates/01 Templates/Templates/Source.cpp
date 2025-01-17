#include <iostream>
#include <string>

using namespace std;
/************************************************************************
What is a Template?
	- A template function defines a blueprint for generating functions.
	- It's equivalent to having the compiler automatically write out 
	every instance of Max you need for every type you need.
	- Template instantiation occurs when a template function is used for a specific type of variable.
************************************************************************/

/************************************************************************
	It is better to use "class" if it is expected T will always be a class, 
	with "typename" if other types (int, char* whatever) may be expected.
************************************************************************/
template <typename T>
inline T const& Max(T const& a, T const& b)
{
	cout << "Inside \"inline T const& Max(T const& a, T const& b)\"" << endl;
	return a < b ? b : a;
}

// Template Specialization
template <>
inline char const& Max(char const& a, char const& b)
{
	cout << "Inside \"inline char const& Max(char const& a, char const& b)\"" << endl;
	return a < b ? b : a;
}

template<typename To, typename From> 
To convert(From f)
{
	To a = static_cast<To>(f);
	return a;
}

void g(double d)
{
	int i = convert<int,double>(d);	// Calls convert<int,double>(double)
	cout << "Value of i: " << i << endl;
	char c = convert<char>(d);		// Calls convert<char,double>(double)
	cout << "Value of c: " << c << endl;
	int(*ptr)(float) = convert;		// Instantiates convert<int, float>(float)
	int m = ptr(static_cast<float>(d));
	cout << "Value of m: " << m << endl;
}

int main(void)
{

	{
		int i = 39;
		int j = 20;
		cout << "Max(i, j): " << Max(i, j) << endl;

		double f1 = 13.5;
		double f2 = 20.7;
		cout << "Max(f1, f2): " << Max(f1, f2) << endl;

		string s1 = "Hello";
		string s2 = "World";
		cout << "Max(s1, s2): " << Max(s1, s2) << endl;
	}
	{
		char ch1 = 'a';
		char ch2 = 'i';
		cout << "Max(ch1, ch2): " << Max(ch1, ch2) << endl;
	}

	{
		g(98.0);
	}
	return 0;
}