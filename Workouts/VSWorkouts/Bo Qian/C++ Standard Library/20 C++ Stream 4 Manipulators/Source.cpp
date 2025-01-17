#include <iostream>
#include <iomanip>

using namespace std;

ostream& endl(ostream& sm)	// Manipulator!!!
{
	sm.put('\n');
	sm.flush();
	return sm;
}

ostream& ostream::operator<<(ostream& (*func)(ostream&))
{
	return (*func)(*this);
}

int main()
{
	// endl is new line + flush
	cout << "Hello" << endl;
	// But what is endl? is it a object? or Built-in data type?
	// or is it function?

	// endl is a function!!! endl takes ostream reference and returns
	// ostream reference

	// Then what is << operator?
	// Now << is taking function(endl) as parameter


	cout << ends;	// Insert a '\0'
	cout << flush;
	//cin >> ws;	// Read and discard white spaces!!!


	// It will print 8 chars and 99 is aligned to left and fill with underscore
	cout << setw(8) << left << setfill('_') << 99 << endl;

	cout << hex << showbase << 14 << endl;
	return 0;
}