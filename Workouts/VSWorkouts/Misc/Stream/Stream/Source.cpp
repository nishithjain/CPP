#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// This file demonstrates the WRONG way to read two numbers from a stream.  The
// complexity associated with this is why Stanford provides simpio.h and the
// getInteger function.
int getInteger()
{
	cout << "Please enter an integer value" << endl;
	int value;

	while (true)
	{
		cin >> value;
		if (!cin.fail()) 
			break;

		cout << "Please re-enter an integer value: " << endl;
	}
	return value;
}

// We define a small helper function to simplify the process of reading a line
string getLine() 
{
	string line;
	getline(cin, line);
	return line;
}

int main()
{
	/************************************************************************
	Points to REMEMBER
	- Unread data sits on the stream
	- A stream which has failed stays failed
	************************************************************************/
	{
		int a;
		cin >> a;
		string b;
		cin >> b;

		cout << a << endl;
		cout << b << endl;
	}

	{
		while (true) 
		{
			// By reading an entire line at once we avoid problems with extra data on the stream.
			cout << "How many cookies do you have? ";
			string line = getLine();
			stringstream converter;
			converter << line;

			// We can read data from our stringstream just like any other stream
			int numCookies;
			converter >> numCookies;

			// If we couldn't read an int, then the user entered bad data
			if (converter.fail()) 
			{
				// We clear our error state and read what the user DID enter as a string
				converter.clear();
				string badInput;
				converter >> badInput;
				cout << "Not an integer: " << badInput << endl;
			}
			else
			{
				// Even if we were successfully able to read in one integer, we still need
				// to make sure that there isn't any remaining input. We do this by trying
				// to read in another character.
				char junk;
				converter >> junk;

				// If we read more input, then there was garbage data at the end of our
				// string
				if (!converter.fail())
				{
					cout << "Extra character found: " << junk << endl;
				}
				else 
				{
					cout << "Well, I have " << (2 * numCookies) << " cookies." << endl;
				}
			}
		}

	}
	{
		// Say that the user enters the number 867.5309 here.  The stream will read
		// "867", and return that as the integer result.
		cout << "The first value was: " << getInteger() << endl;

		// The string ".5309" will remain at the end of the stream, so whatever the
		// user enters here will fail to be read, because "." isn't part of any valid
		// integer
		cout << "The second value was: " << getInteger() << endl;
	}
	return 0;
}
