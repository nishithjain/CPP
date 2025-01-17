#include "OperatorOverloading.h"

OperatorOverloading::OperatorOverloading(size_t size) : mSize(size), count(0), mArray(mSize ? new int[mSize]() : 0)
{
	//cout << "Inside Constructor" << endl;
	for (size_t i = 0; i < mSize; i++)
	{
		mArray[i] = count;
		//cout << mArray[i] << endl;
	}
}

#pragma region TheRuleOf3
// Copy constructor
OperatorOverloading::OperatorOverloading(const OperatorOverloading& obj) : mSize(obj.mSize), count(obj.count), mArray(mSize ? new int[mSize] : 0)
{
	//cout << "Inside Copy Constructor" << endl;
	std::copy(obj.mArray, obj.mArray + mSize, mArray);
}
OperatorOverloading& OperatorOverloading::operator=(OperatorOverloading rhs)
{
	swap(*this, rhs);
	return *this;
}
void swap(OperatorOverloading& first, OperatorOverloading& second) // nothrow
{
	// enable ADL (not necessary in our case, but good practice)
	using std::swap;

	// by swapping the members of two classes,
	// the two classes are effectively swapped
	swap(first.mSize, second.mSize);
	swap(first.count, second.count);
	swap(first.mArray, second.mArray);
}
OperatorOverloading::~OperatorOverloading(){ }
#pragma endregion TheRuleOf3

#pragma region UnaryOperator
void OperatorOverloading::operator!()
{
	cout << "Operator NOT is called!!!" << endl;
}
OperatorOverloading& OperatorOverloading::operator++()
{
	count++;
	for (size_t i = 0; i < mSize; i++)
		mArray[i] = count;
	return *this;
}
OperatorOverloading OperatorOverloading::operator++(int)
{
	OperatorOverloading tmp(*this);
	operator++();
	return tmp;
}
OperatorOverloading& OperatorOverloading::operator--()
{
	count--;
	for (size_t i = 0; i < mSize; i++)
		mArray[i] = count;
	return *this;
}
OperatorOverloading OperatorOverloading::operator--(int)
{
	OperatorOverloading tmp(*this);
	operator--();
	return tmp;
}
#pragma endregion UnaryOperator

#pragma region BinaryArithmeticOperators
OperatorOverloading& OperatorOverloading::operator += (const OperatorOverloading& rhs)
{
	// actual addition of rhs to *this
	count = count + rhs.count;
	for (size_t i = 0; i < mSize; i++)
		mArray[i] = count;
	return *this;
}
OperatorOverloading& OperatorOverloading::operator-=(const OperatorOverloading& rhs)
{
	count = count - rhs.count;
	for (size_t i = 0; i < mSize; i++)
		mArray[i] = count;
	return *this;
}
OperatorOverloading operator+(OperatorOverloading lhs, const OperatorOverloading& rhs) { lhs += rhs; return lhs; }
OperatorOverloading operator-(OperatorOverloading lhs, const OperatorOverloading& rhs) { lhs -= rhs; return lhs; }
#pragma endregion BinaryArithmeticOperators

#pragma region ComparisonOperators
bool operator==(const OperatorOverloading& lhs, const OperatorOverloading& rhs)
{
	return (lhs.getCount() == rhs.getCount()) ? true : false;
}
bool operator< (const OperatorOverloading& lhs, const OperatorOverloading& rhs)
{
	return (lhs.getCount() < rhs.getCount()) ? true : false;
}
bool operator!=(const OperatorOverloading& lhs, const OperatorOverloading& rhs){ return !operator==(lhs, rhs); }
bool operator> (const OperatorOverloading& lhs, const OperatorOverloading& rhs){ return  operator< (rhs, lhs); }
bool operator<=(const OperatorOverloading& lhs, const OperatorOverloading& rhs){ return !operator> (lhs, rhs); }
bool operator>=(const OperatorOverloading& lhs, const OperatorOverloading& rhs){ return !operator< (lhs, rhs); }
#pragma endregion ComparisonOperators

#pragma region HelperFunctions
void OperatorOverloading::displayMyObject(void)
{
	cout << "---------" << endl;
	for (size_t i = 0; i < mSize; i++)
		cout << mArray[i] << endl;
	cout << "---------" << endl;
}
size_t OperatorOverloading::getSize(void) const { return mSize; }
int OperatorOverloading::getCount(void) const { return count; }
#pragma endregion HelperFunctions