#include <iostream>
#include <thread>
#include <mutex>
#include <string>

using namespace std;

/*************************************************************
Race condition and mutex
**************************************************************/

#pragma region Problem
/* Here the output of the program is a mess. Because 2 thread t1()
and main thread are racing for the resource. The resource that they 
are sharing is "cout"

What is RACE Condition?
	- A race condition is a condition where the output of the program
	depends on the relative execution order of 1 or more threads.
*/
//void function_1(void)
//{
//	for (int i = 0; i > -100; i--)
//		cout << "From t1: " << i << endl;
//}
//
//
//int main(void) 
//{ 
//	thread t1(&function_1);
//
//	for (int i = 0; i < 100; i++)
//		cout << "From main: " << i << endl; 
//
//	t1.join();
//
//	return 0; 
//}
#pragma endregion Problem


#pragma region Solution Using Mutex

mutex mu;

#pragma region Problem with Lock and Unlock
//void shared_Print(string msg, int id)
//{
//	// Locking the mutex
//	mu.lock();
//	// What if the below line of code throws an exception?
//	// mutex mu is locked for ever!!!
//	cout << msg << id << endl;
//	mu.unlock();
//}
#pragma endregion Problem with Lock and Unlock


void shared_Print(string msg, int id)
{

	// Its better not use lock and unlock directly!!!
	//mu.lock();

	// This uses RAII. Whenever guard goes out of scope, the mutex
	// mu will be automatically unlocked!!!
	lock_guard<mutex> guard(mu);

	cout << msg << id << endl;
	//mu.unlock();
}


void function_1(void)
{
	for (int i = 0; i > -100; i--)
		shared_Print("From t1: ", i);
}


int main(void) 
{ 
	thread t1(&function_1);

	for (int i = 0; i < 100; i++)
		shared_Print("From main: ", i);

	t1.join();

	return 0; 
}
#pragma endregion Solution Using Mutex

/*
Avoiding Data Race:
1. Use mutex to synchronize data access;
2. Never leak a handle of data to outside
3. Design interface appropriately.
*/