#include <iostream>
#include <fstream>
#include "Integer.h"

using namespace std;

void f(Integer a)
{
	Integer temp;
	temp = +a;
	temp = -a;
	temp = ~a;
	Integer* ip = &a;
	temp = !a;
	temp = ++a;
	temp = a++;
	temp = --a;
	temp = a--;
}


ofstream out("IntegerTest.out");

void h(Integer& c1, Integer& c2) 
{
	// A complex expression:
	c1 += c1 * c2 + c2 % c1;

#define TRY(OP) \
out << "c1 = "; c1.print(out); \
out << ", c2 = "; c2.print(out); \
out << "; c1 " #OP " c2 produces "; \
(c1 OP c2).print(out); \
out << endl;

	TRY(+) TRY(-) TRY(*) TRY(/ )
	TRY(%) TRY(^) TRY(&) TRY(| )
	TRY(<< ) TRY(>> ) TRY(+= ) TRY(-= )
	TRY(*= ) TRY(/= ) TRY(%= ) TRY(^= )
	TRY(&= ) TRY(|= ) TRY(>>= ) TRY(<<= )

	// Conditionals:
#define TRYC(OP) \
out << "c1 = "; c1.print(out); \
out << ", c2 = "; c2.print(out); \
out << "; c1 " #OP " c2 produces "; \
out << (c1 OP c2); \
out << endl;

	TRYC(<) TRYC(>) TRYC(== ) TRYC(!= ) TRYC(<= )
	TRYC(>= ) TRYC(&&) TRYC(|| )
}



class After 
{
	int i;
	After *This() { return this; }
public:
	After(int ll = 0) : i(ll) { }
	int getI(void) const { return i; }
	const After& operator,(const After&) const 
	{
		cout << "After::operator,()" << endl;
		return *this;
	}
	const After operator+(const After& right)
	{
		return After(i + right.i);
	}
};

const After operator+(int x, const After& rhs)
{
	return After(x + rhs.getI());
}

class Before {};
Before& operator,(int, Before& b) 
{
	cout << "Before::operator,()" << endl;
	return b;
}


int main(void)
{
	Integer aa(55);

	f(aa);

	Integer c1(47), c2(9);
	h(c1, c2);


	After a, b;
	a, b; // Operator comma called
	Before c;
	1, c; // Operator comma called
	5.5f, c;

	7 + a;


	return 0;
}