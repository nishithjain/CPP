#include <iostream>
#include <vector>

using namespace std;

/************************************************************************
	Bitwise const-ness/Physical const-ness is what provided by C++ compiler.
	- This checks whether any member variable is getting modified or not.
	Logical const-ness is what is our model.
************************************************************************/

class BigArray
{
private:
	vector<int> aVector;	// Huge Vector
	int accessCounter;		// How many times the vector has been accessed.
	int* v2;				// Another int array
public:
	int getItem(int index) const
	{
		// Using mutable, we can modify accessCounter.
		//accessCounter++;	
		// Using const_cast we can modify accessCounter.
		const_cast<BigArray*>(this)->accessCounter++;
		return aVector[index];
	}

	void setV2Item(int index, int x) const
	{
		*(v2 + index) = x;
	}
};

int main(void)
{
	BigArray b;

	return 0;
}