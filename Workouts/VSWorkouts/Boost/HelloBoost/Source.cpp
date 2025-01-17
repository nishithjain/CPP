#include <iostream>
#include <string>
using namespace std;

#include <boost\optional.hpp>
using namespace boost;

/************************************************************************
								OPTIONAL
************************************************************************/

#pragma region Optional
//class Address
//{
//public:
//	Address(string sN) : streetName(sN) {}
//	string streetName;
//};
//
//class Person
//{
//public:
//	Person(string fN, string lN) : firstName(fN), lastName(lN) { }
//
//	string firstName, lastName;
//	optional<string> middleName;
//	optional<Address> address;
//};
//
//int main(void)
//{
//	Person p{ "Nishith", "M R" };
//	
//	p.middleName = "Jain";
//
//	if (p.middleName)
//		cout << *p.middleName << endl;
//
//	p.address = Address{ "Mysore" };
//	if (p.address)
//		cout << p.address->streetName << endl;
//
//	return 0;
//}
#pragma endregion Optional

#pragma region Logger

#include "Logger.h"

class Address
{
public:
	Address(string sN) : streetName(sN) {}
	string streetName;
};

class Person
{
public:
	Person(string fN, string lN) : firstName(fN), lastName(lN) { }

	string firstName, lastName;
	optional<string> middleName;
	optional<Address> address;
};

int main(void)
{
	Person p{ "Nishith", "M R" };

	p.middleName = "Jain";

	if (p.middleName)
		cout << *p.middleName << endl;

	p.address = Address{ "Mysore" };
	if (p.address)
		cout << p.address->streetName << endl;

	//logging::add_common_attributes();

	//using namespace logging::trivial;

	//dhlogging::Logger::getInstance()->logInfo("himom");

	return 0;
}
#pragma endregion Logger