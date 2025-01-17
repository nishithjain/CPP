#include <iostream>
#include <thread>
#include <string>
#include <future>

/************************************************************************
Passing the value and receiving the same from threads.
Future and Promise are communication channel between 2 threads...
Input side of the channel - Promise.
Output side of the channel - Future.

1.	First we create a promise. Promise is a template. It is parametrized 
	by the values that will be passed between threads.
2.	A shared state is allocated when we create a promise. This is the state 
	where the value will be stored. 
3.	Next step is to obtain the future from the promise. At this point the 
	shared state is shared between future and promise. And the shared state
	is reference counted. This means, when future and promise goes out of 
	scope, the shared state will be reclaimed.
4.	Shared state can also be used to pass exceptions.
5.	Next step is to create a thread and pass the promise to the thread. 
	Remember, promise is the input end of the channel so it goes to thread B. 
	Future is the output end of the channel it stays with thread A.
6.	The shared state is shared between the two threads and the synchronization 
	is provided by the system.
7.	Next is...Either promise sets the value or future tries to get the value. 
	If the future tries to get the value before promise sets, the future 
	is blocked!!! and it waits until promise sets the value.
************************************************************************/

void threadFunction(std::promise<std::string>& thePromise)
{
	std::string str("Hello from the future");
	thePromise.set_value(str);
}

int main(void)
{
	std::promise<std::string> thePromise;
	std::future<std::string> theFuture = thePromise.get_future();

	std::thread theThread(&threadFunction, std::ref(thePromise));
	std::cout << "Hello from main\n";

	std::string str = theFuture.get();
	std::cout << str << std::endl;

	theThread.join();

	return 0;
}