#include <iostream>
#include <chrono>

using namespace std;

/*************************************************************
time_point: we need clock and duration concepts to know time_point
	- Represents a point of time.

In oder to represent a point of time, we need a reference.
Example: 04-July-2014. From where 2014 came from? 2014 number of 
years after Jesus birth.
Similarly we need a reference to represent a point of time. In
programming world, the reference is

00:00 January 1, 1970 (Coordinated Universal Time - UTC) - Epoch of a clock

Examples:
time_point<system_clock,milliseconds> : According to system_clock, the
	elapsed time since epoch in milliseconds!!!

system_clock::time_point -> time_point < system_clock, system_clock::duration >
steady_clock::time_point -> time_point < steady_clock, steady_clock::duration >
**************************************************************/

int main(void) 
{ 
	// Gives current time of system clock.
	chrono::system_clock::time_point tp = chrono::system_clock::now();
	// This returns the duration from now and the time of epoch
	cout << tp.time_since_epoch().count() << endl;

	tp = tp + chrono::seconds(2);
	cout << tp.time_since_epoch().count() << endl;

	chrono::steady_clock::time_point start = chrono::steady_clock::now();

	cout << "I am bored" << endl;

	chrono::steady_clock::time_point endPoint = chrono::steady_clock::now();

	chrono::steady_clock::duration d = endPoint - start;
	if (d == chrono::steady_clock::duration(0))
		cout << "No time elapse!!!" << endl;

	cout << chrono::duration_cast<chrono::microseconds>(d).count() << endl;

	return 0; 
}