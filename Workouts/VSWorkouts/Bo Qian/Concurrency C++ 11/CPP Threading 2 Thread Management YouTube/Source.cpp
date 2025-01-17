#include <iostream>
#include <thread>

using namespace std;

/*************************************************************
Thread Management
- We know that a thread can either be joined or detached. But
what about the thread which is neither joined nor detached?
Answer: If a thread is neither joined nor detached or if the 
thread object is destroyed before the thread is joined or detached,
the program will TERMINATE!!!
**************************************************************/

void function_1(void)
{
	cout << "Hello from thread!!!" << endl;
}

class functor
{
public:
	void operator()()
	{
		for (int i = 0; i >= -100; i--)
		{
			cout << "From t1 " << i << endl;
		}
	}
};


int main(void) 
{ 

	thread t1(&function_1);
#pragma region CRASH
	/* The below code will crash. This is because while the main
	thread is doing something, t1 has already finished the job and
	the t1 object is destroyed before it is joined. So it will throw an
	exception.
	*/
	//	for (int i = 0; i < 100; i++)
		//	cout << "From main :" << i << endl;
#pragma endregion CRASH

#pragma region Solution 1
	//try
	//{
	//	for (int i = 0; i < 100; i++)
	//	cout << "From main :" << i << endl;
	//}
	//catch (...)
	//{
	//	t1.join();
	//	throw;
	//}
#pragma endregion Solution 1

	/*
	Alternative approach is using RAII.
	We can create a wrapper class that wraps around t1. In the 
	destructor of the wrapper class, will call the t1.join(). When the 
	wrapper object goes out of scope, it will automatically join the
	thread.
	*/

	/*
	We can also create thread using any callable object such as functor,
	lambda expression...
	*/
	functor fct;	
	thread t2(fct);
	
	/*
	// Get the ID of the thread
	cout << std::this_thread::get_id() << endl;
	Thread is a movable object
	//thread t3 = t1;	// will not compile.
	thread t4 = std::move(t1);
	t4.join();
	cout << thread::hardware_concurrency();
	*/

	t2.join();
	t1.join();
	return 0; 
}