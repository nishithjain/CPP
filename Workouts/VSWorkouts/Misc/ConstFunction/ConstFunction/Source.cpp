#include <iostream>
using namespace std;

class ToExplanConstFunction
{
private:
	mutable int count = 0;
	int anotherVariable = 0;
public:
	void modify(void) const
	{
		count++;
	}
	void myFunction()
	{
		count++;
		cout << "Function: count value" << count << endl;
	}

	void myFunction() const
	{
		count++;
		modify();
		//anotherVariable++;
		cout << "ConstFunction: count value" << count << endl;
	}
};
int main(void)
{
	ToExplanConstFunction x;
	x.myFunction();

	const ToExplanConstFunction y;
	y.myFunction();

	return 0;
}