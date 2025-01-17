#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

/************************************************************************
			Spawn some threads and wait for them to finish
************************************************************************/

void printValue(unsigned id)
{
	std::cout << "Printing value :" << id << std::endl;
}

void aFunction()
{
	std::vector<std::thread> threads;
	for (unsigned i = 0; i < 20; ++i)
	{
		threads.push_back(std::thread(printValue, i));
	}
	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
}
int main(void)
{
	aFunction();
	return 0;
}