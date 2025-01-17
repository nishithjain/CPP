#include <iostream>
using namespace std;

class VirtualBaseA	
{ 
public: 
	VirtualBaseA(){ cout << "VirtualBaseA\n"; }
	~VirtualBaseA(){ cout << "~VirtualBaseA\n\n"; }

};

class NonVirtualClass1
{
public:
	NonVirtualClass1(){ cout << "NonVirtualClass1\n"; }
	~NonVirtualClass1(){ cout << "~NonVirtualClass1\n"; }
};

class NonVirtualClass2
{
public:
	NonVirtualClass2(){ cout << "NonVirtualClass2\n"; }
	~NonVirtualClass2(){ cout << "~NonVirtualClass2\n"; }
};

class DataMember1
{
public:
	DataMember1(){ cout << "DataMember1\n"; }
	~DataMember1(){ cout << "~DataMember1\n"; }
};

class DataMember2
{
public:
	DataMember2(){ cout << "DataMember2\n"; }
	~DataMember2(){ cout << "~DataMember2\n"; }
};

class VirtualB : virtual VirtualBaseA
{
public:
	VirtualB(){ cout << "VirtualB\n"; }
	~VirtualB(){ cout << "~VirtualB\n"; }
};

class VirtualC : virtual VirtualBaseA
{
public:
	VirtualC(){ cout << "VirtualC\n"; }
	~VirtualC(){ cout << "~VirtualC\n"; }
};

class MostDerived : VirtualB, VirtualC, NonVirtualClass1, NonVirtualClass2
{
public:
	DataMember1 a;
	DataMember2 b;
	MostDerived(){ cout << "MostDerived\n\n"; }
	~MostDerived(){ cout << "~MostDerived\n"; }
};

int main(void)
{
	cout << "##############Constructing##############\n\n";
	MostDerived s;
	cout << "##############Destructing##############\n\n";
	return 0;
}

/*
##############Constructing##############

VirtualBaseA
VirtualB
VirtualC
NonVirtualClass1
NonVirtualClass2
DataMember1
DataMember2
MostDerived

##############Destructing##############

~MostDerived
~DataMember2
~DataMember1
~NonVirtualClass2
~NonVirtualClass1
~VirtualC
~VirtualB
~VirtualBaseA
*/