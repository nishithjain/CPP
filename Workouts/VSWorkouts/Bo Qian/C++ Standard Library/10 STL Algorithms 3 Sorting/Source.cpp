#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using namespace std;

/************************************************************************
								Sorting 
	- Sorting algorithms requires random access iterators
	- vector, deque, container array and native array
	- List and unordered containers can't be sorted.
	- Associative container doesn't need sort, because they are already
	sorted.
************************************************************************/

bool leastSignificantDigit(int x, int y) { return ((x % 10) < (y % 10)); }
bool lessThan10(int x) { return (x < 10); }

int main(void)
{
#pragma region Sort
	{
		vector<int> vec = { 9, 1, 10, 2, 45, 3, 90, 4, 9, 5, 8 };		// 11 item;
		cout << "################### SORT ###################" << endl;
		cout << "vec before sort: ";
		for (int& i : vec) cout << i << " ";
		cout << endl;
		sort(vec.begin(), vec.end());	// Default comparison function if operator <
		cout << "vec after sort: ";
		for (int& i : vec) cout << i << " ";
		cout << endl;

		// If we want to sort according to the last digit, then
		// we can declare a function to do that...
		sort(vec.begin(), vec.end(), leastSignificantDigit);
		cout << "vec after leastSignificantDigit: ";
		for (int& i : vec) cout << i << " ";
		cout << endl;
	}
#pragma endregion Sort
	cout << endl;

#pragma region Partial Sort

	{
		vector<int> vec = { 9, 60, 70, 8, 45, 87, 90, 69, 69, 55, 7 };
		cout << "################### PARTIAL SORT ###################" << endl;

		cout << "vec before partial_sort: ";
		for (int& i : vec) cout << i << " ";
		cout << endl;
		// Find top 5 students according to their test scores
		// greater<int>() - greater<int> is a functor, we need to default construct it
		partial_sort(vec.begin(), vec.begin() + 5, vec.end(), greater<int>());
		cout << "vec after partial_sort: ";
		for (int& i : vec) cout << i << " ";
		cout << endl;

		partial_sort(vec.begin(), vec.begin() + 5, vec.end());
		cout << "vec after partial_sort :Overloaded : ";
		for (int& i : vec) cout << i << " ";
		cout << endl;
	}
#pragma endregion Partial Sort
	cout << endl;

#pragma region nTh Element
	{
		vector<int> vec = { 9, 60, 70, 8, 45, 87, 90, 69, 69, 55, 7 };
		cout << "################### nth ELEMENT ###################" << endl;

		cout << "vec before nth_element: ";
		for (int& i : vec) cout << i << " ";
		cout << endl;
		// Find top 5 students according to their test scores, but we don't care
		// their order.
		// greater<int>() - greater<int> is a functor, we need to default construct it
		nth_element(vec.begin(), vec.begin() + 5, vec.end(), greater<int>());
		cout << "vec after nth_element: ";
		for (int& i : vec) cout << i << " ";
		cout << endl;
	}
#pragma endregion nTh Element
	cout << endl;

#pragma region Partition
	{
		vector<int> vec = { 9, 60, 70, 8, 45, 87, 90, 69, 69, 55, 7 };
		vector<int> vec1 = { 9, 60, 70, 8, 45, 87, 90, 69, 69, 55, 7 };

		cout << "################### PARTITION ###################" << endl;

		cout << "vec before partition: ";
		for (int i : vec) cout << i << " ";
		cout << endl;
		// We want to move the students whose score is less 
		// than 10 to the front
		partition(vec.begin(), vec.end(), lessThan10);
		cout << "vec after partition: ";
		for (int i : vec) cout << i << " ";
		cout << endl;

		cout << "vec1 before stable_partition: ";
		for (int i : vec1) cout << i << " ";
		cout << endl;
		stable_partition(vec1.begin(), vec1.end(), lessThan10);
		cout << "vec1 after stable_partition: ";
		for (int i : vec1) cout << i << " ";
		cout << endl;
	}
#pragma endregion Partition
	cout << endl;

#pragma region Heap Algorithm
	//HEAP ALGORITHMS
	{
		vector<int> vec = { 9, 1, 10, 2, 45, 3, 90, 4, 9, 5, 8 };
		cout << "################### HEAP ###################" << endl;

		cout << "vec before make_heap: ";
		for (int i : vec) cout << i << " ";
		cout << endl;
		make_heap(vec.begin(), vec.end());
		cout << "vec after make_heap: ";
		for (int i : vec) cout << i << " ";
		cout << endl;

		// Remove largest element from the heap.
		// pop_heap, 
		//	1. Swap vec[0] with last item vec[size-1]
		//	2. Heapify [vec.begin(), vec.end()-1)
		pop_heap(vec.begin(), vec.end());
		cout << "vec after pop_heap: ";
		for (int i : vec) cout << i << " ";
		cout << endl;
		vec.pop_back();
		cout << "vec after vec.pop_back(): ";
		for (int i : vec) cout << i << " ";
		cout << endl;

		// Add new element
		vec.push_back(100);
		push_heap(vec.begin(), vec.end());
		cout << "vec after vec.push_back(100): ";
		for (int i : vec) cout << i << " ";
		cout << endl;

		// Heap Sorting
		vector<int> vec1 = { 9, 1, 10, 2, 45, 3, 90, 4, 9, 5, 8 };
		cout << "vec1 before sort_heap: ";
		for (int i : vec1) cout << i << " ";
		cout << endl;
		make_heap(vec1.begin(), vec1.end());
		sort_heap(vec1.begin(), vec1.end());
		cout << "vec1 after sort_heap: ";
		for (int i : vec1) cout << i << " ";
		cout << endl;
	}
#pragma endregion Heap Algorithm
	cout << endl;
	
	return 0;
}