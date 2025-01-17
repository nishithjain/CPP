#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	/************************ String and Algorithm ************************/
	// We can apply STL algorithms to string.

	string s1 = "Variety is the spice of life";
	int num = count(s1.begin(), s1.end(), 'e');
	cout << "Number of e's in '" << s1 << "' is " << num << endl;

	// All the letter of abcde...
	num = count_if(s1.begin(), s1.end(),
		[](char ch) { return ((ch <= 'e') && (ch >= 'a')); });
	cout << "Number of a's + b's + c's + d's + e's :" << num << endl;

	s1 = "Goodness is better than beauty";
	// Search consecutive 2 s
	string::iterator itr = search_n(s1.begin(), s1.begin() + 20,
		2, 's');
	s1.erase(itr, itr + 5);
	cout << "s1.erase(itr, itr + 5) :" << s1 << endl;

	s1.insert(itr, 3, 'z');
	cout << "s1.insert(itr, 3, 'z') :" << s1 << endl;

	s1.replace(itr, itr + 3, 3, 'y');	// Replace the substring
	// Member function replace
	cout << "s1.replace(itr, itr + 3, 3, 'y') :" << s1 << endl;

	string s2 = s1;
	is_permutation(s1.begin(), s1.end(), s2.begin());

	// Algorithm function replace
	replace(s1.begin(), s1.end(), 'e', ' ');	// Replace characters
	cout << "s1.replace(s1.begin(), s1.end(), 'e', ' ') :" << s1 << endl;

	transform(s1.begin(),s1.end(),
		s2.begin(),
		[](char ch) {
		if (ch < 'n') return 'a';
		else return 'z';
	});
	cout << "After transform s2 is: " << s2 << endl;

	s1 = "abcdefg";

	rotate(s1.begin(), s1.begin() + 3, s1.end());
	cout << "After rotate s1: " << s1 << endl;

	u16string s3;	// string char16_t
	u32string s4;	// string char32_t
	wstring s5;		// string wchar_t (wide character)

	return 0;
}