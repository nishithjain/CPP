#include <exception>
#include <stdexcept>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::runtime_error;

class DivideByZeroException : public runtime_error
{
public:
	DivideByZeroException() : runtime_error("attempted to divide by zero") { }
}; 

double quotient(int numerator, int denominator)
{
	if (denominator == 0)
		throw DivideByZeroException(); 

	return static_cast<double>(numerator) / denominator;
}

int main(void)
{
	int number1;
	int number2;
	double result;

	cout << "Enter two integers (end-of-file to end): ";

	while (cin >> number1 >> number2)
	{
		try
		{
			result = quotient(number1, number2);
			cout << "The quotient is: " << result << endl;
		} 

		catch (DivideByZeroException &divideByZeroException)
		{
			cout << "Exception occurred: " << divideByZeroException.what() << endl;
		}

		cout << "\nEnter two integers (end-of-file to end): ";
	}
	cout << endl;
	return 0;
}

