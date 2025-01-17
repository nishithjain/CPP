#include <iostream>
#include <thread>


using namespace std;

/************************************************************************
					Waiting for a thread to finish
************************************************************************/
class ThreadGuard
{
	std::thread& myThread;
public:
	explicit ThreadGuard(std::thread& t_) : myThread(t_) { }
	~ThreadGuard()
	{
		// The destructor first tests to see if the std::thread object 
		// is joinable() before calling join(). This is important, because 
		// join() can be called only once for a given thread of execution, 
		// so it would therefore be a mistake to do so if the thread had 
		// already been joined.
		if (myThread.joinable()) 
		{ 
			cout << "Inside Destructor, joining the thread" << endl;
			myThread.join(); 
		}
	}
	// The copy constructor and copy-assignment operator are marked =delete 
	// to ensure that they're not automatically provided by the compiler. 
	// Copying or assigning such an object would be dangerous.
	ThreadGuard(ThreadGuard const&) = delete;
	ThreadGuard& operator=(ThreadGuard const&) = delete;
};

struct Functor
{
	int& i;
	Functor(int& i_) :i(i_){}
	void operator()()
	{
		for (unsigned j = 0; j < 1000000; ++j)
		{
			cout << "Inside Sleep Thread\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
	}
};

void doSomethingInCurrentThread(void)
{
	try
	{
		cout << "I am doing something here\n";
		throw "ABCD";
	}
	catch (...)
	{
		
	}
}

/************************************************************************
	- When the execution of the current thread reaches the end of aFunction, 
	the local objects are destroyed in reverse order of construction. 
	Consequently, the ThreadGuard object threadGuardObj is destroyed first, 
	and the thread is joined with in the destructor. This even happens if 
	the function exits because doSomethingInCurrentThread throws an exception.
************************************************************************/
void aFunction()
{
	int some_local_state = 0;
	Functor my_func(some_local_state);
	std::thread t(my_func);
	ThreadGuard threadGuardObj(t);
	doSomethingInCurrentThread();
}

int main(void)
{
	aFunction();
	return 0;
}