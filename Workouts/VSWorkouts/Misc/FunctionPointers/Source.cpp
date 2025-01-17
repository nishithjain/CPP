#include <iostream>
#include <stdlib.h>
using namespace std;

// Function pointer
typedef int* (*funPtr)(float, double);
// Global Variables
int gVariable1 = 100;
int gVariable2;
char cstring[10] = "Hello";
char* cptr = "Hello World";

int* aFunction(float x, double d)
{
	int *ptr = new int;
	*ptr = static_cast<int>(x)+static_cast<int>(d);
	return ptr;
}

void function1(void)
{
	int j = 5;
	j++;
	cout << "Value of J: " << j << endl;
	int local_To_Function1;
	int *iptr;
	iptr = (int *)malloc(sizeof(int));
	free(iptr);
}

int main(void)
{
	{
		funPtr x; // x is function pointer
		x = aFunction;
		int* anotherPtr = x(10.5, 11.6);

		cout << "Value returned: " << *anotherPtr << endl;
		delete anotherPtr;
	}
	{
		function1();
		function1();
		cstring[2] = 'N';
		cout << "cString :" << cstring << endl;
		//cptr[2] = 'k';
		cptr = "Nishith Jain";
		cout << "Value @ CPTR: " << cptr << endl;
	}


	return 0;
}