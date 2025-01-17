#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	/************************ Member Function Algorithms ************************/
	// copy(), find() and compare()

	{
		string s1 = "abcdefg";
		char buf[20];

		// Will copy 3 chars from s1 to buf and the returned value is the 
		// number of chars that are indeed copied.
		size_t len = s1.copy(buf, 3);
		buf[len] = '\0';
		cout << "buf is: "<< buf << endl;
		cout << "Number of chars copied = " << len << endl;

		// here copy is the only function with exception where the 1st 
		// number is the size and the 2nd number is the position
		len = s1.copy(buf, 4, 2);
		buf[len] = '\0';
		cout << "buf is: " << buf << endl;
		cout << "Number of chars copied = " << len << endl;

		s1 = "If a job is worth doing, it's worth doing well";
		size_t found = s1.find("doing");
		cout << "Position of 'doing' in s1 is :" << found << endl;

		// This find will start searching from 20th position onwards
		found = s1.find("doing", 20);
		cout << "Position of 'doing' in s1 is :" << found << endl;
		
		found = s1.find("doing well", 0);
		cout << "Position of 'doing' in s1 is :" << found << endl;

		found = s1.find("doing well", 0, 5);
		cout << "Position of 'doing' in s1 is :" << found << endl;

		found = s1.find_first_of("doing");
		cout << "One of the chars from 'doing' appeared at: " << found << endl;

		found = s1.find_first_of("doing", 10);
		cout << "One of the chars from 'doing' appeared at: " << found << endl;

		found = s1.find_first_of("doing", 10, 1);
		cout << "One of the chars from 'doing' appeared at: " << found << endl;

		found = s1.find_last_of("doing");
		cout << "find_last_of: " << found << endl;

		found = s1.find_first_not_of("doing");
		cout << "find_first_not_of: " << found << endl;

		found = s1.find_last_not_of("doing");
		cout << "find_last_not_of: " << found << endl;


		// Compare
		// Returns +ve if (s1 > s2)
		// -ve if (s1 < s2)
		// 0 if (s1 == s2)
		string s2(s1);
		if (s1 == s2)
			cout << "Both s1 and s2 are equal!!!" << endl;
		
		s2 = "zzz";
		if (s1 < s2)
			cout << "s1 is less than s2" << endl;

		s2 = "aaa";
		if (s1 > s2)
			cout << "s1 is greater than s2" << endl;

		// Start the comparison at position 3 and compare 2 chars
		cout << "s1.compare(3, 2, s2): " << s1.compare(3, 2, s2) << endl;

		string ss = s1 + s2;
		cout << "ss = s1 + s2; : " << ss << endl;
	}
	cout << endl;

	return 0;
}