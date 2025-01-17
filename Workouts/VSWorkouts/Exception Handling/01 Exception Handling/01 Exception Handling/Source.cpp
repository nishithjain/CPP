#include <iostream>
using namespace std;

double Divide(int a, int b)
{
	if (b == 0)
	{
		throw "Division by zero!";
	}
	return (a / b);
}

double cFunction(int a, int b)
{
	//try
	{
		return Divide(a, b);
	}
	//catch (const char* msg)
	//{
	//	cerr << msg << endl;
	//	throw "Throwing Again";
	//}
	return -5;
}
double bFunction(int a, int b)
{
	return cFunction(a, b);
}
double aFunction(int a, int b)
{
	return bFunction(a, b);
}

int main()
{
	int x = 50;
	int y = 0;
	double z = 0;

	try 
	{
		z = aFunction(x, y);
		cout << z << endl;
	}
	catch (const char* msg) 
	{
		cerr << msg << endl;
		//cout << z << endl;
	}
	return 0;
}