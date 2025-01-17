#include <iostream>
#include <thread>

using namespace std;

/************************
C Style casting
static_cast<>()
dynamic_cast<>()
reinterpret_cast<>()
const_cast<>()
************************/

#pragma region Polymorphic Class
// Polymorphic classes
class Base
{
private:
	int _x;
public:
	Base() { };
	virtual ~Base() { };
};
class Derived : public Base
{
private:
	int _y;
public:
	Derived() { };
	~Derived() { };
};
#pragma endregion Polymorphic Class

#pragma region Non-polymorphic Class
// Non-polymorphic classes    
class AnotherBase
{
public:
	~AnotherBase() { }; // Not virtual
};
class AnotherDerived : public AnotherBase
{
public:
	void f() { }; // Not virtual either
};
#pragma endregion Non-polymorphic Class

#pragma region Dynamic Cast Helper
typedef enum MyEnum
{
	MSG_DEBUG_OUT, MSG_XYZ
}MyEnum;

class Message
{
public:
	MyEnum message_id;
	Message() : message_id(MSG_DEBUG_OUT){}
	virtual ~Message(){}
};

class DebugMsgData : public Message
{
public:
	DebugMsgData(){}
	~DebugMsgData(){}
};

class XYZMsgData : public Message
{
public:
	XYZMsgData(){}
	~XYZMsgData(){}
};
#pragma endregion Dynamic Cast Helper

#pragma region Helper Functions
void threadFunction(void *data)
{
	cout << "Inside threadFunction" << endl;
	AnotherBase *c = static_cast<AnotherBase*>(data);
}
int add10ToInteger(int* ptr)
{
	*ptr = *ptr + 10;
	return (*ptr);
}
void OnMessage(Message *msg)
{
	switch (msg->message_id)
	{
		case MSG_DEBUG_OUT:
		{
			DebugMsgData *data = dynamic_cast<DebugMsgData*>(msg);
			if (data)
				cout << "DebugMsgData:: data is not null" << endl;
			else
				cout << "DebugMsgData:: data is null" << endl;
			break;
		}

		case MSG_XYZ:
		{
			XYZMsgData *data = dynamic_cast<XYZMsgData*>(msg);
			if (data)
				cout << "XYZMsgData:: data is not null" << endl;
			else
				cout << "XYZMsgData:: data is null" << endl;
			break;
		}
	}
}

#pragma endregion Helper Functions

int main(int argc, char* argv[])
{

#pragma region C-Style
	/************************************************************************
	- static_cast<>() gives you a compile time checking ability, C-Style cast doesn't.
	- static_cast<>() is more readable and can be spotted easily anywhere 
	inside a C++ source code, C-Style cast isn't.
	- Intentions are conveyed much better using C++ casts.
	************************************************************************/
	{
		// The static cast performs conversions between compatible types. 
		// It is similar to the C-style cast, but is more restrictive. 
		// For example, the C-style cast would allow an integer pointer to point to a char.
		char c = 10;		// 1 byte
		int *p = (int*)&c;	// 4 bytes
		// BOOM!!!
		//*p = 5;			// Run-time error: stack corruption
		//int *q = static_cast<int*>(&c); // Compile-time error
	}
#pragma endregion C-Style

#pragma region static_cast
	{
		AnotherBase c;
		// Conversion from AnotherBase* -> void* is implicit
		thread t1(&threadFunction, &c);  // threadFunction(&c) will be called
		t1.join();
	}
#pragma endregion static_cast

#pragma region dynamic_cast

	/************************************************************************
	dynamic_cast works ONLY with polymorphic class. And polymorphic class
	is that which has at least one virtual function, even be it the destructor.
	************************************************************************/
	{
		Base* b = new Derived();				// Creating derived class object and assign it to base class pointer
		Derived* d1 = static_cast<Derived*>(b);	// Valid! d1 is a valid and correct pointer to a BClass
		Derived* d2 = dynamic_cast<Derived*>(b);// Valid! d2 is a valid and correct pointer to a BClass
	}

	{
		Base* b = new Base();
		Derived* d1 = static_cast<Derived*>(b); // Invalid!
		Derived* d2 = dynamic_cast<Derived*>(b);// Valid, but d2 is now a null pointer
		if (d2)
			cout << "d2 is not null" << endl;
		else
			cout << "d2 is null" << endl;
	}

	/************************************************************************
	Note that in dynamic_cast, only the source type need to be polymorphic
	in order to compile. If the destination isn't polymorphic, then
	dynamic_cast will return null pointer.
	************************************************************************/
	{
		Base* b = new Derived();				// Creating derived class object and assign it to base class pointer
		AnotherDerived *pD = dynamic_cast<AnotherDerived*>(b);	// OK - source (AClass) is polymorphic

		if (pD)
			cout << "pD is not null" << endl;
		else
			cout << "pD is null" << endl;
	}

	{
		Message *ptr = new DebugMsgData;
		ptr->message_id = MSG_DEBUG_OUT;
		OnMessage(ptr);
		delete ptr;

		Message *ptr1 = new XYZMsgData;
		ptr1->message_id = MSG_XYZ;
		OnMessage(ptr1);
		delete ptr1;
	}

#pragma endregion dynamic_cast

#pragma region reinterpret_cast
	/************************************************************************
	This is the ultimate cast, which disregards all kind of type safety,
	allowing you to cast anything to anything else, basically reassigning
	the type information of the bit pattern.
	************************************************************************/
	{
		int i = 12345;
		AnotherBase* p = reinterpret_cast<AnotherBase*> (i); // DANGEROUS!!!
	}

	{
		int i = 0;
		void *v = 0;

		int c = (int)v;						// is valid
		//int d = static_cast<int>(v);		// is not valid, different types
		int e = reinterpret_cast<int>(v);	// is valid, but very dangerous
	}
#pragma endregion reinterpret_cast

#pragma region const_cast
	/************************************************************************
	const_cast is used to cast away the constness of variables.
	************************************************************************/
	{
		int val = 10;
		const int *ptr = &val;
		int *ptr1 = const_cast <int *>(ptr);
		add10ToInteger(ptr1);
		cout << val;
	}

/************************************************************************
const_cast can be used to change non-const class members inside a const
member function.
************************************************************************/
	{
		class student
		{
		private:
			int roll;
		public:
			// constructor
			student(int r) :roll(r) {}

			// A const function that changes roll with the help of const_cast
			void fun() const
			{
				(const_cast <student*> (this))->roll = 5;
			}

			int getRoll()  { return roll; }
		};

		student s(3);
		cout << "Old roll number: " << s.getRoll() << endl;
		s.fun();
		cout << "New roll number: " << s.getRoll() << endl;
	}
#pragma endregion const_cast

	return 0;
}

