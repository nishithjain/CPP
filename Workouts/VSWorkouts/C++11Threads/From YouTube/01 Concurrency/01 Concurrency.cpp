#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

void threadFunction(void)
{
	std::cout << "Hello\n";
}

int main(void)
{
	// Thread construct is a variadic template. The type is deduced from the arguments.
	std::thread th(threadFunction);
	std::cout << "Hello from main\n";
	th.join();

	{
		std::vector<std::thread> workerThreads;
		for (int i = 0; i < 10; ++i)
		{
			workerThreads.push_back(std::thread([i]()
			{ 
				std::cout << "Hello from thread :" << i << "\n"; 
			}));
		}

		std::cout << "Hello form Main\n";

		for_each(workerThreads.begin(), workerThreads.end(), [](std::thread& th) 
		{
			th.join(); 
		});
	}
	
	return 0;
}

