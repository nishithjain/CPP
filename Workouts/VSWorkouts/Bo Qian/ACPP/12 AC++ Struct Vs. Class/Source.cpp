#include <iostream>
#include <string>
using namespace std;

/************************************************************************
							Struct Vs. Class
	- The members of structure are public by default but for class, 
	its private. This is the only difference as far as language is concerned.

	Semantic Difference:
	- Structure is used for small passive object that carry public data 
	and have no or few basic member functions. In other words structure is
	used for data container.
	- Class is used for bigger active objects that carry private data,
	interfaced through public member functions. In other words class is
	used for more complex data structure.
************************************************************************/


struct StructPerson
{
	// Public by default
	string name;
	unsigned age;
	StructPerson(unsigned personAge = 5) : age(personAge) {}
};

class ClassPerson
{
	// Private by default
	string name_;		// Trailing underscore notation is used for naming class data members.
	unsigned age_;
public:
	// Too many getter and setter means there is some design problem.
	unsigned getAge(void) const { return age_; }	// Getter or accessors
	void setAge(unsigned age) { age_ = age; }		// Setter or mutator
};


int main(void)
{
	StructPerson aPerson;
	cout << "Person age :" << aPerson.age << endl;


	ClassPerson bPerson;
	bPerson.setAge(4);
	cout << "Person age :" << bPerson.getAge() << endl;

	return 0;
}