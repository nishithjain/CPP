#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/************************************************************************
								Stream Buffer
	- Typically IO operations has 2 steps...
	1. Formatting the data. -> It is the responsibility of STREAM class
	2. Communicating data to external devices. -> Done by STREAM buffer!!
************************************************************************/
int main(void)
{
	// If we do cout << 34, It is the responsibility of cout to format
	// the data appropriately and then delegate the job of communicating
	// the data to external device to its internal module, which is STRAM
	// buffer!!!
	cout << 34;

	//cout.rdbuf() -> This will give the pointer to internal module of STRAM buffer.
	streambuf* pbuf = cout.rdbuf();

	// This will create another ostream which has the same STREAM buffer
	// as the cout!!! In other words, myCOUT has the same transferring 
	// channel as that of cout!!!
	ostream myCOUT(pbuf);
	myCOUT << 34 << endl; // This will print 34 to standard out!!!

	// Changing the format of myCOUT
	myCOUT.setf(ios::showpos);	// Show the +ve sign of a number
	myCOUT.width(20);			// Width = 20, alignment = right
	myCOUT << 12 << endl;		//           +12

	cout << 12 << endl;			//12

	// Store the STREAM buffer in a temp variable
	streambuf* originalBuf = cout.rdbuf();

	ofstream of("MyLog.txt");
	//	of.rdbuf() -> will give the pointer to buffer
	// Below we are assigning other stream buffer to cout!!!
	cout.rdbuf(of.rdbuf()); // Now cout will write to file!!!
	cout << "Hello" << endl;	// Will write Hello to file

	// Restore the original stream buffer of cout
	cout.rdbuf(originalBuf);
	cout << "Goodbye!!!" << endl;	// Will write Goodbye to screen

	/* STREAM buffer iterator */
	istreambuf_iterator<char> i(cin);
	ostreambuf_iterator<char> o(cout);

	while (*i != 'x')
	{
		*o = *i;
		o++;
		i++;
	}

	copy(istreambuf_iterator<char>(cin), istreambuf_iterator<char>(), ostreambuf_iterator<char>(cout));

	return 0;
}