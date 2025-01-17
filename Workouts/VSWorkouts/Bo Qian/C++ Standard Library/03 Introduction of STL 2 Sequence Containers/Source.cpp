#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>

using namespace std;

/************************************************************************
							Containers
1. Sequence containers (array and linked list)
	- STL provides vector, deque, list, forward list and array
2. Associative containers (binary tree) : always sorted
	- set, multiset
	- map, multimap
3. Unordered containers (hash tables)
	- Unordered set/multiset
	- Unordered map/multimap

	
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <set>				// Set and multiset
#include <map>				// Map and multimap
#include <unordered_set>	// Unordered set/multiset
#include <unordered_map>	// Unordered map/multimap
#include <iterator>
#include <algorithm>
#include <numeric>			// Some numeric algorithm
#include <functional>		// For functors

************************************************************************/

int main(void)
{

#pragma region Vector
	{
		cout << "##################### VECTOR #####################" << endl;

		vector<int> aVec;	//	aVec.size() == 0

		aVec.push_back(4);
		aVec.push_back(1);
		aVec.push_back(6);
		aVec.push_back(7);	// aVec: {4, 1, 6, 7}; aVec.size() == 4

		//cout << aVec[8] << endl;	// This was of accessing doesn't do "range check"
		//cout << aVec.at(8) << endl;	// throws range_error exception of out of range

		for (int i = 0; i < aVec.size(); i++)
			cout << aVec[i] << " ";
		cout << endl;

		for (vector<int>::iterator itr = aVec.begin(); itr != aVec.end(); itr++)
			cout << *itr << " ";
		cout << endl;

		for (auto it : aVec)	// In C++11
			cout << it << " ";
		cout << endl;


		{	// Common member functions provided by all containers
			if (aVec.empty()) { cout << "Not possible\n"; }	// aVec.size() == 4
			cout << aVec.size() << endl;
			vector<int> bVec(aVec);	// Copy constructor
			aVec.clear();			// Removes all items in aVec and aVec.size() == 0
			bVec.swap(aVec);		// Interchange the elements
		}
	}
/************************************************************************
Properties of vector
	1. Fast insert/remove at the end : O(1)
	2. Slow insert/remove at the beginning or in the middle : O(n)
	3. Slow search : O(n)
************************************************************************/

#pragma endregion Vector

#pragma region Deque
	// Deque can grow both at the end and at the beginning
	//		 +-----+-----+-----+-----+-----+-----+-----+     
	//	<----      |     |     |     |     |     |      ---->
	//		 +-----+-----+-----+-----+-----+-----+-----+     

	cout << "##################### DEQUE #####################" << endl;

	deque<int> aDeque{ 4, 6, 7 };

	aDeque.push_back(2);	// { 4, 6, 7, 2 };
	aDeque.push_front(5);	// { 5, 4, 6, 7, 2 };

	for (deque<int>::iterator itr = aDeque.begin(); itr != aDeque.end(); itr++)
		cout << *itr << " ";
	cout << endl;

	// Deque has similar interface with vector - Random Access
	cout << aDeque[2] << endl;

/************************************************************************
Properties of deque
	1. Fast insert/remove at the beginning and at the end : O(1)
	2. Slow insert/remove in the middle : O(n)
	3. Slow search : O(n)
************************************************************************/
#pragma endregion Deque

#pragma region List
	cout << "##################### LIST #####################" << endl;
//	List is doubly liked list!!!
//				+--> +----+-----------> +----+--->  
//					 |  5 |             |  7 |      
//				<----+----+ <-----------+----+ <---+

	list<int> aList{ 5, 2, 9 };

	aList.push_back(6);		// { 5, 2, 9, 6 };
	aList.push_front(8);	// { 8, 5, 2, 9, 6 };

	for (list<int>::iterator itr = aList.begin(); itr != aList.end(); itr++)
		cout << *itr << " ";

	cout << endl;

	list<int>::iterator itr = find(aList.begin(), aList.end(), 2);
	// Will insert the item in front of the iterator
	aList.insert(itr, 100); // { 8, 5, 100, 2, 9, 6 };
	for (list<int>::iterator itr = aList.begin(); itr != aList.end(); itr++)
		cout << *itr << " ";
	cout << endl;

	itr++;

	aList.erase(itr);	// { 8, 5, 100, 2, 6 };

	for (list<int>::iterator itr = aList.begin(); itr != aList.end(); itr++)
		cout << *itr << " ";
	cout << endl;
/************************************************************************
Properties of list
	1. Fast insert/remove at any place : O(1)
	2. No random access, no [] operator.
	3. Slow search : O(n)
************************************************************************/
#pragma endregion List

#pragma region Forward List
	cout << "##################### FORWARD LIST #####################" << endl;
//	+-----+-----> +-----+-----> +-----+-----> +-----+
//	|     |       |     |       |     |       |     |
//	+-----+       +-----+       +-----+       +-----+

	forward_list<int> aForwardList{ 1, 2, 3, 4 };

	aForwardList.push_front(6);		// { 6, 1, 2, 3, 4 };

	for (forward_list<int>::iterator itr = aForwardList.begin(); itr != aForwardList.end(); itr++)
		cout << *itr << " ";
	cout << endl;

#pragma endregion Forward List

#pragma region Array
	cout << "##################### ARRAY #####################" << endl;

	array<int, 5> aArray = { 1, 2, 3, 4, 5 };
	for (array<int, 5>::iterator itr = aArray.begin(); itr != aArray.end(); itr++)
		cout << *itr << " ";
	cout << endl;

#pragma endregion Array

	return 0;
}