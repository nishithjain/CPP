#include <iostream>
#include <unordered_set>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

/*************************************************************
Containers Member Functions vs Algorithm Functions
Containers Member Functions: Functions that work on containers
data.
Algorithm: Also functions that work on containers data.
The question is could there be any duplicate functions between these
two groups?
Answer: YES

List:
List Member Function	Algorithms
void remove(const T)	template<class Comp> void remove_if(Comp);
void unique();			template<class Comp> void unique(Comp);
Void sort();			template<class Comp> void sort(Comp);
void merge(list&);		template<class Comp> void merge(Comp);
void reverse();

Associative Containers:
size_type count(const T&) const;
iterator find(const T&) const;
iterator lower_bound(const T&) const;
iterator upper_bound(const T&) const;
pair<iterator, iterator> equal_range(const T&) const;

Unordered Container:
size_type count(const T&) const;
iterator find(const T&) const;
pair<iterator, iterator> equal_range(const T&) const;

No the question is why there are duplicate function?
- Although there are duplicate functions and have the same purpose,
they are actually different. They do things in different way. So, 
now again the question is which one is better?
**************************************************************/


int main(void) 
{ 
	{
		unordered_set<int> s = { 2, 4, 1, 8, 5, 9 };
		unordered_set<int>::iterator itr;

		// Using member function
		itr = s.find(4);	// O(1)

		// Using algorithm	// O(n)
		// Why algorithm takes O(n)? This is because, algorithm find()
		// Only knows data through iterator. It doesn't know anything
		// about container. It doesn't know whether the data is store in
		// hash table, or in a binary tree or in contiguous array. 
		// The only way to find the element is starting from first iterator
		// and iterate through all the items till the end and find the data.
		// This takes linear time.
		itr = find(s.begin(), s.end(), 4);
	}
	{
		map<char, string> myMap = { { 'S', "Sunday" }, { 'M', "Monday" }, { 'T', "Tuesday" } };

		// Using member function -  O(log(n))
		map<char, string>::iterator itr;
		itr = myMap.find('F');

		// Using Algorithm - O(n)
		// Algorithm find() is much complex, cos, it need two things to
		// find. 'F' and "Friday" and the compare function will be complex.
		itr = find(myMap.begin(), myMap.end(), make_pair('F', "Friday"));
	}

	{
		list<int> s = { 2, 4, 1, 8, 5, 9 };

		// Since list contains unsorted data, the only way to find and 
		// remove the item is to iterate through each item.
		// Using member function - O(n)
		// Member function remove() just tweaks two pointers
/*
	+-----+----> +-----+----> +-----+----> +-----+---> +-----+----> +-----+
	|  2  |      |  4  |      |  1  |      |  8  |     |  5  |      |  9  |
	+-----+ <----+-----+ <----+-----+ <----+-----+ <---+-----+ <----+-----+

	 +-----+----> 
	 |  4  |      
<----+-----+

	+-----+-----------------> +-----+----> +-----+---> +-----+----> +-----+
	|  2  |      	          |  1  |      |  8  |     |  5  |      |  9  |
	+-----+ <-----------------+-----+ <----+-----+ <---+-----+ <----+-----+
*/
		s.remove(4); //s = { 2, 1, 8, 5, 9 };
		list<int>::iterator itr;
		// Using Algorithm - O(n)
		// Algorithm removes the elements by copying and after the removal
		// the content of s will be { 2, 1, 8, 5, 9, 9 }. It has one more
		// 9 at the end. This is because, the algorithm don't know about 
		// the container and it can't remove the element. Then how to remove
		// the another 9? remove() returns the iterator to last element.

		itr = remove(s.begin(), s.end(), 4); //s = { 2, 1, 8, 5, 9, 9 };
		s.erase(itr, s.end());//s = { 2, 1, 8, 5, 9 };
/*
	+-----+----> +-----+----> +-----+----> +-----+---> +-----+----> +-----+
	|  2  |      |  1  |      |  8  |      |  5  |     |  9  |      |  9  |
	+-----+ <----+-----+ <----+-----+ <----+-----+ <---+-----+ <----+-----+
*/
		//To sort, with member functions...
		s.sort();

		// To sort with algorithm, 
		// Below code doesn't work. Because, sort() needs random access
		// iterators. List has bi-directional iterators.
		//sort(s.begin(), s.end());

	}

/*************************************************************
Summary:
1. There are duplicated function between container's member function
and algorithm functions.
2. Prefer member functions over algorithm function with the same name
**************************************************************/

	return 0; 
}