#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <algorithm>

/************************************************************************
					Protecting shared data with mutexes
************************************************************************/
/************************************************************************
	- In C++, we create a mutex by constructing an instance of std::mutex,
	lock it with a call to the member function lock(), and unlock it with 
	a call to the member function unlock().
	- It isn't recommended practice to call the member functions directly, 
	because this means that you have to remember to call unlock() on every
	code path out of a function, including those due to exceptions.
	- Instead, the Standard	C++ Library provides the std::lock_guard class 
	template, which implements that RAII idiom for a mutex; it locks the 
	supplied mutex on construction and unlocks it on destruction, thus 
	ensuring a locked mutex is always correctly unlocked.
************************************************************************/

struct Counter
{
	int value;
	Counter() : value(0) { }
	void increment() 
	{ 
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
		++value; 
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
	}
	void decrement()
	{
		--value;
	}
};

struct ConcurrentSafeCounter 
{
	std::mutex mutex;
	Counter counter;

	void increment()
	{
		std::lock_guard<std::mutex> guard(mutex);
		counter.increment();
	}

	void decrement()
	{
		std::lock_guard<std::mutex> guard(mutex);
		counter.decrement();
	}
};

int main(void)
{
	while (0)
	{
		Counter counter;
		std::vector<std::thread> threads;
		for (int i = 0; i < 5; ++i)
		{
			threads.push_back(std::thread([&counter]() {	// This is a LAMBDA expression
				for (int i = 0; i < 100; ++i)
				{
					counter.increment();
				}
			}
			));
		}

		for (auto& forEachThread : threads)
		{
			forEachThread.join();
		}

		std::cout << counter.value << std::endl;
	}


	while (1)
	{
		ConcurrentSafeCounter counter;
		std::vector<std::thread> threads;
		for (int i = 0; i < 5; ++i)
		{
			threads.push_back(std::thread([&counter]() {	// This is a LAMBDA expression
				for (int i = 0; i < 100; ++i)
				{
					counter.decrement();
					counter.increment();
				}
			}
			));
		}

		for (auto& forEachThread : threads)
		{
			forEachThread.join();
		}

		std::cout << counter.counter.value << std::endl;
	}

	return 0;
}