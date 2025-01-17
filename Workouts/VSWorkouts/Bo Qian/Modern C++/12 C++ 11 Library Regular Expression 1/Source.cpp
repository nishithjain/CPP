#include <iostream>
#include <regex>	// Regular Expression
#include <string>

using namespace std;

/*************************************************************
					Regular Expression
- What is "Regular Expression"?
Answer: Regular Expression is a specific pattern that provides 
concise and flexible means to match strings of text, such as 
particular characters, words or patterns of characters.
- In short, Regular Expression is a way of matching strings.
- It is supported by almost all languages.
**************************************************************/

#pragma region Simple Example
//int main(void) 
//{ 
//	string str;
//
//	while (true)
//	{
//		cin >> str;	 
//							/*Ignore Case*/
//		regex e("abc", regex_constants::icase);
//
//		bool match = regex_match(str, e);
//		cout << (match ? "Matched" : "Not matched") << endl;
//	}
//	return 0; 
//}
#pragma endregion Simple Example

#pragma region Special Pattern Characters
/*************************************************************
Special Pattern Characters - has special meaning when it appears
in regular expression.

dot (.) - Any character except newline.
?	- 0 or 1 preceding character.	regex e("abc?") means, here
	preceding character is 'c' and it means 0 or 1 'c'. So 'ab' is match
*	- 0 or more preceding character.
+	- 1 or more (can't be 0)
[]	- any characters in the [] can be matched.
^	- any characters which are in [] is not a match
{3}	- exact 3 appearance of preceding character
{3,}- 3 or more preceding character
{3,5} - either 3 or 4 or 5 of preceding character
|	- mean OR
\	- escape sign
()	- indicates the group
**************************************************************/
int main(void) 
{ 
	string str;

	while (true)
	{
		cin >> str;	 
							
		regex e("abc", regex_constants::icase);
		//regex e("abc.");	// Means abcd is match
		//regex e("abc?");	// ab is a match
		//regex e("abc*");	// abcdef is a match
		//regex e("abc+");	// 
		//regex e("ab[cd]*");	// abcccdd is a match
		//regex e("ab[^cd]*");	// abeee is a match
		//regex e("ab[cd]{3}");	// abddd is a match
		//regex e("ab[cd]{3,}");	// abcdddd is a match
		//regex e("ab[cd]{3,5}");	// abcdddd is a match
		//regex e("abc|de[fg]");		// def is a match
		//regex e("abc|de[\[fg]");
		//regex("(abc)de+\\1");	// abddeeabc is a match
		//regex("(ab)c(de+)\\2\\1");	//

		// To search a email address
		//regex e("[[:w:]]+@[[:w:]]+\.com");	// [[:w:]] word char: digit, number or underscore


		//bool match = regex_match(str, e);

		bool match = regex_search(str, e);

		cout << (match ? "Matched" : "Not matched") << endl;
	}
	return 0; 
}

#pragma endregion Special Pattern Characters
