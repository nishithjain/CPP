#include <iostream>
#include <string>
#include <memory>

using namespace std;
class Dog
{
public:
	string name_;
	Dog(string name) : name_(name) { cout << "Dog is created: " << name << endl; }
	Dog() { cout << "Nameless dog created: " << endl; name_ = "nameless"; }
	~Dog() { cout << "Dog is destroyed: " << name_ << endl; }
	void bark(void){ cout << "Dog " << name_ << " rules!" << endl; }
};

/*********************************************
Unique Pointer:
It represents exclusive ownership of an object.
One object can only be owned by one pointer and when
that one pointer goes out of scope or some other object
is assigned to the unique pointer, the old object is 
deleted!!!.
Unique pointer is light weight smart pointer
**********************************************/

#pragma region unique_ptr Example 1
//void test()
//{
//	{
//		unique_ptr<Dog> pD(new Dog("Gunner"));
//		pD->bark();
//		// Raw pointer for unique_ptr. release() function 
//		// returns the raw pointer from unique_ptr similar
//		// to get() function of shared_ptr
//		// After the pD.release(), pD has given up the ownership
//		// of the Dog and as the result nobody owns the Dog anymore
//		// nobody is going to delete the Dog. "Gunner" is not deleted here.
//		Dog* ptr = pD.release();
//
//		// Inference is that, shared_ptr.get() doesn't give up the 
//		// ownership of the object. But the unique_ptr.release() 
//		// function gives up the ownership of the object.
//		if (!pD)
//			cout << "pD is empty!" << endl;
//	}
//	{
//		unique_ptr<Dog> pD(new Dog("Gunner"));
//		// Gunner is destroyed when we call reset() function
//		// because pD starts to own another Dog
//		pD.reset(new Dog("Smokey"));
//		pD.reset();	// Reseting pD to nullptr
//		if (!pD)
//			cout << "pD is empty!" << endl;
//		// So the unique_ptr.release() doesn't destroy the object
//		// but the unique_ptr.reset() does!!!
//	}
//}
#pragma endregion unique_ptr Example 1

#pragma region unique_ptr Example 2

//void f(unique_ptr<Dog> p)
//{
//	p->bark();
//}// Dog Gunner is destroyed here
//
//unique_ptr<Dog> getDog()
//{
//	unique_ptr<Dog> p(new Dog("Smokey2"));
//	return p;	// This will automatically use move semantics
//}
//
//void test()
//{
//	/*********************************************
//	We said unique_ptr can't share the object at the
//	same time. But they can share the object at 
//	different time.
//	**********************************************/
//	unique_ptr<Dog> pD(new Dog("Gunner"));
//	unique_ptr<Dog> pD2(new Dog("Smokey"));
//	pD2->bark();
//	/*******************************
//	1. Smokey is destroyed.
//	2. pD becomes empty.
//	3. pD2 owns Gunner.
//	********************************/
//	pD2 = move(pD);
//	pD2->bark();
//
//	f(move(pD2));
//	if (!pD2)
//		cout << "pD2 is empty" << endl;
//
//	unique_ptr<Dog> pdd = getDog();
//	// With shared_ptr, we provided the custom deleter, but with
//	// unique_ptr, we need not provide.
//	//shared_ptr<Dog> arrofDog(new Dog[3], [](Dog* p){delete[] p; });
//	// Creating array of dogs, here the template parameter is array
//	unique_ptr<Dog[]> dogd(new Dog[3]);
//}
//
//int main(void) 
//{
//	test();
//	return 0; 
//}

#pragma endregion unique_ptr Example 2

#pragma region unique_ptr as Class Member

class Bone { };

class Toy { };

class UniqueDog
{
	// This is the old way of managing resource. 
	// In the constructor, lets say we created new Bone() and assigned
	// the object to pBone pointer. But in the rest of the constructor,
	// an exception is thrown. This means, the object of UniqueDog is
	// not created successfully so the destructor will not be called.
	// Observe that, we have created the Bone object successfully, but
	// the same Bone object, we are destroying it in the destructor.
	// Since the destructor is not called, Bone's memory is leaked.
	Bone* pBone_;
	// Its better to use unique_ptr instead of Raw pointer as a class member.
	unique_ptr<Toy> pToy_;
public:
	string name_;
	UniqueDog(string name) : name_(name) { cout << "Dog is created: " << name << endl; }
	UniqueDog() : pToy_(new Toy())	// Initializing unique_ptr
	{ 
		pBone_ = new Bone();
		cout << "Nameless dog created: " << endl; name_ = "nameless"; 
	}
	~UniqueDog() 
	{ 
		delete pBone_;
		cout << "Dog is destroyed: " << name_ << endl; 
	}

	void bark(void){ cout << "Dog " << name_ << " rules!" << endl; }
};

#pragma endregion unique_ptr as Class Member
