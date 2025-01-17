#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Note that we must take the first parameter by reference
void writeToStream(ostream& output, int number) 
{
	output << number << endl;
}

int main(void) {
	// Write an int to the user's console.
	int myNum = 65536;
	cout << "Result when writing an int directly to cout: " << myNum << endl;
	writeToStream(cout, myNum);

	// Write an int to a file
	ofstream outputFile;
	outputFile.open("Nishith.txt");
	writeToStream(outputFile, myNum);
	return 0;
}
