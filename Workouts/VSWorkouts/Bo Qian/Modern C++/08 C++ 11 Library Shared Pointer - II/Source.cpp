#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Dog
{
public:
	Dog(string name) : name_(name) { cout << "Dog is created: " << name << endl; }
	Dog() { cout << "Nameless dog created: " << endl; name_ = "nameless"; }
	~Dog() { cout << "Dog is destroyed: " << name_ << endl; }
	void bark(void){ cout << "Dog " << name_ << " rules!" << endl; }
private:
	string name_;
};

#pragma region Releasing Memory
//void foo(void)
//{
//	shared_ptr<Dog> p1 = make_shared<Dog>("Gunner");
//	shared_ptr<Dog> p2 = make_shared<Dog>("Tank");
//	//p1 = p2;		// "Gunner" will be deleted
//	//p1 = nullptr;	// "Gunner" will be deleted
//	//p1.reset();	// "Gunner" will be deleted
//}
#pragma endregion Releasing Memory

#pragma region Custom Deleter

void foo(void)
{
/*********************************************
		What is custom deleter?
- When shared_ptr (p1) goes out of scope, it will call
some delete function to delete the Dog "Gunner" and this
delete function is called the "DELETER!!!".
- By default the "DELETER" is operator 'delete'
**********************************************/
	// Below code uses default "DELETER": operator delete
	shared_ptr<Dog> p1 = make_shared<Dog>("Gunner");
/*********************************************
- Sometimes we want to use different "DELETER" and if
that is the case, we have to use the constructor of the
shared_ptr to create a shared pointer.
Example:
**********************************************/

	shared_ptr<Dog> p2 = shared_ptr<Dog>(
		/* Object */
		new Dog("Bruce"),	
		/*********************** DELETER ***********************/
		[](Dog* p){cout << "Custom Deleting" << endl; delete p; }
	);	

	// When we create an array of Dog as shown below, p3 (shared_ptr)
	// will be pointing to dog[0]. When p3 goes out of scope, only
	// dog[0] gets deleted and dog[1] and dog[2] are leaked. In this
	// case we need to use custom deleter.
	//shared_ptr<Dog> p3(new Dog[3]);
	
	// Custom deleter to delete the array of objects when p4 goes out
	// of scope
	shared_ptr<Dog> p4(new Dog[4],
		[](Dog* p){ cout << "Deleting array of DOGs!!!" << endl; delete[] p; }
		);

}

#pragma endregion Custom Deleter

int main(void) 
{ 
	foo();
	return 0; 
}