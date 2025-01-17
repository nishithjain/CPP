#include <iostream>
#include <vector>
#include <deque>

using namespace std;

/*************************************************************
Vector vs. Deque
Vector can grow at only one end.
Deque can grow at both the ends.
		  +---------------------------+           
		  |          VECTOR           -------> 
		  +---------------------------+           
												  
		  +---------------------------+           
  <-------            DEQUE            -------->
		  +---------------------------+           

	Which one to use?
**************************************************************/

class Dog{ };


int main(void) 
{ 
#pragma region Vector 
	{
		vector<int> vec = { 2, 3, 4, 5 };
		cout << "Size of vec: " << vec.size() << endl;
		cout << "Capacity of vec: " << vec.capacity() << endl;

		vec.push_back(6);
		cout << "Size of vec: " << vec.size() << endl;
		cout << "Capacity of vec: " << vec.capacity() << endl;
		/******************
		OUTPUT
		Size of vec: 4
		Capacity of vec: 4
		Size of vec: 5
		Capacity of vec: 6	// Capacity is more here
		*******************/

		/******************
		Why the capacity is more in the later case?
		+---+---+---+---+
		| 2 | 3 | 4 | 5 | here vec.size() == vec.capacity()
		+---+---+---+---+
		vec.push_back(6); Now there is no space to push the data into the
		vector. It creates new vector which is 1.5 capacity of original.
		The old vector is deleted and space is released and involves the
		process of reallocation.
		+---+---+---+---+---+---+
		| 2 | 3 | 4 | 5 | 6 |   |
		+---+---+---+---+---+---+

		VECTOR CAPACITY GROWS EXPONENTIALLY!!!

		DRAWBACKS:
		1. Expensive reallocation.
		2. Requires contiguous memory.

		*******************/
	}
	{
		// 6 Dogs are created with default constructor!!!
		vector<Dog> vec(6);
		cout << "Size of vec: " << vec.size() << endl;
		cout << "Capacity of vec: " << vec.capacity() << endl;

		// vec.size() == 0 and vec.capacity() == 0
		vector<Dog> vec2;
		vec2.resize(6);	// 6 Dogs are created with default constructor!!!
		cout << "Size of vec2: " << vec.size() << endl;
		cout << "Capacity of vec2: " << vec.capacity() << endl;

		vector<Dog> vec3;
		// reserve() function increase the capacity but not the size.
		vec3.reserve(6);	// No Dog's are constructed
		cout << "Size of vec2: " << vec.size() << endl;
		cout << "Capacity of vec2: " << vec.capacity() << endl;

	}

	/*************************************************************
	Strategy of minimizing reallocation:

	1. If the maximum number of item is known, use reserve(MAX);
	2. If the end of grow is know, reserve as much memory as we can.
	Once all data is inserted, trim off the rest of data.
	To trim off,
	vec.shrink_to_fit();	// C++11
	vector<int>(vec).swap(vec);	// C++03
	**************************************************************/
#pragma endregion Vector

#pragma region Deque

/*
		  +---------------------------+           
  <-------            DEQUE            -------->
		  +---------------------------+           

	Underlying implementation of Deque
- A deque starts with fixed sized array to hold the data and when the 
array is full and there is no more space for new elements to PUSH_BACK(),
It allocates another fix sized array after it...
- If there is no more space left to PUSH_FRONT(), it allocates another
fix sized array before it...

			+---+   +---+   +---+
			|   |   |   |   |   |
			+---+   +---+   |   |
			|   |   |   |   | ^ |
			+---+   +---+   | | |
			|   |   |   |   | | |
  <-------  +---+   +---+   |   | ------->
			|   |   |   |   |   |
			|   |   +---+   +---+
			| | |   |   |   |   |
			| | |   +---+   +---+
			| v |   |   |   |   |
			|   |   +---+   +---+
			|   |   |   |   |   |
			+---+   +---+   +---+

	- Deque grows linearly with a fixed size...
OBSERVATION:
	- No reallocation. 
	deque has no reserve() and capacity()
	- Slightly slower than vector because
	1. More complex data structure.
	2. Locality (Not in contiguous memory, more page faults)
*/

#pragma endregion Deque

#pragma region Which one to use
/*************************************************************
Deque or Vector, which one to use?
	- Need to push_front() a lot?-> deque is the answer.
	- Performance is important?	-> vector is the answer.

Still lot more things needs to be considered...

Note 1: Element Type
	- When the elements are not of trivial types(Built in data types),
	deque is not much less efficient than vector.

Note 2: Memory availability
	- Allocation of large contiguous memory is a problem? -> deque
	cos, vector requires large contiguous amount of memory.

Note 3: Frequency of unpredictable growth.
Example:
	vector<int> vec;
	for (int x = 0; x < 1025; x++)
		vec.push_back(x);	// To push_back 1024 elements, there
		will be a minimum of 11 REALLOCATION.
	- We know REALLOCATION is costly. To prevent this we can use
	vec.reserve(1024);
	- If the frequency of growth is unpredictable, ->deque

Note 4: Invalidation of pointers/references/iterators because
	of growth.
	##############################
	vector<int> vec = { 2, 3, 4, 5 };
	int* p = &vec[3];
	vec.push_back(6);
	cout << *p << endl;	// UNDEFINED BEHAVIOR!!!
	- The push_back(6) invalidates all the pointer and iterators.
	- Hence the above code is UNDEFINED BEHAVIOR!!!

	deque<int> deq = { 2, 3, 4, 5 };
	p = &deq[3];
	deq.push_back(6);
	cout << *p << endl;	// OK : 5

	- For deque, if it is growing at both ends, all the pointers will
	not be invalidated.
	- But if we insert/remove in the middle of the deque, the pointers
	or references or iterators will be invalidated!!!
	##############################

Note 5: Vector's unique function : Portal to C language
Example:
	vector<int> vec = { 2, 3, 4, 5 };
	void cFunction(const int* arr, int size);
	cFunction(&vec[0], vec.size());

	// Passing data from a list to C
	list<int> myList;
	// Copy the list data to vector and call the cFunction()
	vector<int> vec(myList.begin(), myList.end());
	cFunction(&vec[0], vec.size());
**************************************************************/
#pragma endregion Which one to use


	return 0; 
}
/***************************************************************
SUMMARY
1. Frequent push_front()	- deque
2. Build-in data type		- vector
3. Not build-in data type	- deque
4. Contiguous memory		- deque
5. Unpredictable growth		- deque
6. Pointer integrity		- deque
7. Frequently passed to C 	- vector
***************************************************************/