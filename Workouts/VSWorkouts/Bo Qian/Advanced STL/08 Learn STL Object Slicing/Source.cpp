#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Dog
{
public:
	virtual void bark() { cout << "I don't have a name." << endl; }
};

class YellowDog : public Dog
{
	string name_;
public:
	YellowDog(string name) : name_(name) { }
	void bark() { cout << "My name is: " << name_ << endl; }
};

int main(void) 
{
#pragma region Object Slicing
	
	{
		deque<Dog> d;
		YellowDog y("Gunner");

		d.push_front(y);
		d[0].bark();
	}

#pragma endregion Object Slicing

	{
		deque<Dog*> d;
		YellowDog y("Gunner");

		d.push_front(&y);
		d[0]->bark();
	}

	return 0; 
}