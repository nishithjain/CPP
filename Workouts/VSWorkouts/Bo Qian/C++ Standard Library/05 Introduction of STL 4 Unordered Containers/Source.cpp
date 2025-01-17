#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std; 

/************************************************************************
								Unordered Containers (C++11)
************************************************************************/

int main(void)
{
		//												Buckets			Entries
		//                                               +----+          +----+          
		//                                 +-----------> |    | +------> |    |          
		//                                 |             +----+          +----+          
		//                                 |             |    |                          
		//                                 |             +----+                          
		//+------+                         |             |    |                          
		//|      |         +--------------++             +----+          +----+    +----+
		//|      |         |              ++-----------> |    | +------> |    | +> |    |
		//|      |         |     Hash     |              +----+          +----+    +----+
		//|      |-------> |   Functions  |              |    |                          
		//|      |         |              ++             +----+          +----+          
		//|      |         +--------------++             |    | +------> |    |          
		//+------+                         |             +----+          +----+          
		//                                 +-----------> |    |                          
		//                                 |             +----+                          
		//                                 +-----------> |    |                          
		//                                               +----+                          
		//													|
		//													|
		//													|
		//													v


#pragma region UnorderedSet

	cout << "##################### Unordered Set #####################" << endl;
	// Doesn't allow duplicate items!!!
	// 2 items with red are there, but only one item will be stored!!!
	unordered_set<string> aUnorderedSet = { "red", "blue", "green", "red" };
	
	for (auto it = aUnorderedSet.begin(); it != aUnorderedSet.end(); it++)
		cout << *it << " ";
	cout << endl;

	auto itr = aUnorderedSet.find("green");	// Takes O(1)

	if (itr != aUnorderedSet.end())	// Important check
		cout << *itr << endl;

	aUnorderedSet.insert("yellow");	// Takes O(1)

	vector<string> aVec = { "purple", "pink" };
	aUnorderedSet.insert(aVec.begin(), aVec.end());

	// Hash table specific API's
	// Ratio of total number of elements to total number of buckets
	cout << "Load Factor = " << aUnorderedSet.load_factor() << endl;	
	string x = "red";
	// In which bucket the element is stored?
	cout << x << " is in bucket #" << aUnorderedSet.bucket(x) << endl;
	cout << "Total buckets = " << aUnorderedSet.bucket_count() << endl;

#pragma endregion UnorderedSet


#pragma region UnorderedMultiset

	cout << "##################### Unordered Multiset #####################" << endl;
	// Unordered set that allows duplicate items!!!

	unordered_multiset<string> multiSet = { "red", "blue", "green", "red" };

	for (auto itr1 = multiSet.begin(); itr1 != multiSet.end(); itr1++)
		cout << *itr1 << " ";
	cout << endl;

#pragma endregion UnorderedMultiset


	/************************************************************************
	Properties of Unordered Containers
		1.	Fastest search/insert at any place: O(1)
			Associative containers takes O(log(n))
			vector, deque takes O(n)
			list takes O(1) to insert and O(n) to search
		2.	Unordered set/multiset: element value cannot be changed.
			Unordered map/multimap: element key cannot be changed.
	************************************************************************/
	return 0;
}
	