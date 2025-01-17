#include <iostream>
#include "string.h"
using namespace myString;

string myFunction(void)
{
	string xx("M R");
	return xx;
}

int main(void)
{
	string x("Nishith");
	string y("Jain");
	string a(x);    
	string b(myFunction());

	std::cout << "Hi";
	yourString::string xxx;

	return 0;
}