#include <iostream>
#include <string>
#include <memory>

using namespace std;

/*********************************************
		Shared Pointer
**********************************************/

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

#pragma region Problem

//void foo(void)
//{
//	Dog*p = new Dog("Gunner");
//	//...
//	//delete p;
//	//...
//	p->bark();	// p is a dangling pointer if we delete the Dog early - Undefined behavior
//} // If we forget to delete the Dog, then there is memory leak!!!

#pragma endregion Problem

#pragma region Solution
//void foo(void)
//{
//	shared_ptr<Dog>p(new Dog("Gunner"));	// Count == 1
//
//	{
//		shared_ptr<Dog> p2 = p;	// Count == 2
//		p2->bark();
//		// To print the count. 
//		// Notice that to use object members we use ->
//		// and to use shared_ptr members we use '.'
//		cout << p.use_count() << endl;
//	}// Count == 1
//
//	p->bark();
//}	// Count == 0
//
//int main(void) 
//{ 
//	foo();
//	/*********************************************
//	An object should be assigned to a smart pointer 
//	as soon as it is created. Raw pointer should not
//	be used again.
//	Example: 
//	{// Pitfall
//	Dog* d = new Dog("Tank");
//	shared_ptr<Dog> p(d);	// p.use_count() == 1
//	shared_ptr<Dog> p2(d);	// p2.use_count() == 1
//	}// CRASH
//	**********************************************/
//	{
//		// We are creating an object but not assigning to smart pointer.
//		// This is incorrect way of using smart pointer
//		Dog* d = new Dog("Tank");	
//		// We are using raw pointer again here. This is incorrect way of
//		// using smart pointer.
//		shared_ptr<Dog> p(d);	// p.use_count() == 1
//		shared_ptr<Dog> p2(d);	// p2.use_count() == 1
//	}// CRASH
//
//	return 0; 
//}
#pragma endregion Solution

#pragma region make_shared

void foo(void)
{
	// make_shared is FASTER and SAFER!!! Exception safe!!!
	shared_ptr<Dog> ptr = make_shared<Dog>("Bruce");

/*********************************************
Use make_shared instead of new. What happens if
we use new?
Two steps in creating a shared pointer...
1. "Gunner" is created.
2. p is created with Dog "Gunner".

Also,
- What if "Gunner" has been created successfully
and the make_shared has failed?
Answer: Dog "Gunner" will be created but not managed
by share pointer. Memory will be leaked!!!
**********************************************/
	shared_ptr<Dog>p(new Dog("Gunner"));	// Not exception safe
	p->bark();
}

int main(void) 
{ 
	foo();

	// Also we can use below mentioned cast operators to cast smart pointers
	// static_pointer_cast
	// dynamic_pointer_cast
	// const_pointer_cast

	return 0; 
}
#pragma endregion make_shared