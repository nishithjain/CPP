#include "Header.h"

myDLLClass::MyDllClass::MyDllClass()
{
	cout << "Inside constructor" << endl;
}

myDLLClass::MyDllClass::~MyDllClass()
{
	cout << "Inside destructor" << endl;
}

void myDLLClass::MyDllClass::justPrintHello(string passString)
{
	cout << "Your string is :" << passString << endl;
}
