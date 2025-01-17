#include <iostream>
#include <string>
#include <thread>
#include <future>

using namespace std;

string regularFun()
{
	string str("Hello from FUTURE!!!");
	throw exception("Exception from TASK!!!");
	return str;
}

int main(void)
{
	auto theFuture = async(&regularFun);
	cout << "Hello from main!!!\n";

	try
	{
		string str = theFuture.get();
		cout << str << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}