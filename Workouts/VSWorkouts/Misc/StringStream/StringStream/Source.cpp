#include <iostream>
#include <string>
#include <sstream> // notice the dumb name
using namespace std;

int main(void) 
{

	int nishithFavoriteNumber = 8675309;
	string nishithFavoriteNumberString = "8675309";

	stringstream inputStringStream;
	int intRepresentation;
	inputStringStream << nishithFavoriteNumberString;
	inputStringStream >> intRepresentation;
	cout << "Result when converting a string to an int:" << endl;
	cout << intRepresentation << endl;



	stringstream outputStringStream;
	outputStringStream << nishithFavoriteNumber;
	string stringRepresentation = outputStringStream.str();
	cout << "Result when converting an int to a string:" << endl;
	cout << stringRepresentation << endl;

	return 0;
}
