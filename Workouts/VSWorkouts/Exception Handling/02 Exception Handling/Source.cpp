#include <exception>
#include <iostream>

/*******************************************************
	- Wrap code that might throw an exception in a try block.
	- Try/catch as close to the problem as possible.
	- Add one or more catch blocks after the try.
	- Catch more specific exceptions first.
	- Catch exceptions by reference.
	- Standard Library includes an exception class.-----------------|
********************************************************			|
																	|			*/						
double divideTwoInts(int a, int b)//								|------->	/******************************************/
{																				//std::exception
	if (0 == b)																	//	logic_error
		throw std::invalid_argument("Argument b is ZERO!!!");					//		invalid_argument
	return static_cast<double>(a / b);											//		domain_error
}																				//		length_error
																				//		out_of_range
double aFunction(int a, int b)													//		future_error(C++11)
{																				//	runtime_error
	return divideTwoInts(a, b);													//		range_error
}																				//		overflow_error
																				//		underflow_error
double bFunction(int a, int b)													//		regex_error(C++11)
{																				//		system_error(C++11)
	return aFunction(a, b);														//		ios_base::failure(since C++11)
}																				//	bad_typeid
																				//	bad_cast
double cFunction(int a, int b)													//	bad_weak_ptr(C++11)
{																				//	bad_function_call(C++11)
	return bFunction(a, b);														//	bad_alloc
}																				//		bad_array_length(C++14)
																				//		bad_array_new_length(C++11)
int main(void)																	//	bad_exception
{																				//	ios_base::failure(until C++11)
	int a = 10;																	/******************************************/
	int b = 0;
	try
	{
		cFunction(a, b);
	}
	catch (std::invalid_argument& e)	// Catch the exception polymorphically by reference.
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::exception& e)			// Catching more generic exception
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}