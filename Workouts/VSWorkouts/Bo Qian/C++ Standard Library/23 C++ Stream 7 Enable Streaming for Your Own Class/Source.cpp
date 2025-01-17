#include <iostream>
#include <string>
#include <ostream>
#include <istream>

using namespace std;

/************************************************************************
					Enable Streaming for Your Own Class
	- Creating stream enabled class
************************************************************************/

struct Dog
{
	int age_;
	string name_;
};

ostream& operator<<(ostream& sm, const Dog& d)
{
	sm << "My name is " << d.name_ << " and my age is " << d.age_ << endl;
	return sm;
}

istream& operator>>(istream& sm, Dog& d)
{
	sm >> d.age_;
	sm >> d.name_;
	return sm;
}

int main(void)
{	
	Dog d{ 2, "Bob" };
	cout << d;

	cin >> d;
	cout << d;

	return 0;
}