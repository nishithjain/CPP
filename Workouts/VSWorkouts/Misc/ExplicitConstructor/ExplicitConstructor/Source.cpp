#include <iostream>
using namespace std;

class MyClass
{
public:
	explicit MyClass(int x) : _x(x) { }
	explicit MyClass(char ch) : _ch(ch) { }

	~MyClass() { }
	int getX(void) const { return _x; }
	char getCh(void) const { return _ch; }

private:
	int _x;
	char _ch;
};

void printMyClassX(MyClass temp)
{
	cout << "Value of MyClass::_x = " << temp.getX() << endl;
}

int main(void)
{
	// printMyClassX(45); // Compiler will throw error
	MyClass temp(45);
	printMyClassX(temp);

	return 0;
}