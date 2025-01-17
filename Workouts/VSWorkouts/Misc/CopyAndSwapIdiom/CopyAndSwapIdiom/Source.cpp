/************************************************************************
The rule of three/The Big Three
	If you need to explicitly declare either the destructor, copy constructor 
	or copy assignment operator yourself, you probably need to explicitly 
	declare all three of them.
************************************************************************/
/************************************************************************
Copy And Swap Idiom
Why do we need it?
Any class that manages a resource needs to implement The Big Three. 
While the goals and implementation of the copy-constructor and destructor
are straightforward, the copy-assignment operator is arguably the most nuanced
and difficult. How should it be done? What pitfalls need to be avoided?
The copy-and-swap idiom is the solution, and elegantly assists the 
assignment operator in achieving two things: avoiding code duplication, 
and providing a strong exception guarantee.

How does it work?
Conceptually, it works by using the copy-constructor's functionality to 
create a local copy of the data, then takes the copied data with a swap function, 
swapping the old data with the new data. The temporary copy then destructs, 
taking the old data with it. We are left with a copy of the new data.

In order to use the copy-and-swap idiom, we need three things: a working 
copy-constructor, a working destructor and a swap function.
************************************************************************/
#include <iostream>
#include <algorithm>	// copy
#include <cstddef>		// size_t
using namespace std;

class myArray
{
private:
	size_t mSize;
	int* mArray;
public:
	// (default) constructor
	myArray(int value, size_t size = 0) : 
		mSize(size), mArray(mSize ? new int[mSize]() : 0)
	{ 
		for (int i = 0; i < mSize; i++)
		{
			mArray[i] = value;
		}
	}
	// copy-constructor
	myArray(const myArray& other) : 
		mSize(other.mSize), mArray(mSize ? new int[mSize] : 0) 
	{
		// note that this is non-throwing, because of the data
		// types being used; more attention to detail with regards
		// to exceptions must be given in a more general case, however
		copy(other.mArray, other.mArray + mSize, mArray);
	}
	// destructor
	~myArray() { delete[] mArray; }
	
	friend void swap(myArray& first, myArray& second) // nothrow
	{
		// enable ADL (not necessary in our case, but good practice)
		using swap;
		// by swapping the members of two classes,
		// the two classes are effectively swapped
		swap(first.mSize, second.mSize);
		swap(first.mArray, second.mArray);
	}
	myArray& operator=(myArray other) // (1)
	{
		swap(*this, other); // (2)
		return *this;
	}

	void display(void)
	{
		cout << "------" << endl;
		for (int i = 0; i < mSize; i++) cout << mArray[i] << endl;
		cout << "------" << endl;
	}
};

int main(void)
{
	myArray temp(555, 5);
	myArray temp1(777, 7);
	myArray temp2(666, 6);

	temp.display();
	temp1.display();
	temp2.display();
	
	temp = temp1 = temp2;
	
	temp.display();
	temp1.display();
	temp2.display();

	return 0;
}
