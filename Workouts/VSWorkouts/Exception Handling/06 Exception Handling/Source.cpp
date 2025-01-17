#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;


namespace HandingException
{
	///<summary>
	///AAAA
	///</summary>
	///<returns>AASSS</returns>
	class myBase : public exception
	{
	public:
		myBase() {};
		virtual ~myBase(void) {};
		virtual const char* what() const { return "Hello, you have done a mistake"; }
		int y;
		myBase operator=(myBase& that)
		{
			this->x = that.x;
			this->y = that.y;
			this->z = that.z;
			return *this;
		}
	protected:
		int z;
	private:
		int x;
	};

	class myDerived : public myBase
	{
	public:
		myDerived() {};
		virtual ~myDerived(void) {};
		const char* what() const { return "Hello, you have done a mistake in - derived class"; }
	};

	struct myStruct
	{
		int x;
		int y;
		typedef float FLOATS;
		FLOATS ab, cd;
	};

	enum MyEnum
	{
		A, B, C, D
	};

	union MyUnion
	{
		int x;
		float y;
	};

	template<class T>
	class MyClass
	{
	public:
		MyClass() {};
		~MyClass() {};

	private:
		T abc;
	};
}

using namespace HandingException;


int main(void)
{
	try
	{
		throw myDerived();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	getchar();
	return 0;
}