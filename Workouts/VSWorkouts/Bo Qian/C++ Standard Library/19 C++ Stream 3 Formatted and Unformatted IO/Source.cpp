#include <iostream>
#include <fstream>

using namespace std;
/************************************************************************
						Formatted and Unformatted IO
	- Main purpose of stream class is to format the data
************************************************************************/

int main(void)
{
	// Formatting

	cout << 34 << endl; // Writes 34 to stdout

	cout.setf(ios::oct, ios::basefield);
	cout << 34 << endl;

	cout.setf(ios::showbase);
	cout << 34 << endl;

	cout.setf(ios::hex, ios::basefield);
	cout << 34 << endl;

	cout.unsetf(ios::showbase);
	cout << 34 << endl;

	cout.setf(ios::dec, ios::basefield);
	cout << 34 << endl;

	// We can also change the way the output is shown
	cout.width(10);
	cout << 26 << endl;

	cout.setf(ios::left, ios::adjustfield);
	cout << 26 << endl;

	// Floating point value
	cout.setf(ios::scientific, ios::floatfield);
	cout << 340.1 << endl;

	cout.setf(ios::fixed, ios::floatfield);
	cout << 340.1 << endl;

	cout.precision(3);
	cout << 340.1 << endl;

	// Input formatting
	int i;
	cin.setf(ios::hex, ios::basefield);
	//cin >> i;

	ios::fmtflags f = cout.flags();
	cout.flags(ios::oct | ios::showbase);

	// Unformatted IO

	// Input
	ifstream inf("MyLog.txt");
	char buf[80];

	// Reads up to 80 chars and save in buf
	inf.get(buf, 80);

	// Reads up to 80 chars or until \n
	inf.getline(buf, 80);

	// read 20 chars
	inf.read(buf, 20);

	// Ignore the next 3 chars in the stream
	inf.ignore(3);
	// Returns the char on top of stream
	inf.peek();
	// Returns a char back to the stream
	inf.unget();
	inf.get();

	// Returns the number of chars read by last unformatted read
	inf.gcount();


	// Output
	ofstream of("MyLog.txt");
	of.put('c');

	of.write(buf, 6);
	of.flush();
	return 0;
}