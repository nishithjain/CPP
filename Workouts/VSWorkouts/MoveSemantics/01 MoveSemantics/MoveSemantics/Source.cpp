#include <iostream>
#include <vector>

class MyMoveClass
{
public:
	int _a;

	MyMoveClass(int a) : _a(a)
	{
		std::cout << "Inside constructor" << std::endl;
	}
	MyMoveClass(const MyMoveClass& temp)
	{
		this->_a = temp._a;
		std::cout << "Inside Copy" << std::endl;
	}
	MyMoveClass(MyMoveClass&& tmp)
	{
		std::cout << "Inside Move" << std::endl;
		this->_a = tmp._a;
		tmp._a = 0;
	}
	MyMoveClass& operator=(MyMoveClass&& that)
	{
		std::cout << "Inside Move assignment" << std::endl;
		this->_a = that._a;
		return *this;
	}
	~MyMoveClass()
	{
		std::cout << "Inside destructor : " << _a << std::endl;
	}
};


MyMoveClass aFunction(void)
{
	//std::cout << "Inside aFunction" << std::endl;
	MyMoveClass temp(99);
	return temp;
}

int main(void)
{
	std::vector<MyMoveClass> temp;

	MyMoveClass a1(1), a2(2), a3(3), a4(4);

	temp.push_back(a1);
	temp.push_back(a2);
	temp.push_back(a3);
	temp.push_back(a4);

	std::cout << "Printing\n";

	for (auto tem : temp)
		std::cout << "Value :" << tem._a << std::endl;

	MyMoveClass aObject = aFunction();
	MyMoveClass bObject(55);
	bObject = aFunction();

	return 0;
}