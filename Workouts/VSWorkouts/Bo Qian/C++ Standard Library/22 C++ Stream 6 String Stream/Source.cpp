#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/************************************************************************
								String Stream
	- It doesn't do IO operation.
	- It read/write operation on string.
	- It treas the string as file. But Why????
		The main purpose of this is to reuse the formatting functions of
		stream to process the string. CODE REUSE.
************************************************************************/
int main(void)
{
	stringstream ss;	// This doesn't do IO operation
	
	ss << 89 << " Hex: " << hex << 89 << " Oct: " << oct << 89;
	cout << ss.str() << endl;

	int a, b, c;
	string s1;

	// Formatted input. Works token by token. 
	// Tokens are space, tabs, newlines.
	ss >> hex >> a;
	cout << a << endl;

	ss >> s1; 
	cout << s1 << endl;

	ss >> dec >> b;
	cout << b << endl;

	// Ignore the next 6 chars in the stream.
	ss.ignore(6);

	ss >> oct >> c;
	cout << c << endl;

	// ostringstream -- formatted output
	// istringstream -- formatted input

	return 0;
}