#include <iostream>

using namespace std;

// POD
class A 
{ public: int m; };
// Non-POD, compiler generated default constructor
class B 
{ public: int m; ~B(); }; 
// Non-POD, default-initializing m
class C 
{ public: int m; C() : m() {} ~C(); }; 

int main(void)
{
	A* a1 = new A; 		// indeterminate value
	A* a2 = new A();	// zero-initialize
	B* b1 = new B;		// default construct (B::m is uninitialized)
	B* b2 = new B();	// default construct (B::m is uninitialized)
	C* c1 = new C;		// default construct (C::m is zero-initialized)
	C* c2 = new C();	// default construct (C::m is zero-initialized)

	cout << "new A: " << a1->m << endl;
	cout << "new A(): " << a2->m << endl;
	cout << "new B: " << b1->m << endl;
	cout << "new B(): " << b2->m << endl;
	cout << "new C: " << c1->m << endl;
	cout << "new C(): " << c2->m << endl;
	
	return 0;
}
/************************
new A: -842150451
new A(): 0
new B: -842150451
new B(): -842150451
new C: 0
new C(): 0
*************************/