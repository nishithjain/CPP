#include <iostream>
#include <mutex>
#include <string>
#include <memory>

using namespace std;

/************************************************************************
				Resource Acquisition is Initialization
mutex myMutex = MUTEX_INITIALIZER;
void aFunction(void)
{
	myMutex.lock();
	// Do a bunch of things
	myMutex.unlock();	// Will this line always be executed????
}
************************************************************************/

#pragma region Example 1
class Lock
{
private:
	mutex* myMutex;
public:
	explicit Lock(mutex* ptr)
	{ 
		// Lock the mutex here
	}
	~Lock() 
	{
		// Unlock the mutex here
	}
};
/************************************************************************
	- The only code that can be guaranteed to be executed after exception
is thrown are the destructor's of the objects residing on stack.
	- Resource management therefore needs to be tied to the lifespan of 
suitable objects in order to gain automatic deallocation and reclamation.
************************************************************************/
#pragma endregion Example 1


#pragma region Example 2
class Dog
{
public:
	int age;
	string name;
};
void aFunction()
{
	// A shared pointer is reference counted smart pointer.
	// shared pointer is destroyed when the reference count reaches zero.
	shared_ptr<Dog> ptrDog(new Dog);
}
#pragma endregion Example 2


int main(void)
{
	return 0;
}