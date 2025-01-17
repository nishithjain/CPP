#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	/************************ Constructors ************************/
#pragma region Constructor
	{
		// String can be constructed from C string as shown below
		string s1("Hello");
		cout << "s1: " << s1 << endl;

		// Here number specifies the size.
		string s2("Hello", 3);
		cout << "s2: " << s2 << endl;

		// Copy constructor
		// Here, the number is the starting position of s1 from 
		// where we want to construct s3
		string s3(s1, 2);
		cout << "s3: " << s3 << endl;

		// s4 is constructed form s2 starting from 2nd position 
		// and has the size 2
		string s4(s1, 2, 2);
		cout << "s4: " << s4 << endl;

		// s5 contains 5 chars of 'a'
		string s5(5, 'a');
		cout << "s5: " << s5 << endl;

		// Also can be constructed from initializer list
		string s6({ 'a', 'b', 'c' });
		cout << "s6: " << s6 << endl;
	}
#pragma endregion Constructor

	/************************ Size ************************/
#pragma region Size

	{
		string s1 = "Goodbye";
		// size() and length() are synonymous functions
		cout << "Size of s1: " << s1.size() << endl;
		cout << "Size of s1: " << s1.length() << endl;

		// capacity(), returns the storage space currently
		// allocated to s1
		cout << "Storage space allocated to s1 :" << s1.capacity() << endl;
		//capacity can be changed using reserve()
		s1.reserve(100);
		cout << "Storage space allocated to s1 :" << s1.capacity() << endl;
		// reserve() function doesn't change the content of s1. It doesn't
		// change the size of s1. It only works on the capacity!!!
		s1.reserve(5);
		cout << "Storage space allocated to s1 :" << s1.capacity() << endl;
		cout << "s1 is: " << s1 << endl;

		// Shrinks the capacity to hold the content
		s1.shrink_to_fit();
		cout << "shrink_to_fit: Size of s1 :" << s1.size() << endl;
		cout << "s1 is: " << s1 << endl;

		// To reduce the size of s1
		s1.resize(9);
		cout << "resize(9): Size of s1 :" << s1.size() << endl;
		s1.resize(9,'x');
		cout << "s1 is: " << s1 << endl;

		// This will print Goo
		s1.resize(3);
		cout << "resize(3): s1 is: " << s1 << endl;

	}
#pragma endregion Size

	return 0;
}