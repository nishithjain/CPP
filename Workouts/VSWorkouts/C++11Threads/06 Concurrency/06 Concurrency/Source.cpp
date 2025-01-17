#include <iostream>
#include <thread>

using namespace std;
/************************************************************************
					Transferring ownership of a thread
************************************************************************/

/************************************************************************
	- Many resource-owning types in the C++ Standard Library such as 
	std::ifstream and std::unique_ptr are movable but not copyable, and 
	std::thread is one of them. This means that the ownership of a particular 
	thread of execution can be moved between std::thread instances.
************************************************************************/
void someFunction()
{
	cout << "Inside someFunction\n";
}
void someOtherFunction()
{
	cout << "Inside someOtherFunction\n";
}

void f(std::thread t)
{
	cout << "Nothing to do here\n";
	if (t.joinable())
		t.join();
}
void g()
{
	f(std::thread(someFunction));
	std::thread t(someFunction);		
	f(std::move(t));
}

int main(void)
{
	std::thread oneThread(someFunction);			// Creating a thread instance.
	std::thread twoThread = std::move(oneThread);	// Moving the ownership to another thread instance.
	oneThread = std::thread(someOtherFunction);		// Now oneThread no longer has an associated thread of execution.
	std::thread threeThread;
	threeThread = std::move(twoThread);				// Moving the ownership to another thread instance.
	//oneThread = std::move(threeThread);			// oneThread already had an associated thread, 
													// so std::terminate() is called to terminate the program.
	oneThread.join();
	threeThread.join();
	g();
	return 0;
}