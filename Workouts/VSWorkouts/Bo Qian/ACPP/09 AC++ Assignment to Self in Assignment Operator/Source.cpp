#include <iostream>
#include <string>

using namespace std;

/************************************************************************
			Assignment of self in assignment operator
************************************************************************/

#pragma region Solution 1
//class collar
//{
//public:
//	string _collar;
//};
//
//class Dog
//{
//	collar* ptrCollar;
//public:
//	Dog& operator=(const Dog& rhs)
//	{
//		if (this == &rhs)
//			return *this;
//		//delete ptrCollar;
//		// What happens if the copy constructor throws an exception?
//		// The ptrCollar has already been deleted. In order to avoid this
//		// delete ptrCollar after successful construction.
//		collar* pOriginalCollar = ptrCollar;
//		ptrCollar = new collar(*rhs.ptrCollar);
//		delete pOriginalCollar;
//		return *this;
//	}
//};
#pragma endregion Solution 1

#pragma region Solution 2
class collar
{
public:
	string _collar;
};

class Dog
{
	collar* ptrCollar;
public:
	// Delegates the assignment operator to collar class.
	Dog& operator=(const Dog& rhs)	
	{								// Member by member copying of collar 								
		*ptrCollar = *rhs.ptrCollar;//				OR
	}								// call collar's operator=
};
#pragma endregion Solution 2
int main(void)
{
	return 0;
}