#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readNumbers() 
{
	// Create our ifstream and open the file we want to write to
	ifstream input;
	input.open("numbers.txt");

	int value;
	while (true)
	{
		// Try and read a value
		input >> value;
		// If we failed to read a value, stop.
		if (input.fail())
			break;
		cout << "I read the value: " << value << endl;
	}
}

void readHaiku() 
{
	ifstream input;
	input.open("haiku.txt");

	// Read the file word by word
	while (true) 
	{
		string word;
		// Reading strings using >> will skip whitespace, then read characters
		// until more whitespace is encountered
		input >> word;

		if (input.fail()) break;
		cout << word << endl;
	}
	// Close our stream and reset the fact that it has failed.
	input.close();
	input.clear();
	input.open("haiku.txt");
	cout << endl;

	// Read the file line by line
	while (true)
	{
		string line;
		// The getline function will read characters until a newline character is seen.
		getline(input, line);

		if (input.fail()) break;
		cout << line << endl;
	}
}


int main(void) 
{
	readNumbers();
	readHaiku();
	return 0;
}
