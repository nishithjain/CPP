#include <iostream>
#include <thread>
#include <string>
#include <future>

using namespace std;
/************************************************************************
	- When an exception is thrown from inside a thread, and is not caught
	inside the thread, the program terminates.
	- It is always a good idea to put try-catch block inside a thread.
	- Whats happening
		Inside the thread function we put a try catch block, and we throw 
		an exception and is caught in the catch block. The same exception 
		is passed through the promise.
		It comes to main thread, when we call get on the future. The exception
		is re thrown and is caught in the catch block and is printed.
************************************************************************/

void theThreadFunction(promise<string>& thePromise)
{
	try
	{
		string str("Hello from FUTURE!!!");
		throw(exception("Exception from FUTURE!!!"));
		thePromise.set_value(str);
	}
	catch (...)
	{
		thePromise.set_exception(current_exception());
	}
}

int main(void)
{
	promise<string> thePromise;
	future<string> theFuture = thePromise.get_future();
	thread theThread(&theThreadFunction, ref(thePromise));

	cout << "Hello from MAIN!!!\n";

	try
	{
		string str = theFuture.get();
		cout << str << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	theThread.join();

	return 0;
}