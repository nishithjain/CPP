#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> vec;
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(2);
	vec.push_back(-9);

	vector<int>::iterator itr1 = vec.begin();
	vector<int>::iterator itr2 = vec.end();

	// iterator is like a pointer 
	// We can assign value to them, compare them like pointer, increment them
	// and we can dereference them.
	for (vector<int>::iterator itr = itr1; itr != itr2; itr++)
	{
		cout << *itr << " ";
	}
				//	vec.begin()				vec.end()
				//	  +                         +
				//	  |                         |
				//	  |                         |
				//	  v                         v
				//	+----+----+----+----+----+   
				//	|    |    |    |    |    |   
				//	+----+----+----+----+----+   
				//	cout << *vec.end() << endl;	// BOOM!!!

	sort(itr1, itr2);
	cout << endl;
	for (vector<int>::iterator itr = itr1; itr != itr2; itr++)
	{
		cout << *itr << " ";
	}

	/************************************************************************
	Reasons to use C++ standard library:
	1. Code reuse, no need to re-invent the wheel.
	2. Efficiency.
	3. Accurate, less buggy.
	4. Terse, readable code, reduced control flow.
	5. standardization, guaranteed availability.
	6. A role model of writing library.
	7. Good knowledge of data structures and algorithm.
	************************************************************************/
	return 0;
}