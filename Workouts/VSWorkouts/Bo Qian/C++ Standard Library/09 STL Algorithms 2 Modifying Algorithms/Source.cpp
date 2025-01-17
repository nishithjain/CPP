#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/************************************************************************
							Value Changing Algorithms
	- copy, move, transform, swap, fill, replace, remove.
************************************************************************/

int main(void)
{
	
#pragma region Copy
	{
		vector<int> vec = { 9, 60, 70, 8, 45, 87, 90 };					// 7 items
		vector<int> vec2 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };			// 11 items
		vector<int>::iterator itr, itr2;
		pair<vector<int>::iterator, vector<int>::iterator> pair_of_itr;

		cout << "################### COPY ###################" << endl;
	
		cout << "vec2 before copy: ";
		for (int& i : vec2) cout << i << " ";
		cout << endl;
		// Copies everything from vec to vec2.
		// vec2 should be at least as big as vec. otherwise it is undefined behavior.
		copy(vec.begin(), vec.end(),			// Source
			vec2.begin());						// Destination
		cout << "vec2 after copy: ";
		for (int& i : vec2) cout << i << " ";
		cout << endl;
	
		// copy_if, copies everything that satisfies the condition
		copy_if(vec.begin(), vec.end(),			// Source
			vec2.begin(),						// Destination
			[](int x) { return x > 80; });		// Condition
		cout << "vec2 after copy_if: ";
		for (int& i : vec2) cout << i << " ";
		cout << endl;
	
		// copy_n, copies n items from vec to vec2
		copy_n(vec.begin(),						// Source
			4,									// Number of items
			vec2.begin());						// Destination
		cout << "vec2 after copy_n: ";
		for (int& i : vec2) cout << i << " ";
		cout << endl;
	
		// copy_backward, copies vec to the end of vec2.
		copy_backward(vec.begin(), vec.end(),	// Source
			vec2.end());						// Destination, here destination range starts with evc2.end()
		cout << "vec2 after copy_backward: ";
		for (int& i : vec2) cout << i << " ";
		cout << endl;
	}
#pragma endregion Copy
	cout << endl;

#pragma region Move
	{
		vector<string> sVec = { "apple", "orange", "pear", "grape" };	// 4 items
		vector<string> sVec2 = { "", "", "", "", "", "" };				// 6 items
		vector<string> sVec3 = { "A", "B", "C", "D" };					// 4 items

		cout << "################### MOVE ###################" << endl;

		// move, moves the items from vec to vec2.
		// If move semantics are defined for element type, elements are moved else
		// they are copied with copy constructor, just like copy.
		move(sVec.begin(), sVec.end(),			// Source
			sVec2.begin());						// Destination
		cout << "sVec2 after move: ";
		for (string& i : sVec2) cout << i << " ";
		cout << endl;

		// move_backward, moves vec3 to end of vec2.
		move_backward(sVec3.begin(), sVec3.end(),	// Source
			sVec2.end());							// Destination
		cout << "sVec2 after move_backward: ";
		for (string& i : sVec2) cout << i << " ";
		cout << endl;
	}
#pragma endregion Move
	cout << endl;

#pragma region Transform
	{
		vector<int> vec = { 9, 60, 70, 8, 45, 87, 90 };					// 7 items
		vector<int> vec2 = { 9, 60, 70, 8, 45, 87, 90 };				// 7 items
		vector<int> vec3 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };			// 11 items
		cout << "################### TRANSFORM ###################" << endl;

		// transforms the result and store it in another place.
		// Below, transform will decrement all the items of vec by 1
		// and stores the result in vec3.
		transform(vec.begin(), vec.end(),				// Source
			vec3.begin(),								// Destination
			[](int x){ return x - 1; });				// Operation
		cout << "vec3 after transform: ";
		for (int& i : vec3) cout << i << " ";
		cout << endl;

		transform(vec.begin(), vec.end(),				// Source #1
			vec2.begin(),								// Source #2
			vec3.begin(),								// Destination
			[](int x, int y){ return x + y; }			// Operation
			);
		cout << "vec3 after transform: ";
		for (int& i : vec3) cout << i << " ";
		cout << endl;
	}
#pragma endregion Transform
	cout << endl;
	
#pragma region Swap Ranges
	{
		vector<int> vec = { 9, 60, 70, 8, 45, 87, 90 };					// 7 items
		vector<int> vec2 = { 9, 60, 70, 8, 45, 87, 90 };				// 7 items
		vector<int> vec3 = { 0, 0, 0, 0, 0, 0, 0 };						// 7 items
		cout << "################### TRANSFORM ###################" << endl;

		cout << "vec3 before swap_ranges: ";
		for (int& i : vec3) cout << i << " ";
		cout << endl;
		swap_ranges(vec.begin(), vec.end(), vec3.begin());
		cout << "vec3 after swap_ranges: ";
		for (int& i : vec3) cout << i << " ";
		cout << endl;
	}
#pragma endregion Swap Ranges
	cout << endl;

#pragma region Fill
{
		vector<int> vec3 = { 0, 0, 0, 0, 0, 0, 0 };						// 7 items
		cout << "################### FILL ###################" << endl;

		cout << "vec3 before fill: ";
		for (int& i : vec3) cout << i << " ";
		cout << endl;
		// Fills the vec3 with 9
		fill(vec3.begin(), vec3.end(), 9);	
		cout << "vec3 after fill: ";
		for (int& i : vec3) cout << i << " ";
		cout << endl;

		// fill_n, will fill n items with certain value
		fill_n(vec3.begin(), 3, 0);
		cout << "vec3 after fill_n: ";
		for (int& i : vec3) cout << i << " ";
		cout << endl;

		// generate takes a number generation function!!!
		generate(vec3.begin(), vec3.end(), rand);
		cout << "vec3 after generate: ";
		for (int& i : vec3) cout << i << " ";
		cout << endl;

		generate_n(vec3.begin(), 3, rand);
		cout << "vec3 after generate_n: ";
		for (int& i : vec3) cout << i << " ";
		cout << endl;
	}
#pragma endregion Fill
	cout << endl;

#pragma region Replace
	{
		vector<int> vec = { 9, 9, 70, 8, 9, 87, 90 };					// 7 items
		vector<int> vec2 = { 9, 60, 70, 8, 45, 87, 90 };				// 7 items
		vector<int> vec3 = { 0, 0, 0, 0, 0, 0, 0 };						// 7 items
		cout << "################### REPLACE ###################" << endl;

		
		cout << "vec before replace: ";
		for (int& i : vec) cout << i << " ";
		cout << endl;
		replace(vec.begin(), vec.end(),					// Data range
			9,											// Old value
			100);										// New value
		cout << "vec after replace: ";
		for (int& i : vec) cout << i << " ";
		cout << endl;

		replace_if(vec.begin(), vec.end(),				// Data range
			[](int x){ return x > 80; },				// Value condition
			999);										// New value
		cout << "vec after replace_if: ";
		for (int& i : vec) cout << i << " ";
		cout << endl;

		replace_copy(vec.begin(), vec.end(),			// Source
			vec3.begin(),								// Destination
			999,										// Value condition
			0);											// New value
		cout << "vec3 after replace_copy: ";
		for (int& i : vec3) cout << i << " ";
		cout << endl;
	}
#pragma endregion Replace
	cout << endl;

#pragma region Remove
{
		vector<int> vec = { 9, 9, 70, 8, 9, 87, 90 };					// 7 items
		vector<int> vec2 = { 9, 60, 70, 8, 45, 87, 90 };				// 7 items
		vector<int> vec3 = { 0, 0, 0, 0, 0, 0, 0 };						// 7 items
		cout << "################### REMOVE ###################" << endl;


		cout << "vec before remove: ";
		for (int i : vec) cout << i << " ";
		cout << endl;
		// removes all 70!!!
		remove(vec.begin(), vec.end(), 70);
		cout << "vec after remove: ";
		for (int i : vec) cout << i << " ";
		cout << endl;

		// We have, remove_if with condition
		// and remove_copy, to copy to other container after removing
		
		// unique, removes consecutive equal elements.
		unique(vec.begin(), vec.end());
		cout << "vec after unique: ";
		for (int i : vec) cout << i << " ";
		cout << endl;

		// We have unique_copy to remove consecutive elements and then
		// copy to other container.
	}

#pragma endregion Remove
	cout << endl;

/************************************************************************
							Order Changing Algorithms
	- reverse, rotate, permute, shuffle
	// They change the order of elements in container, but not necessarily 
	the elements themselves.
************************************************************************/

#pragma region Reverse
	{
		vector<int> vec = { 9, 9, 70, 8, 9, 87, 90 };					// 7 items
		vector<int> vec2 = { 9, 60, 70, 8, 45, 87, 90 };				// 7 items
		vector<int> vec3 = { 0, 0, 0, 0, 0, 0, 0 };						// 7 items
		cout << "################### REVERSE ###################" << endl;

		cout << "vec before reverse: ";
		for (int i : vec) cout << i << " ";
		cout << endl;
		reverse(vec.begin(), vec.end());
		cout << "vec after reverse: ";
		for (int i : vec) cout << i << " ";
		cout << endl;

		reverse_copy(vec.begin(), vec.end(), vec3.begin());
		cout << "vec3 after reverse_copy: ";
		for (int i : vec3) cout << i << " ";
		cout << endl;
	}
#pragma endregion Reverse
	cout << endl;

#pragma region Rotate
	{
		vector<int> vec = { 9, 9, 70, 8, 9, 87, 90 };					// 7 items
		vector<int> vec2 = { 9, 60, 70, 8, 45, 87, 90 };				// 7 items
		vector<int> vec3 = { 0, 0, 0, 0, 0, 0, 0 };						// 7 items
		cout << "################### ROTATE ###################" << endl;

		cout << "vec before rotate: ";
		for (int i : vec) cout << i << " ";
		cout << endl;
		rotate(vec.begin(), vec.begin()+3, vec.end());
		cout << "vec after rotate: ";
		for (int i : vec) cout << i << " ";
		cout << endl;

		rotate_copy(vec.begin(), vec.begin()+3, vec.end(), vec3.begin());
		cout << "vec3 after rotate_copy: ";
		for (int i : vec3) cout << i << " ";
		cout << endl;
	}
#pragma endregion Rotate
	cout << endl;

#pragma region Permute
	{
		vector<int> vec = { 9, 9, 70, 8, 9, 87, 90 };					// 7 items
		cout << "################### PERMUTE ###################" << endl;

		cout << "vec before next_permutation: ";
		for (int i : vec) cout << i << " ";
		cout << endl;
		next_permutation(vec.begin(), vec.end());
		cout << "vec after next_permutation: ";
		for (int i : vec) cout << i << " ";
		cout << endl;

		cout << "vec before prev_permutation: ";
		for (int i : vec) cout << i << " ";
		cout << endl;
		prev_permutation(vec.begin(), vec.end());
		cout << "vec after prev_permutation: ";
		for (int i : vec) cout << i << " ";
		cout << endl;
	}
#pragma endregion Permute
	cout << endl;
#pragma region Shuffel
	{
		vector<int> vec = { 9, 9, 70, 8, 9, 87, 90 };					// 7 items
		cout << "################### SHUFFEL ###################" << endl;

		// Rearrange the data randomly
		cout << "vec before random_shuffle: ";
		for (int i : vec) cout << i << " ";
		cout << endl;
		random_shuffle(vec.begin(), vec.end());
		cout << "vec after random_shuffle: ";
		for (int i : vec) cout << i << " ";
		cout << endl;
	}
#pragma endregion Shuffel
	cout << endl;

	return 0;
}
