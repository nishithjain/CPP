#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	/************************ Non-member Function ************************/

	string s1("Hello world");

	cout << s1 << endl;
	
	//cout << "Enter a string, press ENTER key to terminate: ";
	//cin >> s1;			// Reads until carriage return, which is the default delimiter
	//cout << "Entered string is : " << s1 << endl;

	//cout << "Enter a string, press ENTER key to terminate: ";
	//getline(cin, s1);	// Reads until carriage return, which is the default delimiter
	//cout << "Entered string is : " << s1 << endl;

	//cout << "Enter a string, press ; to terminate: ";
	//getline(cin, s1, ';');
	//cout << "Entered string is : " << s1 << endl;

	s1 = to_string(8);
	cout << "to_string(8): " << s1 << endl;

	s1 = to_string(2.3e7);
	cout << "to_string(2.3e7): " << s1 << endl;

	s1 = to_string(0XA4);
	cout << "to_string(0XA4): " << s1 << endl;

	s1 = to_string(034);
	cout << "to_string(034): " << s1 << endl;


	// String into a number
	s1 = "190";
	int i = stoi(s1);
	cout << "Int i = " << i << endl;
	
	s1 = "190 monkeys";
	size_t position;

	// i will be 190
	// position will be the location number where the stoi() has stopped parsing
	i = stoi(s1, &position);
	cout << "Position where stoi() has stopped: " << position << endl;


	s1 = "a monkey";
	//i = stoi(s1, &position); // This will throw invalid_argument
					/*16 for hexa decimal number*/
	i = stoi(s1, &position, 16);
	cout << "i = stoi(s1, &position, 16): " << i << endl;

	// We also have
	// stol - string to long
	// stod - string to double
	// stof - string to float

	return 0;
}