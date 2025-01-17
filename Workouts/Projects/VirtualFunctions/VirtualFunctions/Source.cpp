#include <iostream>
#include <vector>

using namespace std;

//class Base
//{
//public:
//	virtual void afunction(void)
//	{
//		cout << "From Base : afunction" << endl;
//	}
//	virtual void bfunction(void)
//	{
//		cout << "From Base : bfunction" << endl;
//	}
//	virtual void pure(void) = 0;
//};
//
//class Derived : public Base
//{
//public:
//	void afunction(void) override
//	{
//		cout << "From Derived : afunction" << endl;
//	}
//	void bfunction(void)
//	{
//		cout << "From Derived : bfunction" << endl;
//	}
//	void pure(void)
//	{
//
//	}
//};
//
//class Derived1 : public Base
//{
//public:
//	void afunction(void)
//	{
//		cout << "From Derived1 : afunction" << endl;
//	}
//	void bfunction(void) final
//	{
//		cout << "From Derived1 : bfunction" << endl;
//	}
//	void pure(void)
//	{
//
//	}
//};

class aClass;
class MakeaClassFinal
{
private:
	MakeaClassFinal(){ cout << "MakeaClassFinal\n"; }
	friend aClass;
};

class aClass : virtual public MakeaClassFinal
{
public:
	aClass(){ cout << "aClass\n"; }

};

class anotherClass : public aClass
{
public:
	anotherClass(){ cout << "anotherClass\n"; }
};

//template< typename T > class Final
//{
//protected:
//	Final() {}
//	Final(Final const&) {}
//};
//
//class X : private virtual Final < X >
//{
//	// whatever I want to do
//};
//
//class myClass
//{
//public:
//	void aFunction(void)
//	{
//		cout << "Hello" << endl;
//	}
//private:
//	void* operator new(size_t x);
//};
//class A
//{
//public:
//	A() { cout << "A\n"; }
//};
//
//class B : virtual public A
//{
//public:
//	B() { cout << "B\n"; }
//};
//
//class C : public B
//{
//public:
//	C() { cout << "C\n"; }
//};
//
//class D : public C
//{
//public:
//	D() { cout << "D\n"; }
//};


int main(void) 
{ 
	anotherClass a;
	return 0; 
}