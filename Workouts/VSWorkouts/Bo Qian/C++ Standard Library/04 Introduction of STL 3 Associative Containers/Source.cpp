#include <iostream>
#include <set>
#include <map>

using namespace std;

/************************************************************************
							Associative Container
	- The elements of associative container are always sorted.
	- They are implemented using binary tree.
	- Elements are sorted using operator <
	- No push_back() or push_front(), cos these operation doesn't make 
	any sense.
************************************************************************/

int main(void)
{

#pragma region Set
	// Set/Multiset: value of the elements can't be modified!!!
	// Set doesn't allow duplicate items!!!
	cout << "##################### SET #####################" << endl;

	set<int> aSet;

	// Insert take log time
	aSet.insert(3);			// aSet: { 3 }
	aSet.insert(10);		// aSet: { 3, 10 }
	aSet.insert(-4);		// aSet: { -4, 3, 10 }

	for (set<int>::iterator itr = aSet.begin(); itr != aSet.end(); itr++)
		cout << *itr << " ";
	cout << endl;

	// Search takes log time
	set<int>::iterator itr = aSet.find(10);	// O(log(n)), itr points to 10
	 
	// Insertion 
	pair<set<int>::iterator, bool> ret;
	ret = aSet.insert(10);

	if (false == ret.second)
	{
		itr = ret.first;	// Now the itr points to 10
		cout << "Set already contains this element!!!" << endl;
	}

	// Note that insert will not insert at the end, but will be inserted at
	// proper position. By providing itr to insert function, we are providing 
	// hint to the compiler.
	aSet.insert(itr, 9);	// aSet: { -4, 3, 9, 10 }

	for (set<int>::iterator itr = aSet.begin(); itr != aSet.end(); itr++)
		cout << *itr << " ";
	cout << endl;
#pragma endregion Set

#pragma region MultiSet
	
	cout << "##################### MULTI SET #####################" << endl;

	// Allows duplicate items!!!
	multiset<int> aMultiSet;

	aMultiSet.insert(10);	// aMultiSet: { 10 }
	aMultiSet.insert(11);	// aMultiSet: { 10, 11}
	aMultiSet.insert(1);	// aMultiSet: { 1, 10, 11 }
	aMultiSet.insert(12);	// aMultiSet: { 1, 10, 11, 12 }
	aMultiSet.insert(10);	// aMultiSet: { 1, 10, 10, 11, 12 }

	
	for (multiset<int>::iterator itr = aMultiSet.begin(); itr != aMultiSet.end(); itr++)
		cout << *itr << " ";
	cout << endl;

	multiset<int>::iterator itr1 = aMultiSet.find(10);
	
	//	*itr1 = 10;	// can't be modified.
	
	for (; itr1 != aMultiSet.end(); itr1++)
		cout << *itr1 << " ";
	cout << endl;

/************************************************************************
Properties of vector
	1. Fast search: O(log(n)).
	2. Traversing is slow (compared to vector & deque).
	3. No random access, no [] operator.
************************************************************************/

#pragma endregion MultiSet

#pragma region Map
	cout << "##################### MAP #####################" << endl;

	/**************************************************
	Associative containers are always sorted. Sometimes,
	people want to sort based on keys. So we can use 
	Map or Multimap!!!
	Keys can't be modified!!!
	**************************************************/
	
	// Map doesn't allow duplicate items!!!
	map<char, int> aMap;

	aMap.insert(pair<char, int>('a', 100));
	aMap.insert(make_pair('z', 200));

	for (map<char, int>::iterator itr = aMap.begin(); itr != aMap.end(); itr++)
		cout << (*itr).first << " => " << (*itr).second << endl;
	cout << endl;

	for (auto itr = aMap.begin(); itr != aMap.end(); itr++)
		cout << (*itr).first << " => " << (*itr).second << endl;
	cout << endl;

	auto it = aMap.begin();
	aMap.insert(it, pair<char, int>('b', 400));

	for (auto itr = aMap.begin(); itr != aMap.end(); itr++)
		cout << (*itr).first << " => " << (*itr).second << endl;
	cout << endl;

#pragma endregion Map

#pragma region Multimap
	cout << "##################### MULTI MAP #####################" << endl;
	multimap<char, int> aMultiMap;
	
	aMultiMap.insert(pair<char, int>('n', 100));
	aMultiMap.insert(make_pair('i', 200));
	aMultiMap.insert(pair<char, int>('s', 100));
	aMultiMap.insert(pair<char, int>('s', 500));

	for (auto itr = aMultiMap.begin(); itr != aMultiMap.end(); itr++)
		cout << (*itr).first << " => " << (*itr).second << endl;
	cout << endl;

#pragma endregion Multimap

	return 0;
}