#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(void) 
{ 
	{
		multiset<int> c = { 1, 4, 6, 1, 1, 1, 1, 12, 18, 16 };
		cout << "###################### Multiset ######################" << endl;


		//for (multiset<int>::iterator itr = c.begin(); itr != c.end(); ++itr)
		//{
		//	if (*itr == 1)
		//	{
		//		c.erase(itr);
		//		cout << "Erased one item of " << *itr << endl;
		//	}
		//}

		for (multiset<int>::iterator itr = c.begin(); itr != c.end(); ++itr)
		{
			if (*itr == 1)
			{
				cout << "Erased one item of " << *itr << endl;
				c.erase(itr++);
			}
			else
			{
				itr++;
			}
		}
	}
	{
		cout << "###################### Vector ######################" << endl;
		vector<int> c = { 1, 4, 6, 1, 1, 1, 1, 12, 18, 16 };

		for (auto itr = c.begin(); itr != c.end(); ++itr)
		{
			if (*itr == 1)
			{
				cout << "Erased one item of " << *itr << endl;
				itr = c.erase(itr);
			}
			else
			{
				itr++;
			}
		}
	}
	return 0; 
}
/*************************************************************
Summary:
Sequence container and unordered container: itr = c.erase(itr);
Associative container:	c.erase(itr++);
**************************************************************/