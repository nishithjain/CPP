#include <iostream>
#include <thread>

using namespace std;
/************************************************************************
	- std::thread works with any callable type, so we can pass an instance 
	of a class with a function call operator to the std::thread constructor.
************************************************************************/
void doSomething() { cout << "Inside doSomething " << endl; }
void doSomethingElse() { cout << "Inside doSomethingElse " << endl; }

class FunctionObjects
{
public:
	FunctionObjects() {};
	~FunctionObjects(){};

	void operator()() const 
	{ 
		doSomething();
		doSomethingElse();
	}

};

int main(void)
{
	{
		// The supplied function object is copied into the storage belonging to the
		// newly created thread of execution and invoked from there.
		FunctionObjects fObj;

		thread myThread{ fObj }; // Uniform Initialization Syntax
		// We can call join() only once for a given thread
		myThread.join();	// Waiting for a thread to complete
	}
	{
	// Using LAMBDA expressions to call the functions.
	std::thread my_thread([](){ doSomething(); doSomethingElse(); });
	my_thread.join();	// Waiting for a thread to complete
}
	{
		thread aThread(doSomething);
		thread bThread(doSomethingElse);
		aThread.join();	// Waiting for a thread to complete
		bThread.join();	// Waiting for a thread to complete
	}
	return 0;
}