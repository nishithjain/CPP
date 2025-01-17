#include <iostream>
#include <tuple>
#include <string>

using namespace std;

/*************************************************************
- Pair is used to store a pair of values of different types.
- A Tuple can be considered as an extended pair. Instead of
storing 2 values, it can be used to store arbitrary number of
values with arbitrary data types.
**************************************************************/

int main(void)
{
	std::pair<int, string> p = make_pair(23, "hello");

	cout << p.first << " " << p.second << endl;

	// Creating a tuple
	tuple<int, string, char> t(32, "Penny wise", 'a');

	// To get the values stored in the tuple
	cout << get<0>(t) << endl;
	cout << get<1>(t) << endl;
	cout << get<2>(t) << endl;

	// To change the values in the tuple
	// The get<1>(t) returns a reference to tuple!!!
	get<1>(t) = "Pound Foolish";

	string& s = get<1>(t);
	s = "Patience is virtue!!!";
	cout << get<0>(t) << endl;
	cout << get<1>(t) << endl;
	cout << get<2>(t) << endl;

	// get<3> will not work. It wont compile. get<> needs a compile
	// time constant. get<i> also will not compile!!!
	// cout << get<3>(t) << endl;
	int i = 1;
	//cout << get<i>(t) << endl;


	tuple<int, string, char> t2;
	t2 = make_tuple(12, "Cat", 'd');

	// This does lexicographical comparison!!!
	if (t > t2)
	{
		cout << "t is larger than t2" << endl;
		// Member by member copy!!!
		t = t2;
	}

	// Tuple can store references!!!

	string st = "In for a penny";
	tuple<string&> t3(st);
	cout << "The string (before) : " << st << endl;
	get<0>(t3) = "In for a pound!!!";
	cout << "The string (after) : " << st << endl;

	// To extract the values of tuple, we can use below technique
	{
		int x;
		string y;
		char z;

		make_tuple(ref(x), ref(y), ref(z)) = t2;
		cout << "X: " << x << endl;
		cout << "Y: " << y << endl;
		cout << "Z: " << z << endl;
		// Same as the above
		std::tie(x, y, z) = t2;
		// We can ignore a value using tie()
		std::tie(x, std::ignore, z);
	}

	// Concatenating tuple
	{
		// t4 is a tuple<int, string, char, string> since t3 is tuple of
		// string&
		auto t4 = std::tuple_cat(t2, t3);
	}

	return 0; 
}