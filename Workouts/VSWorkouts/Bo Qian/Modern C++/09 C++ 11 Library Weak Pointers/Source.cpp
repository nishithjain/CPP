#include <iostream>
#include <string>
#include <memory>

using namespace std;

#pragma region Cyclic Reference

//class Dog
//{
//	shared_ptr<Dog> mpFriend_;
//public:
//	string name_;
//
//	Dog(string name) : name_(name) { cout << "Dog is created: " << name << endl; }
//	Dog() { cout << "Nameless dog created: " << endl; name_ = "nameless"; }
//	~Dog() { cout << "Dog is destroyed: " << name_ << endl; }
//
//	void bark(void){ cout << "Dog " << name_ << " rules!" << endl; }
//	void makeFreind(shared_ptr<Dog> f)
//	{
//		mpFriend_ = f;
//	}
//};
//
//int main(void) 
//{
//	shared_ptr<Dog> pD(new Dog("Gunner"));
//	shared_ptr<Dog> pD2(new Dog("Smokey"));
//
//	pD->makeFreind(pD2);
//	pD2->makeFreind(pD);
//
//	return 0; 
//}

#pragma endregion Cyclic Reference

/*********************************************
weak_ptr:
	- We know shared_ptr provides shared ownership
of the object.
	- weak_ptr doesn't owns the object. Its not
the business of weak_ptr to delete the object.
	- weak_ptr is just similar to raw pointer with
one level of protection. The protection is that 
nobody can do delete on weak_ptr.
**********************************************/
class Dog
{
	weak_ptr<Dog> mpFriend_;
public:
	string name_;

	Dog(string name) : name_(name) { cout << "Dog is created: " << name << endl; }
	Dog() { cout << "Nameless dog created: " << endl; name_ = "nameless"; }
	~Dog() { cout << "Dog is destroyed: " << name_ << endl; }

	void bark(void){ cout << "Dog " << name_ << " rules!" << endl; }
	void makeFreind(shared_ptr<Dog> f)
	{
		mpFriend_ = f;
	}
	

	void showFriend()
	{
		// Below code will not compile. weak_ptr can't be used
		// like regular pointer.
		//cout << "My friend is: " << mpFriend_->name_ << endl;

		/*********************************************
		In order to use it, we need to call lock(), what the lock()
		function does is, it creates a shared_ptr out of weak_ptr.
		Why it does that?
		It does that to make sure 2 things...
		1. It checks if the weak_ptr is still pointing to a valid object.
		2. It makes sure that, while it is accessing the object, the object
		will not be deleted.

		If weak_ptr is a empty pointer, lock() will throw an exception. 
		If you don't want the lock() to throw an exception we have to
		check the weak_ptr using expired()
		**********************************************/
		if (!mpFriend_.expired())
			cout << "My friend is: " << mpFriend_.lock()->name_;
		/*use_count() gives the count of shared_ptr that is pointing to the object */
		cout << ", He is owned by " << mpFriend_.use_count() << " pointers" << endl;
	}

};

int main(void)
{
	shared_ptr<Dog> pD(new Dog("Gunner"));
	shared_ptr<Dog> pD2(new Dog("Smokey"));

	pD->makeFreind(pD2);
	pD2->makeFreind(pD);
	pD->showFriend();

	return 0;
}