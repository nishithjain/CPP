#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>	// Numeric Algorithms

using namespace std;

/************************************************************************
				Sorted Data Algorithms and Numeric Algorithms
	 - Algorithms that require date being presorted.
	 - Binary search, merge, set operations.
	 - If we apply these algorithm on unsorted data, result is undefined.
	 - Generalized form also exists for these algorithms.
************************************************************************/

int main(void)
{
	/********** Sorted Data Algorithms **********/
#pragma region Binary Search
	{
		cout << "################### Binary Search ###################" << endl;
		vector<int> vec = { 8, 9, 9, 9, 45, 87, 90 };

		// Check if 9 is present in the vec
		bool found = binary_search(vec.begin(), vec.end(), 9);
		if (found) cout << "9 is present in vec!!!" << endl;

		// If we want to search multiple item, then we should 
		// use include()
		vector<int> searchThese = { 9, 45, 87 };		// Must be Sorted!!!
		found = includes(vec.begin(), vec.end(),		// Range #1
			searchThese.begin(), searchThese.end());	// Range #2
		if (found)
			cout << "Items in the searchThese vector are found in vec" << endl;

		// lower_bound, finds the first position where 66 can be
		// inserted and still keep sorting. It returns iterator.
		vector<int>::iterator itr = lower_bound(vec.begin(), vec.end(), 66);


		// upper_bound, finds the last position where 9 could be 
		// inserted and still keep the sorting
		itr = upper_bound(vec.begin(), vec.end(), 9);

		// equal_range, returns both upper bound and lower bound.
		pair<vector<int>::iterator, vector<int>::iterator> pairOfItrs;
		pairOfItrs = equal_range(vec.begin(), vec.end(), 9);
	}
#pragma endregion Binary Search
	cout << endl;

#pragma region Merge
	{
		cout << "################### Merge ###################" << endl;
		vector<int> vec = { 8, 9, 9, 10 };
		vector<int> vec2 = { 7, 9, 10 };
		vector<int> vec_out(10);
		// merge(), merges two range of sorted data into one big range 
		// of sorted data. All the duplicates are kept.
		merge(vec.begin(),vec.end(),		// Range #1
			vec2.begin(), vec2.end(),		// Range #2
			vec_out.begin());				// Output
		cout << "After merge(): ";
		for (const int& i : vec_out) cout << i << " ";
		cout << endl;

		// inplace_merge(), takes one range of data as input. But that data 
		// has two range of sorted data. Example:
		//							|-Sorted-|  |---Sorted---|
		vector<int> inplaceMerge = { 1, 2, 3, 4, 1, 2, 3, 4, 5 };
		cout << "Before inplace_merge(): ";
		for (const int& i : inplaceMerge) cout << i << " ";
		cout << endl;
		inplace_merge(inplaceMerge.begin(), inplaceMerge.begin() + 4, inplaceMerge.end());
		cout << "After inplace_merge(): ";
		for (const int& i : inplaceMerge) cout << i << " ";
		cout << endl;
	}
#pragma endregion Merge
	cout << endl;

#pragma region Set Operations
	{
		cout << "################### Set Operations ###################" << endl;
		vector<int> vec = { 8, 9, 9, 10 };	// Sorted
		vector<int> vec2 = { 7, 9, 10 };	// Sorted
		vector<int> vec_out(10);
		// set_union(), takes two range of sorted data and does union on them 
		// and stores the result in another vector. 
		// If item X is there in both vec and vec2, only one X will be in 
		// output vector!!!
		set_union(vec.begin(), vec.end(),	// Input Range #1
			vec2.begin(), vec2.end(),		// Input Range #2
			vec_out.begin());				// Output
		cout << "After set_union(): ";
		for (const int& i : vec_out) cout << i << " ";
		cout << endl;

		vector<int> setInter(10);
		// Intersection of 2 vectors
		set_intersection(vec.begin(), vec.end(),	// Input Range #1
			vec2.begin(), vec2.end(),				// Input Range #2
			setInter.begin());						// Output
		cout << "After set_intersection(): ";
		for (const int& i : setInter) cout << i << " ";
		cout << endl;

		// set_difference, items in vec but not in vec2
		// here 9 and 10 are in vec and also in vec2 but 8 and 9 are in
		// vec but not in vec2.
		vector<int> setDiff(10);
		set_difference(vec.begin(), vec.end(),		// Input Range #1
			vec2.begin(), vec2.end(),				// Input Range #2
			setDiff.begin());						// Output
		cout << "After set_difference(): ";
		for (const int& i : setDiff) cout << i << " ";
		cout << endl;

		// set_symmetric_difference, items which are not present in 
		// each other vectors!!!
		vector<int> setSymDiff(10);
		set_symmetric_difference(vec.begin(), vec.end(),// Input Range #1
			vec2.begin(), vec2.end(),					// Input Range #2
			setSymDiff.begin());						// Output
		cout << "After set_symmetric_difference(): ";
		for (const int& i : setSymDiff) cout << i << " ";
		cout << endl;
}
#pragma endregion Set Operations
	cout << endl;

	/********** Numeric Algorithms **********/
	// Accumulate, inner product, partial sum, adjacent difference

#pragma region Accumulate
	{
		cout << "################### Accumulate ###################" << endl;
		vector<int> vec = { 8, 9, 9, 10 };	

		// 10 + vec[0] + vec[1] + vec[2] + ...
		int x = accumulate(vec.begin(), vec.end(), 10);
		cout << "Accumulated value + 10 : " << x << endl;

		// 10 * vec[0] * vec[1] * vec[2] * ...
		int y = accumulate(vec.begin(), vec.end(), 10, multiplies<int>());
		cout << "Accumulated value * 10 with multiplies: " << y << endl;

	}
#pragma endregion Accumulate
	cout << endl;

#pragma region Inner Product
	{
		cout << "################### Inner Product ###################" << endl;
		vector<int> vec = { 9, 60, 70, 8, 45, 87, 90 };

		// 10 + vec[0]*vec[4] + vec[2]*vec[5] + vec[3]*vec[6] + ...
		int x = inner_product(vec.begin(), vec.begin()+3,	// Range #1
			vec.end()-3,									// Range #2
			10);											// Initial Value
		cout << "inner_product value + 10 : " << x << endl;
	}
#pragma endregion Inner Product
	cout << endl;

#pragma region Partial Sum
	{
		cout << "################### Partial Sum ###################" << endl;
		vector<int> vec = { 9, 60, 70, 8, 45, 87, 90 };
		vector<int> vec2(10);

		cout << "Vector vec:";
		for (const int& i : vec) cout << i << " ";
		cout << endl;
		partial_sum(vec.begin(), vec.end(),
			vec2.begin());
		for (const int& i : vec2) cout << i << " ";
		cout << endl;
	}
#pragma endregion Partial Sum
	cout << endl;

#pragma region Adjacent Difference
	{
		cout << "################### Adjacent Difference ###################" << endl;
		vector<int> vec = { 9, 60, 70, 8, 45, 87, 90 };
		vector<int> vec2(10);

		cout << "Vector vec:";
		for (const int& i : vec) cout << i << " ";
		cout << endl;
		adjacent_difference(vec.begin(), vec.end(),
			vec2.begin());
		for (const int& i : vec2) cout << i << " ";
		cout << endl;
	}
#pragma endregion Adjacent Difference
	cout << endl;

	return 0;
}
