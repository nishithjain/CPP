#include <iostream>

using namespace std;

struct MyStruct
{
	MyStruct(){};
	MyStruct(int x, int y):_x(x), _y(y){}
	int _x;
	int _y;
};

//void myFunction(MyStruct aStruct)
//{
//	cout << "Inside myFunction(MyStruct aStruct)" << endl;
//	cout << "MyStruct::x " << aStruct.x << endl;
//	cout << "MyStruct::y " << aStruct.y << endl;
//}

// We can only call it with LVALUE
void myFunction(MyStruct& aStruct)
{
	cout << "Inside myFunction(MyStruct& aStruct)" << endl;
	cout << "MyStruct::x " << aStruct._x << endl;
	cout << "MyStruct::y " << aStruct._y << endl;
}

// We can call it with an RVALUE and an LVALUE
void myFunction(const MyStruct& aStruct)
{
	cout << "Inside myFunction(const MyStruct& aStruct)" << endl;
	cout << "MyStruct::x " << aStruct._x << endl;
	cout << "MyStruct::y " << aStruct._y << endl;
}

// We can only call it with RVALUE
// Why someone want to modify an RVALUE which is about to die. 
void myFunction(MyStruct&& aStruct)
{
	cout << "Inside myFunction(MyStruct&& aStruct)" << endl;
	cout << "MyStruct::x " << aStruct._x << endl;
	cout << "MyStruct::y " << aStruct._y << endl;
}

int main(void)
{
	MyStruct aStruct{ 5, 6 };

	myFunction(aStruct);
	myFunction(MyStruct(5,6));

	return 0;
}