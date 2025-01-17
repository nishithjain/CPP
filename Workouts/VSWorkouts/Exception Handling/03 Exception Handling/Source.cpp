#include <iostream>
#include <exception>
#include <memory>
/************************************************************************
								RAII
************************************************************************/

class MyClass
{
public:
	MyClass(int a) : _a(a) { std::cout << "Inside Constructor" << std::endl; }
	~MyClass() { std::cout << "Inside Destructor" << std::endl; }

private:
	int _a;
};

void functionWhichThrows(void)
{
	throw std::out_of_range("Simply Throwing Out Of Range!!!");
}

void withoutRAII(void)
{
	try 
	{
		auto x = new MyClass(10); 
		//risky stuff 
		functionWhichThrows();
		delete x; 
	} 
	catch (std::exception& e) 
	{
		std::cout << "withoutRAII:: Inside catch!!!" << std::endl;
	}
}

void withRAII(void)
{
	try
	{
		auto x = std::make_shared<MyClass>(10);
		functionWhichThrows();
	}
	catch (std::exception& e)
	{
		std::cout << "withRAII:: Inside catch!!!" << std::endl;
	}
}

int main(void)
{
	std::cout << "*****************************\n";
	withoutRAII();
	std::cout << "*****************************\n";
	withRAII();
	std::cout << "*****************************\n";
	return 0;
}