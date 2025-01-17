#include <iostream>
#include <tuple>
#include <string>
#include <map>

using namespace std;

/*************************************************************
When to Use Tuple?
	- We already have structure which does the same thing as 
	tuple. Which one should we use and when?
**************************************************************/
tuple<string, int> getNameAge();
int main(void) 
{ 
	{
		struct Person
		{
			string name;
			int age;
		};
		tuple<string, int> t;

		Person p = { "Nishith", 32 };

		get<0>(t) = "Nishith";
		get<1>(t) = 32;

		// By looking at the code we can say that p.name is name
		// and p.age is age and if we mouse hover over p, it says
		// p is person. But tuple doesn't tell anything!!!.
		// So by using struct, we can make the code more readable.
		cout << p.name << " " << p.age << endl;
		// If the code is 1000s of line, I have to think about what is
		// store at position 0 of tuple!!! Then why do we need a tuple?
		cout << get<0>(t) << " " << get<1>(t) << endl;
	}

	{
		string name;
		int age;

		// Tuple can be used as a one-time only structure to transfer 
		// a group of data from one function to another instead of 
		// creating a dedicated structure for this purpose.
		tie(name, age) = getNameAge();
		cout << name << " " << age << endl;

		// We can take advantage of comparison function of tuple
		tuple<int, int, int> time1, time2;
		if (time1 > time2)
			cout << "time1 is greater than time2" << endl;

		// Multi index map
		map<tuple<int, char, float>, string>m;
		m[make_tuple(2, '1', 2.3)] = "Faith will move mountains";

		// If we want to rotate values 
		int a = 5, b = 6, c = 7;
		cout << "A: " << a << " B: " << b << " C: " << c << endl;
		tie(b, c, a) = make_tuple(a, b, c);
		cout << "A: " << a << " B: " << b << " C: " << c << endl;
	}

	return 0; 
}

tuple<string, int> getNameAge()
{
	//....
	//....
	return make_tuple("Nishith", 32);
}
