#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

/************************************************************************
					Running threads in the background
************************************************************************/

/************************************************************************
	- Calling detach() on a std::thread object leaves the thread to run in
	the background, with no direct means of communicating with it. Its no 
	longer possible to wait for that thread to complete; if a thread becomes 
	detached, it isn’t possible to obtain a std::thread object that references 
	it, so it can no longer be joined.
	- Detached threads truly run in the background; ownership and control 
	are passed over to the C++ Runtime Library, which ensures that the resources 
	associated with the thread are correctly reclaimed when the thread exits.
	- Detached threads are often called daemon threads after the UNIX concept of a
	daemon process that runs in the background without any explicit user interface.
************************************************************************/
void independentThread()
{
	std::cout << "Starting concurrent thread.\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Exiting concurrent thread.\n";
}

void threadCaller()
{
	std::cout << "Starting thread caller.\n";
	std::thread t(independentThread);
	t.detach();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Exiting thread caller.\n";
}

int main(void)
{
	threadCaller();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	return 0;
}