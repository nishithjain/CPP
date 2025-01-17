#include <iostream>
#include <set>
#include <algorithm>

using namespace std;


class Lsb_less
{
public:
	bool operator()(int x, int y)
	{
		return ((x % 10) < (y % 10));
	}
};

int main(void) 
{ 
	set<int, Lsb_less> s = { 21, 23, 26, 27 };
	set<int, Lsb_less>::iterator itr1, itr2;

	// itr1 will be pointing to s.end(). 
	// Algorithm function will return the end
	itr1 = find(s.begin(), s.end(), 36);

	// itr2 will be pointing 26!!!
	itr2 = s.find(36);


	// This is because, the Algorithm find uses if(x == y)
	// The member function uses if( !(x<y) && !(y<x) )
	return 0; 


}

/*************************************************************
If the function is using operator "<" or its like, it's checking equivalence
- Typically it's algorithm that works with sorted data, or a member 
function of a container with sorted data, such as associative container.
- If the function is using operator"==" or its like, it's checking equality
- Typically the data is not required to be sorted

Algorithms of equality
search();
find_end();
find_first_of();
adjacent_search();

Algorithms of equivalence:
binary_search();
includes();
lower_bound();
upper_bound();
**************************************************************/