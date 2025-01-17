#include <iostream>
#include <fstream>
#include <algorithm>
#include <bitset> 
#include <complex>

using namespace std;

/************************************************************************
									Stream
	 - Stream is a C++ input/output library.
************************************************************************/

int main(void)
{
/************************************************************************
	- cout: is a global object of ostream which lives in std namespace
	- ostream is typedef basic_ostream<char> ostream
	- << : is the member function of ostream
	Signature of :
		ostream&& ostream::operator<< (string v);
	- endl; assume '\n' + flush operation

	What is stream?
	- Serial IO interface to external devices (file, stdin/stdout, network, etc...)
************************************************************************/
	cout << "Hello" << endl;

	// What do you mean by serial in the stream definition?
	string s("hello");
	s[3] = 't';	// This is random access!!!
	//cout[3] = 't';	// ERROR!!!


	{
		// This will open a file to write. If the file doesn't exists, it will
		// create a new file!!!.
		ofstream of("MyLog.txt");
		// << is overloaded for all the fundamental data types
		of << "Experience is the mother of wisdom" << endl;
		of << 224 << endl;

		// << is also overloaded for some of STL data types
		of << bitset<8>(14) << endl;
		of << complex<int>(2, 3) << endl;
	}	// Here the file is closed. RAII

/************************************************************************
Every IO operation
	1. Formatting the data
	2. Communication the data with external devices
stream class provides a common API's to formate the data. - Low coupling
************************************************************************/
	return 0;
}