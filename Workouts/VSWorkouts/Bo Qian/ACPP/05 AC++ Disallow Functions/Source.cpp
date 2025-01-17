#include <iostream>
#include <string>

using namespace std;

class openFile
{
public:
	// If we define a constructor which takes a parameter, compiler will not
	// generate any default constructor for me.
	openFile(string fileName){ cout << "Open a file " << fileName << endl; }

	// In C++11, we can disallow copy constructor by using "delete" as shown
	// below or make the copy constructor private and don't define the function.
	openFile(openFile& rhs) = delete;

	// Disallow the copy assignment operator.
	openFile& operator=(const openFile& rhs) = delete;

	// Say this openFile class has inherited the function "writeLine()" and
	// we don't want the write line to be used by openFile class, then we can
	// declare the write line function as private and don't provide definition
	// as shown below...
private:
	void writeLine(string str);

	// Class with a destructor in the private can only be instantiated on heap
	// and can't be stored on stack. Let heavy weight classes to have private 
	// destructor (in embedded programming)
	//~openFile() { cout << "openFile Destructor!!!" << endl; }
};

int main(void)
{
	// We need name of the file to open a file, so don't allow
	// compiler to generate a default constructor for me.
	//openFile f;		// Fails!!!
	openFile f("aTextFile.txt");

	// Below code will call the compiler generated copy constructor.
	// f2 also starts writing to a file. So disallow the copy constructor.
	//openFile f2(f);	// Fails!!!

	openFile f2("bTextFile.txt");
	// Below code will call the compiler generated copy assignment operator.
	// because of this f also starts writing to a file. So disallow 
	// the copy assignment operator.
	//f = f2;			// Fails!!!
	return 0;
}