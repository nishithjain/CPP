#include <iostream>
#include <vector>

using namespace std;

/*************************************************************
Reverse Iterator
**************************************************************/

int main(void) 
{	
	// Two ways to declare reverse iterator
	reverse_iterator<vector<int>::iterator> ritr1;
	vector<int>::reverse_iterator ritr2;
	
	// Traversing with reverse iterator
	vector<int> vec = { 4, 5, 6, 7 };
	for (ritr1 = vec.rbegin(); ritr1 != vec.rend(); ++ritr1)
		cout << *ritr1 << " ";
	cout << endl;

	// Convention
	vector<int>::iterator itr;
	vector<int>::reverse_iterator ritr;

	// Converting regular iterator to reverse iterator
	ritr = vector<int>::reverse_iterator(itr);

	// Converting the reverse iterator to iterator is not possible 
	// as shown above. We need to use the reverse iterator member 
	// function base()
	//itr = vector<int>::iterator(ritr);

	itr = ritr.base();

	// BUT THERE IS A DIFFERENCE
	vector<int> aVec = { 1, 2, 3, 4, 5 };
	vector<int>::reverse_iterator aRitr = find(aVec.rbegin(), aVec.rend(), 3);

	cout << "Using Reversion Iterator: " << *aRitr << endl;
	cout << "Converting Reverse iterator to iterator!!!" << endl;
	vector<int>::iterator anotherItr = aRitr.base();
	cout << "Using Iterator after conversion: " << *anotherItr << endl;

/*OUTPUT 
Using Reversion Iterator: 3
Converting Reverse iterator to iterator!!!
Using Iterator after conversion: 4
----------------
This is because of below...
	vec.begin()     itr = ritr.base()  vec.end() 
		|                 |                  |    
		|                 |                  |    
		|                 |                  |    
		v				  v		     		 v    
	   +----------------------------------+       
	   |            | n |n+1|             |       
	   +----------------------------------+       
	 ^               ^                   ^          
	 |               |                   |        
	 |               |                   |        
	 |               |                   |        
vec.rend()         ritr             vec.rbegin()
*/

	// Inserting elements

	//aVec.insert(aRitr.base(), 9);
	//aVec.insert(aRitr, 9);

	return 0; 
}