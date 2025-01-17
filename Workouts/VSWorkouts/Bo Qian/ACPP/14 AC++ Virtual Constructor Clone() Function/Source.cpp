#include <iostream>

// Co-variant return type
using namespace std;

#pragma region TheProblem
//class Dog
//{
//public:
//	Dog(){ cout << "Inside Dog constructor" << endl; }
//
//};
//
//class Yellowdog : public Dog
//{
//public:
//	Yellowdog(){ cout << "Inside Yellow dog constructor" << endl; }
//};
//
//// What afunction  gets is an yellow dog.
//void aFunction(Dog* d)
//{
//	// Because of copy construction, c will become a dog.
//	Dog* c = new Dog(*d);
//	//...
//	// Play with dog c
//}
//
//int main(void)
//{
//	Yellowdog d;
//
//	aFunction(&d);
//
//	return 0;
//}
#pragma endregion TheProblem

#pragma region Solution
class Dog
{
public:
	Dog(){ cout << "Inside Dog constructor" << endl; }
	// Co-variant return type
	virtual Dog* clone(){ return (new Dog(*this)); }

};

class Yellowdog : public Dog
{
public:
	Yellowdog(){ cout << "Inside Yellow dog constructor" << endl; }
	// Co-variant return type
	virtual Yellowdog* clone(){ return (new Yellowdog(*this)); }
};

// What afunction  gets is an yellow dog.
void aFunction(Dog* d)
{
	// Because of copy construction, c will become a dog.
	//Dog* c = new Dog(*d);
	Dog* c = d->clone();
	//...
	// Play with dog c
}

int main(void)
{
	Yellowdog d;

	aFunction(&d);

	return 0;
}
#pragma endregion Solution
