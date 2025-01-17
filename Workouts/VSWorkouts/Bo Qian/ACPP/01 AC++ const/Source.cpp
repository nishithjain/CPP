#include <iostream>

using namespace std;

/************************************************************************
	const:
		- A "compile time" constraint that an object cannot be modified.
	Benefits
		a) Guards against inadvertent write to the variable.
		b) Self documenting - Telling the reader of the code that the variable
			is not modified.
		c) Enables compiler to do more optimization, making code tighter.
		d) const means the variable can be put in ROM.
************************************************************************/
int main(void)
{	
	const int i = 9;
	//i = 6; // expression must be a modifiable lvalue

	//			   +--------------+
	//			   |		      |
	//			   | +--------->  |
	//			   | |		    | |
	//			   | | +------+ | |
	//			   | | |	  | | |
	//			   + + ^      v | |
	//		const int* p1 = &i; | |		// Data is constant but pointer is not
	//		^      ^ ^        + | |		
	//		|	   | +--------+ | |
	//		|	   |            | |
	//		|	   +------------+ |
	//		|					  |
	//		+---------------------+
	
	//		   +-------------------->
	//		   |                    |
	//		   |   +------------>   |
	//		   |   |		    |   |
	//		   |   |   +----+   |   |
	//		   |   |   |    |   |   |
	//		   +   +   +    |   |   |
	//		int* const p2;  |   |   |	// Pointer is constant
	//		 ^ ^   ^        |   |   |
	//		 | |   +--------+   |   |
	//		 | |				|   |
	//		 | +----------------+   |
	//		 |						|
	//		 +----------------------+

	/*********************************************
		If const is on the left of *, data is const
		If const is on the right of *, pointer is const
	*********************************************/

	const int aConstInt = 9;
	// If we want to change the value of aConstInt, we can use const_cast
	const_cast<int&>(aConstInt) = 6;

	int j = 9;		// j is not const.
	// static_cast will make the j const
	// static_cast<const int&>(j) = 7;

	return 0;
}