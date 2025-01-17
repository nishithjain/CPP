#include <iostream>
#include <chrono>

using namespace std;

/*************************************************************
chrono
- is the library to deal with time and date!!!
- A precision - neutral library for time and date.

Concepts needs clarification:

Clock: chrono provides 3 clocks!!!
1. System Clock - std::chrono::system_clock
				- Current time according to system and is not steady
2. Steady Clock - std::chrono::steady_clock	
				- Goes at a uniform rate.
3. High Resolution Clock - std::chrono::high_resolution_clock
				- provides smallest possible tick period.

Duration:
chrono::duration<> - represents time duration.
Example: If we want to represent "2 hours", here we need number (2) and
a unit (hours). These are the 2 things the template class duration<> needs.

duration<int, ratio<1,1>> -	Number of seconds in a int
duration<double, ratio<60,1>> - Number of minutes in a double

typedefs provided by chrono
nanoseconds, microseconds, milliseconds, seconds, minutes, hours

**************************************************************/

int main(void) 
{ 

#pragma region ratio
	//std::ratio<2, 10>r;
	//cout << r.num << "/" << r.den << endl;

	//// All the clock period is represented with ration
	//// Period of system clock
	//cout << chrono::system_clock::period::num << "/"
	//	<< chrono::system_clock::period::den << endl;	// 1/10000000
#pragma endregion ratio

	chrono::microseconds mi(2700);	// 2700 microseconds
	chrono::nanoseconds na = mi;	// 2700000 nanoseconds
	// This will not compile. Because we are converting higher resolution
	// duration to lower resolution and we might lose some data.
	//chrono::milliseconds mill = mi;

	// 700 microseconds are truncated!!!
	chrono::milliseconds mill = chrono::duration_cast<chrono::milliseconds>(mi);
	
	mi = mill + mi;	// 2000 + 2700 = 4700

	mi.count();	// 4700

	return 0; 
}