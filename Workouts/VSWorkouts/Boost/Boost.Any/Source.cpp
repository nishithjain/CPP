#include <iostream>
#include <vector>
#include <boost/any.hpp>

using namespace std;
using namespace boost;

int main(void)
{
	any w;
	any x{ 2.0 };
	vector<any> y{ 75, "Nishith" };
	any z{ string("NishithJain") };

	if (!x.empty())
		cout << x.type().name() << endl;

	int a = any_cast<int>(y[0]);
	cout << "Value of a: " << a << endl;

	try
	{
		int b = any_cast<int>(y[1]);
	}

	catch (const bad_any_cast& e)
	{
		cout << e.what() << endl;
	}

	for (any a : y)
	{
		int* value = any_cast<int>(&a);
		if (value != nullptr)
			cout << *value << endl;

		const char** text = any_cast<const char*>(&a);
		if (text != nullptr)
			cout << *text << endl;
	}

	return 0;
}