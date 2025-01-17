#include <iostream>
#include <cstddef>
#include "OperatorOverloading.h"

using namespace std;

int main(void)
{
	OperatorOverloading x(3);
	OperatorOverloading y(4);

	if (x < y)
		cout << "X is Less than Y" << endl;
	if (y>x)
		cout << "Y is Greater than X" << endl;
	if (x == y)
		cout << "X is Equal to Y" << endl;
	if (x != y)
		cout << "X is Not equal to Y" << endl;
	if (x <= y)
		cout << "X is Less than of equal to Y" << endl;

	// Calling Overloaded Unary Operator
	{
		!y;
		x.displayMyObject();
		x++;
		x.displayMyObject();
		++x;
		x.displayMyObject();
		x--;
		x.displayMyObject();
		--x;
		x.displayMyObject();
		y++;
		++y;
	}

	// Calling Overloaded Binary Operator
	{
		x.displayMyObject();
		x = x + y;
		cout << "Value of X::Count = " << x.getCount() << endl;
		x.displayMyObject();
		x++;
		x.displayMyObject();
		x = x - y;
		x.displayMyObject();
		cout << "Value of X::Count = " << x.getCount() << endl;
	}

	return EXIT_SUCCESS;
}