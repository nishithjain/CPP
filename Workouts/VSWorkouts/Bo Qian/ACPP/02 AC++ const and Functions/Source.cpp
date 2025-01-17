#include <iostream>
#include <string>

using namespace std;

class Dog
{
private:
	int _age;
	string _name;
public:
	Dog() { _age = 3; _name = "Bruce"; }

	// const parameters
	/* Function which take reference parameter can be overloaded with the
	function which takes const reference parameter.
	*/
	void setAge(const int& a) { _age = a; }	// So that a doesn't get modified.
	// void setAge(const int a) { _age = a; } // No use of const here, cos value is passed by value

	// const return value
	/* Returns const string reference. No copy is made and the 
	caller can't change the value of _name */
	const string& getName() { return _name; }
	/* Below, const is completely useless. Because _name is returned
	by value. */
	// const string getName() { return _name; }

	// const function
	/*
	- Below function promises not to modify any member variables. 
	- A const function can only call another const function.
	- const can be used to overload a function
	*/
	// Below function will be called by const Dog
	void printDogName() const { cout << _name << ":: const function" << endl; }
	// Below function will be called by Non-const Dog
	void printDogName() { cout << _name << ":: Non-const function" << endl; }
};


int main(void)
{
	Dog d;

	int i = 9;
	d.setAge(i);
	const string& name = d.getName();

	cout << i << endl;
	cout << name << endl;
	d.printDogName();

	const Dog d1;
	d1.printDogName();

	return 0;
}