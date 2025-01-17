#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

/************************************************************************
								Iterators
	- There are 5 categories of iterators
		1. Random Access Iterators: vector, deque, array
************************************************************************/

bool isOdd(int i) { return (i % 2); }

int main(void)
{

#pragma region No 1 Random Access Iterator
	vector<int> aVec;
	aVec.push_back(10);
	aVec.push_back(1);
	aVec.push_back(12);
	aVec.push_back(14);
	aVec.push_back(92);
	aVec.push_back(44);
	aVec.push_back(36);
	aVec.push_back(25);
	// We can access the elements of the container randomly!!!
	// vector, deque, array provides random access iterator
	auto itr = aVec.begin();
	auto itr2 = aVec.end();

	// With random access iterators, we can compare 2 iterators
	//if (itr == itr2)

	// Adding value to iterator
	itr += 5;	// Advance itr by 5
	itr -= 4;	

	++itr;		// faster than itr++
	--itr;

#pragma endregion No 1 Random Access Iterator

#pragma region No 2 Bidirectional Iterator

	// list, set/multiset, map/multimap provides Bidirectional Iterator
	// With bidirectional iterator, we can increment 
	// and decrement the iterator but we cannot add or subtract value
	// to/from the iterator. 
	// We can't compare 2 iterators!!!

	list<int> aList;
	aList.push_front(12);
	aList.push_back(14);
	aList.push_back(92);
	aList.push_back(44);
	aList.push_back(36);
	aList.push_back(25);

	auto aListItr = aList.begin();
	aListItr++;
	aListItr--;

#pragma endregion No 2 Bidirectional Iterator

#pragma region No 3 Forward Iterator
	// Can only be incremented cannot be decremented
	forward_list<int> fList;

	fList.push_front(10);
	fList.push_front(14);
	fList.push_front(92);
	fList.push_front(44);
	fList.push_front(36);
	fList.push_front(25);

	auto fListItr = fList.begin();

	fListItr++;

	//fListItr--;		// Error!!!

#pragma endregion No 3 Forward Iterator

	// Unordered containers provide at least Forward iterator.
	// But they have the option to provide Bidirectional iterator!!!

#pragma region No 4 Input Iterator

	// Read and process values while iterating forward
	// We can read and dereference input iterator but we can't write to it!!!
	/* Both input and output iterator can only move forward */

#pragma endregion No 4 Input Iterator

#pragma region No 5 Output Iterator

	// Output values while iterating forward
	// We can write the values but we can't write to it!!!
	// Output iterator can only move forward

#pragma endregion No 5 Output Iterator

#pragma region Const Iterator
	// Every container has a iterator and a const_iterator
	{
		cout << "########################### CONST_ITERATOR ###########################" << endl;
		set<int>::iterator itr;
		set<int>::const_iterator citr, citr1;	// Read only access to container elements

		set<int> aSetP{ 2, 3, 4, 5, 6, 7, 8, 9, 12, 34, 56, 78, 99 };
		for (citr = aSetP.begin(); citr != aSetP.end(); citr++)
			cout << *citr << " ";
		cout << endl;

		for_each(aSetP.begin(), aSetP.end(), [] (int const& i) { cout << i << " "; });
		cout << endl;

		// Some functions
		//citr = aSetP.begin();
		//citr1 = aSetP.begin();
		//advance(citr, 5);		// Move citr forward 5 spots. -> citr += 5;
		//distance(citr, citr1);	// Measure the distance between citr and citr1
	}
#pragma endregion Const Iterator

#pragma region Iterator Adapter
	
	/************************************************************************
						Iterator Adapter (Predefined Iterator)
		- A special, more powerful iterator
			1. Insert iterator.
			2. Stream iterator.
			3. Reverse iterator.
			4. Move iterator.
	************************************************************************/

#pragma region Insert Iterator

	{
		vector<int> vec1 = { 4, 5 };
		vector<int> vec2 = { 12, 13, 14, 15 };
		vector<int>::iterator it = find(vec2.begin(), vec2.end(), 14);
		insert_iterator<vector<int>> i_itr(vec2, it);

		copy(vec1.begin(), vec1.end(), i_itr);	//{ 12, 13, 4, 5, 14, 15 }
		
		for (auto itr3 = vec2.begin(); itr3 != vec2.end(); itr3++)
			cout << *itr3 << " ";
		cout << endl;
		// There are other insert iterators
		//	1. back_insert_iterator - inserts at the back
		//	2. front_insert_iterator - inserts at the end
	}
#pragma endregion Insert Iterator

#pragma region Stream Iterator
	// Is to iterate through the data of stream
	{
		cout << "########################### STREAM ITERATOR ###########################" << endl;
		vector<int> vec2 = { 12, 13, 14, 15 };
		// Copies the content of vec2 to output stream.
		copy(vec2.begin(), vec2.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
#pragma endregion Stream Iterator

#pragma region Reverse Iterator
	// To traverse the container in the reverse order.
	{
		cout << "########################### REVERSE ITERATOR ###########################" << endl;
		vector<int> vec2 = { 12, 13, 14, 15 };
		reverse_iterator<vector<int>::iterator> ritr;

		// rbegin() and rend() are the functions provided by STL
		for (ritr = vec2.rbegin(); ritr != vec2.rend(); ritr++)
			cout << *ritr << " ";
		cout << endl;

	}
#pragma endregion Reverse Iterator


#pragma endregion Iterator Adapter

#pragma region Algorithms

	{
		cout << "########################### ALGORITHMS ###########################" << endl;
		vector<int> vec2 = { 12, 66, 88, 7, 16, 18, -9, 33, 77 };

		auto itr = min_element(vec2.begin(), vec2.end());
		cout << "Minimum in the vector is: " << *itr << endl;

		/************************************************************************
			- Algorithm functions needs to know the where the data is to work
			on and that data is often time is the range of data represented
			by pair of iterators
			************************************************************************/
		// Note 1:		
		{
			cout << "########################### Note 1 ###########################" << endl;

			// Algorithms always process range in a half-open way. This means
			// it includes first item, but not include last item.
			// Example:
			// vec2 = { 12, 66, 88, 7, 16, 18, -9, 33, 77 };
			for (auto it = vec2.begin(); it != vec2.end(); it++)
				cout << *it << " ";
			cout << endl;
			auto itr1 = min_element(vec2.begin(), vec2.end()); // itr1 points to -9
			// vec2.begin() points to 12 which is included
			// itr1 points to -9 which is not included
			sort(vec2.begin(), itr1); // [begin, end)
			// vec2 = { 7, 12, 16, 18, 66, 88, -9, 33, 77 }
			for (auto it = vec2.begin(); it != vec2.end(); it++)
				cout << *it << " ";
			cout << endl;

			reverse(itr1, vec2.end());	// vec2 = { 7, 12, 16, 18, 66, 88, 77, 33, -9 }
			for (auto it = vec2.begin(); it != vec2.end(); it++)
				cout << *it << " ";
			cout << endl;
		}
		// Note 2:
		{
			cout << "########################### Note 2 ###########################" << endl;
			// Sometimes algorithms needs not only one range of data, it needs 
			// 2 range of data
			vector<int> vec = { 12, 66, 88, 7, 16, 18, -9, 33, 77 };
			vector<int> vec2(10);

			cout << "Original vector is: ";
			for (auto it = vec.begin(); it != vec.end(); it++)
				cout << *it << " ";
			cout << endl;

			auto itr = find(vec.begin(), vec.end(), 7);
			copy(itr, vec.end(),	// This is the source
				vec2.begin());		// Destination
			for (auto it = vec2.begin(); it != vec2.end(); it++)
				cout << *it << " ";
			cout << endl;
		}

	}

	{	// Algorithm with function
		cout << "########################### Note 3 ###########################" << endl;
		vector<int> vec = { 12, 66, 88, 7, 16, 18, -9, 33, 77 };
		cout << "Original vector is: ";
		for (auto it = vec.begin(); it != vec.end(); it++)
			cout << *it << " ";
		cout << endl;
		auto fit = find_if(vec.begin(), vec.end(), isOdd);
		cout << "First Odd Element:  " << *fit << endl;
	}
	
	{	// Algorithms can even with C++ native array
		cout << "########################### Note 4 ###########################" << endl;
		int myArray[10] = { 1, 2, 3, 4, 50, 9, 8, 7, 6 };
		for (int i : myArray) cout << i << " ";
		cout << endl;
		sort(myArray, myArray + (sizeof(myArray) / sizeof(int)));
		for (int i : myArray) cout << i << " ";
		cout << endl;
	}

#pragma endregion Algorithms

return 0;
}