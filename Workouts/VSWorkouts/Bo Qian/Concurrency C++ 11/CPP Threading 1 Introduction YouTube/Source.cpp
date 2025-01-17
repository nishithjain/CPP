#include <iostream>
#include <thread>

using namespace std;

/*************************************************************
There are 2 kinds of concurrent programming model...
1. Multiprocessing
	- Each process has one thread running. All the processes 
	communicate to each other through the regular inter process
	communication channel such as files, pipes, message queues, 
	sockets etc...
2. Multi-threading
	- One process consists of 2 or more threads. All the threads
	communicate to each other through shared memory.

Advantages and disadvantages of these models...
1. Multi-threading:
Advantages
	- Fast to start (It is usually slow and complicated to start
	a process because the operating system needs to devote bunch
	of internal resources to manage the process.)
	- Lower overhead (Process has more overhead, one example of 
	that is, the OS needs to provide lot of protection so that
	one process will not accidentally step on to another process. 
	Another example is that communicating through shared memory is
	much faster than the IPC.
	In summary, multi-threading provides better performance than
	multiprocessing!!!
Disadvantages:
	- Difficult to implement. (There are bunch of threading 
	specific issues that needs to carefully handled).
	- Multi-threaded program can't run on distributed system.

C++11 Standard Library provides multi-threading support!!!
**************************************************************/

void function_1()
{
	cout << "Beauty is only skin-deep" << endl;
}

int main(void) 
{ 
	thread t1(function_1);	// t1 starts running
	// Main thread waits for t1 to finish
	//t1.join();

	// t1 will run freely on its own!!! t1 becomes daemon process.
	// C++ runtime library is responsible to reclaim the t1 resource.
	t1.detach();

	// We can only join or detach() thread only once
	if (t1.joinable())
	t1.join();

	return 0; 
}