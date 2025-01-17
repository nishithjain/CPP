#pragma once
#include <iostream>
#include <cstddef>
using namespace std;
class OperatorOverloading
{
private:
	size_t mSize;
	int* mArray;
	int count;
public:
	OperatorOverloading(size_t size = 0);

#pragma region TheRuleOf3
	// Copy constructor
	OperatorOverloading(const OperatorOverloading& obj);
	// Operators overloaded
	friend void swap(OperatorOverloading& first, OperatorOverloading& second);
	OperatorOverloading& operator=(OperatorOverloading rhs);
	// Destructor
	~OperatorOverloading();
#pragma endregion TheRuleOf3

#pragma region UnaryOperator
	void operator!();
	OperatorOverloading& operator++();
	OperatorOverloading operator++(int);
	OperatorOverloading& operator--();
	OperatorOverloading operator--(int);
#pragma endregion

#pragma region BinaryOperator
	OperatorOverloading& operator += (const OperatorOverloading& rhs);
	OperatorOverloading& operator -= (const OperatorOverloading& rhs);
#pragma endregion BinaryOperator
	
#pragma region HelperFunctions
	void displayMyObject(void);
	size_t getSize(void) const;
	int getCount(void) const;
#pragma endregion HelperFunctions
};
#pragma region ComparisonOperators
// Comparison operators implemented as non member functions
bool operator==(const OperatorOverloading& lhs, const OperatorOverloading& rhs);
bool operator< (const OperatorOverloading& lhs, const OperatorOverloading& rhs);
bool operator!=(const OperatorOverloading& lhs, const OperatorOverloading& rhs);
bool operator> (const OperatorOverloading& lhs, const OperatorOverloading& rhs);
bool operator<=(const OperatorOverloading& lhs, const OperatorOverloading& rhs);
bool operator>=(const OperatorOverloading& lhs, const OperatorOverloading& rhs);
#pragma endregion ComparisonOperators

// Binary arithmetic operators
OperatorOverloading operator+(OperatorOverloading lhs, const OperatorOverloading& rhs);
OperatorOverloading operator-(OperatorOverloading lhs, const OperatorOverloading& rhs);