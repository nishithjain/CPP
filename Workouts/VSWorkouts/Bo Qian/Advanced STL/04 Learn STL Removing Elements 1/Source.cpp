#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Prints contents of a container!!!
template<typename T>
void print(T t, string msg)
{
	cout << msg << " { ";
	for (typename T::iterator it = t.begin(); it != t.end(); ++it)
		cout << *it << ", ";
	cout << " }" << endl;
}

int main(void) 
{ 
	vector<int> c = { 1, 4, 6, 1, 1, 1, 1, 12, 18, 16 };
	print(c, "Original: ");

	//for (auto itr = c.begin(); itr != c.end();)
	//{
	//	if (*itr == 1)
	//	{
	//		itr = c.erase(itr);
	//	}
	//	else
	//	{
	//		itr++;
	//	}
	//} // Complexity: O(n*m)
	//print(c, "After erase():");

	auto itr =	remove(c.begin(), c.end(), 1);// Complexity is O(n)
	c.erase(itr, c.end());
	print(c, "After erase():");
	cout << "Capacity is :" << c.capacity() << endl;
	//c.shrink_to_fit();	// shrink_to_fit() is present in C++11
	// We can use swap trick
	vector<int>(c).swap(c);
	cout << "Capacity is :" << c.capacity() << endl;

	return 0; 
}
/*************************************************************
Summary of removing elements:
1. Vector or deque: algorithm remove() followed by erase()
2. List: Member function remove()
3. Associative container or unordered container: erase()
**************************************************************/