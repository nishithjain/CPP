#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	/************************ Single Element Access ************************/
#pragma region Single Element Access
	{
		cout << "############### Single Element Access ###############" << endl;

		string s1 = "Goodbye";
	
		// s[2] will return the reference to the 2nd element of s1
		cout << "2nd Char is :" << s1[2] << endl;
		s1[2] = 'x';
		cout << "Now s1 is: " << s1 << endl;	// Goxdbye
	
		s1.at(2) = 'y';
		cout << "Now s1 is: " << s1 << endl;	// Goydbye
	
		//s1[20] = 'a'; //Undefined behavior
		//s1.at(20) will throw exception of out_of_range
	
		// s1.at() throws exception across all the random access
		// containers if we try to access out side the bound.
	
		{
			// string provides below APIs to be consistent with other
			// containers
			// Like vector, string doesn't have push_front() and pop_front()
			cout << "front(): First char is: " << s1.front() << endl;
			cout << "back(): Last char is: " << s1.back() << endl;
			s1.push_back('z');
			cout << "push_back('z'): Now s1 is: " << s1 << endl;
			s1.pop_back();
			cout << "pop_back(): Now s1 is: " << s1 << endl;
			
			string::iterator begSting = s1.begin();
			string::iterator endString = s1.end();
		
			for (string::iterator it = begSting; it != endString; it++)
				cout << *it << " ";
			cout << endl;
	
			string s3(s1.begin(), s1.begin() + 3);
			cout << "s3 constructed using iterators: " << s3 << endl;
		}
	}
#pragma endregion Single Element Access
	cout << endl;
	/************************ Ranged Access ************************/
#pragma region Ranged Access
	// assign, append, insert and replace
	{
		cout << "############### Ranged Access ###############" << endl;
		string s2 = "Dragon Land";
		string s1;
		
		s1.assign(s2);	// s1 = s2;
		cout << "s1.assign: s1 is :" << s1 << endl;
		// Starting from 2nd position and size is 4
		// When the first parameter is string, 2nd parameter is starting position
		s1.assign(s2, 2, 4);
		cout << "s1.assign: s1 is :" << s1 << endl;
		s1.assign("Wisdom");
		cout << "s1.assign: s1 is :" << s1 << endl;
		// When the 1st parameter is C-string, 2nd parameter is size
		s1.assign("Wisdom", 3);
		cout << "s1.assign: s1 is :" << s1 << endl;

		//s1.assign(s1, 3);	//ERROR!!!

		s1.assign(3, 'x');
		cout << "s1.assign: s1 is :" << s1 << endl;

		s1.assign({ 'a', 'b', 'c' });
		cout << "s1.assign: s1 is :" << s1 << endl;


		// append, insert and replace
		s1.append(" def");
		cout << "s1.append: s1 is :" << s1 << endl;
		
		// insert 4 chars of mountain into 2nd position of s1
		s1.insert(2, "mountain", 4);
		cout << "s1.insert: s1 is :" << s1 << endl;

		s1.replace(2, 5, s2, 3, 3);
		cout << "s1.replace: s1 is :" << s1 << endl;

		// Pattern is 1 number is position
		// 2nd number is size
		s1.erase(1, 4);
		cout << "s1.erase: s1 is :" << s1 << endl;

		s1 = s2.substr(2, 4);
		cout << "s1.substr: s1 is :" << s1 << endl;

		s1 = "abc";
		s1.c_str();	// This will return C-String "abc\0"
		s1.data();	// This will return C-String "abc\0"

		s1.swap(s2);
		cout << "s1.swap: s1 is :" << s1 << endl;
		cout << "s1.swap: s2 is :" << s2 << endl;
	}
#pragma endregion Ranged Access
	cout << endl;

	return 0;
}