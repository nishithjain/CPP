#include <iostream>
#include <thread>

/************************************************************************
					Scoped thread and example usage
************************************************************************/

struct Functor
{
	int& i;
	Functor(int& i_) :i(i_){}
	void operator()()
	{
		for (unsigned j = 0; j < 1000000; ++j)
		{
			std::cout << "Inside Sleep Thread\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(2));
		}
	}
};

class ScopedThread
{
	std::thread t;
public:
	explicit ScopedThread(std::thread t_) : t(std::move(t_))
	{
		if (!t.joinable())
			throw std::logic_error("No thread");
	}
	~ScopedThread()
	{
		t.join();
	}
	ScopedThread(ScopedThread const&) = delete;
	ScopedThread& operator=(ScopedThread const&) = delete;
};

void doSomething(void)
{
	std::cout << "I am doing something in doSomething\n";
	for (unsigned j = 0; j < 1000; ++j)
	{
		//std::cout << "Inside Sleep Thread\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
	}
}
void doSomethingInCurrentThread()
{
	std::cout << "I am doing something\n";
}
void aFunction()
{
	int some_local_state = 10;
	ScopedThread t((std::thread(doSomething)));

	// When the initial thread reaches the end of aFunction, the ScopedThread object is
	// destroyed and then joins with the thread supplied to the constructor.
	doSomethingInCurrentThread();
}

int main(void)
{
	aFunction();
	return 0;
}