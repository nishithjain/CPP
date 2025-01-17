#include <iostream>
#include <fstream>

using namespace std;

/************************************************************************
						File Stream and Error Handling
************************************************************************/
int main(void)
{

	{
		// This will open file for writing also this will clear
		// the content of the file!!!.
		//ofstream of("MyLog.txt");

		// Move the output pointer to the end of the file
		ofstream of("MyLog.txt",ofstream::app);
		of << "Honesty is the best policy" << endl;
	}
	{
		ofstream of("MyLog.txt",ofstream::in | ofstream::out );
		// Moves the output pointer 10 chars after begin
		of.seekp(10, ios::beg);
		of << "12345"; // Overwrite 5 chars
		// Moves the output pointer 5 chars before end
		of.seekp(-5, ios::end);
		of << "Nothing ventured, nothing gained" << endl;
		// Moves the output pointer 5 chars before current position
		of.seekp(-5, ios::cur);
		of << "Hello" << endl;
	}
	{
		ifstream inf("MyLog.txt");
		int i;
		// This will read 1 word, parse it as integer and save it into i.
		// So below operation will fail since the first data is character!!!
		inf >> i;

		/* For stream, error status is indicated with 4 bits
		Error Status:
		1. goodbit
		2. badbit.
		3. failbit.
		4. eofbit.
		*/

		if (inf.good())	// goodbit ==1 
			cout << "Everything is OK" << endl;
		if (inf.bad())	// badbit == 1
			cout << "Non-recoverable error has happened" << endl;
		if (inf.fail())	// failbit == 1 and badbit == 1
			cout << "Failed stream operation" << endl;	// Recoverable
		if (inf.eof())	// eofbit == 1
			cout << "End of file" << endl;

		// This will clear all the error status
		// Sets the goodbit to 1 and sets everything to 0
		inf.clear();

		// Sets a new value to the error flag
		// sets badbit to 1, and sets everything to 0
		inf.clear(ios::badbit);

		// This will read the current status flag
		inf.rdstate();
		// This will clear only the failbit and everything else
		// stay the same
		inf.clear(inf.rdstate() & ~ios::failbit);

		if (inf) // Equivalent to : if(!inf.fail())
			cout << "Read successfully" << endl;
		if (inf>>i)
			cout << "Read successfully" << endl;


		/* Handle errors with exceptions */
		// Setting the exception mask. When badbit or failbit are set to 1,
		// an exception is thrown!!! When eofbit is set to 1, no exception is
		// thrown
		//inf.clear();

		inf.exceptions(ios::badbit | ios::failbit);

		inf.exceptions(ios::goodbit);	// No exception 
	}
	return 0;
}