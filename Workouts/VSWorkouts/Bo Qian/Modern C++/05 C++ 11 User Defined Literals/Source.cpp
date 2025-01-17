#include <iostream>
using namespace std;

/*********************************************
			User Defined Literals
What are literals>
	- Literals are constants
C++ has 4 kinds of literals...
1. Integer Literal			-	4
2. Floating Point Literal	-	4.5
3. Character Literal		-	'z'
4. String Literal			-	"Hello"

Literals can have suffix to specify the exact type...
	45;		// int
	45u;	// unsigned int
	45l;	// long

*** User defined literals allows us to define our own suffix ***
But why do we want to do that?
Look at the examples...
**********************************************/

#pragma region Problem

//int main(void)
//{
//	// C++99
//	// height is Meter? Centimeters? Inches? If it is a big 
//	// project, we have to look 1000s of line to figure it out
//	// whether height is in meters or centimeters or in inches.
//	long double height = 3.4;	
//
//	//Ideally, we would have done like this
//	// height = 3.4cm;
//	// ratio = 3.4cm / 2.1mm => ration = 3.4*10/2.1
//	
//	return 0;
//}

#pragma endregion Problem

#pragma region Example 1

//// User defined literals
//// operator"" means, it is the declaration of USER DEFINED LITERALS
//// _cm, _m and _mm means the suffice. Both centimeter and meter will
//// be translated to millimeter.
//// Visual Studio 2013 doesn't support USER DEFINED LITERALS
//// constexpr make the calculation to happen at compile time!!!
//// constexpr is not supported by Visual Studio 2013
//constexpr long double operator"" _cm(long double x) { return x * 10; }
//constexpr long double operator""_m(long double x) { return x * 1000; }
//constexpr long double operator""_mm(long double x) { return x; }
//
//int main(void)
//{
//	long double height = 3.4_cm;
//
//	cout << height << endl;				// Prints 34
//	cout << (height + 13.0_m) << endl;	// Prints 13034
//	cout << (130.0_mm / 13.0_m) << endl;// Print 0.01
//
//	return 0;
//}

#pragma endregion Example 1

#pragma region Example 2
// String representation of binary number into integer!!!
int operator""_bin(const char*, size_t l)
{
	int ret = 0;
	for (int i = 0; i < l; ++i)
	{
		ret = ret << 1;
		if (str[i] == '1')
			ret += 1;
	}
	return ret;
}

int main(void)
{
	cout << "110"_bin << endl;					// 6
	cout << "1100110"_bin << endl;				// 102
	cout << "110100010001001110001"_bin << endl;// 1712753

	return 0;
}

#pragma endregion Example 2

#pragma region Restriction

/*********************************************
User Defined Literals can work only with the
following parameters...

char const*
unsigned long long
long double
char const*, std::size_t
wchar_t const*, std::size_t
char16_t const*, std::size_t
char32_t const*, std::size_t

Return value can be of any type
//**********************************************/

#pragma endregion Restriction
