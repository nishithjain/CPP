#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/************************************************************************
						STL Algorithm Walk-through
Non-modifying Algorithms
	count, min and max, compare, linear search, attribute
************************************************************************/

int main(void)
{
	vector<int> vec = { 9, 60, 90, 8, 45, 87, 90, 69, 69, 55, 7 };
	vector<int> vec2 = { 9, 60, 70, 8, 45, 87 };
	vector<int> vec3 = { 9, 60, 8, 90, 87, 45, 69, 90, 69, 7, 55 };
	vector<int>::iterator itr, itr2;
	pair<vector<int>::iterator, vector<int>::iterator> pairOfItrs;

#pragma region Count

	cout << "################ COUNT ################" << endl;

				 //Algo			Data			Operation
	int count69 = count(vec.begin(), vec.end(), 69);
	cout << "Number of elements with data 69 : " << count69 << endl;
					//Algo			Data		
	int countGt10 = count_if(vec.begin(), vec.end(),
		//	Operation
		[](int x){return x > 10; }
	);
	cout << "Number of elements > 10: " << countGt10 << endl;

#pragma endregion Count

#pragma region MinNMax
	cout << "################ MINnMAX ################" << endl;

	// Returns the first Max value			
	itr = max_element(vec.begin(), vec.end());
	cout << "Max element in the vector is: " << *itr << endl;

	itr = max_element(vec.begin(), vec.end(),
		// Own version of comparison function
		// Below function will return the first element whose last digit is biggest
		[](int x, int y){ return ((x % 10) < (y % 10)); }
		);
	cout << "Max element whose last digit is Max: " << *itr << endl;

	itr = min_element(vec.begin(), vec.end());
	cout << "Min element in the vector is: " << *itr << endl;

	pairOfItrs = minmax_element(vec.begin(), vec.end());
	cout << "First smallest element: " << *pairOfItrs.first << endl;
	cout << "Last biggest element: " << *pairOfItrs.second << endl;

	pairOfItrs = minmax_element(vec.begin(), vec.end(),
		[](int x, int y) { return ((x % 10) < (y % 10)); }
		);
	cout << "First smallest element: " << *pairOfItrs.first << endl;
	cout << "Last biggest element: " << *pairOfItrs.second << endl;


#pragma endregion MinNMax

#pragma region Linear Searching

	cout << "################ LINEAR SEARCH ################" << endl;

	// Use linear search when the data is not sorted.
	// Use binary search if the data is already sorted.

	// Linear search returns the first item which matches the condition
	itr = find(vec.begin(), vec.end(), 55);
	cout << "Element is :" << *itr << endl;

	itr = find_if(vec.begin(), vec.end(),
		[](int x){ return x > 80; }
	);

	cout << "Element > 80 :" << *itr << endl;

	itr = find_if_not(vec.begin(), vec.end(),
		[](int x){ return x > 80; }
	);
	cout << "Element < 80 :" << *itr << endl;

	itr = search_n(vec.begin(), vec.end(), 2, 69);
	cout << "Consecutive 2 items of 69 :" << *itr << " and " << *itr++ << endl;

	// Search sub range
	vector<int> sub{ 45, 87, 90 };
	itr = search(vec.begin(), vec.end(), sub.begin(), sub.end());
	cout << "Sub vector is : ";
	for (auto i = itr; i != vec.end(); i++)
		cout << *i << " ";
	cout << endl;

	// Search any of
	vector<int> items = { 87, 69 };
	itr = find_first_of(vec.begin(), vec.end(),
		items.begin(), items.end());
	cout << "Search Any Of { 87, 69 }: " << *itr << endl;

#pragma endregion Linear Searching

#pragma region Compare Range
	cout << "################ COMPARE RANGE ################" << endl;

	if (!equal(vec.begin(), vec.end(), vec2.begin()))
		cout << "vec and vec2 are not same!!!" << endl;

	if (is_permutation(vec.begin(), vec.end(), vec3.begin()))
		cout << "vec and vec3 have same items, but in different order!!!" << endl;

	pairOfItrs = mismatch(vec.begin(), vec.end(), vec3.begin());
	// returns the pair of iterators for first mismatch
	cout << "Mismatch in vec:" << *pairOfItrs.first << endl;
	cout << "Mismatch in vec3:" << *pairOfItrs.second << endl;

	if (lexicographical_compare(vec.begin(), vec.end(), vec3.begin(), vec3.end()))
		cout << "vec < vec 3" << endl;
	else
		cout << "vec3 < vec " << endl;

	// All of the comparing algorithms have generalized from of the same name.

#pragma endregion Compare Range

#pragma region Check Attributes

	cout << "################ CHECK ATTRIBUTES ################" << endl;

	if (is_sorted(vec.begin(), vec.end()))
		cout << "vec is sorted" << endl;
	else
		cout << "vec is not sorted" << endl;
	// Finds the first place where the data is no longer sorted
	itr = is_sorted_until(vec.begin(), vec.end());
	cout << "From here vec is unsorted :";
	for (auto i = itr; i != vec.end(); i++)
		cout << *i << " ";
	cout << endl;

	if (all_of(vec.begin(), vec.end(), [](int x){ return x > 6; }))
		cout << "All the vec items are > 6 !!!" << endl;

	if (any_of(vec.begin(), vec.end(), [](int x){ return x == 90; }))
		cout << "One of the item in vec is equal to 90 !!!" << endl;

	if (none_of(vec.begin(), vec.end(), [](int x){ return x < 0; }))
		cout << "One of the item in vec is < 0 !!!" << endl;

#pragma endregion Check Attributes

	return 0;
}