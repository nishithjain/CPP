#include <iostream>
#include "Integer.h"

using namespace std;


/*********************************************
				Unary Operator
*********************************************/
const Integer& operator+(const Integer& a) { return a; }
const Integer operator-(const Integer& a)  { return Integer(-a.i); }
const Integer operator~(const Integer& a)  { return Integer(~a.i); }
Integer* operator&(Integer& a) { return a.This(); /* &a is recursive!*/ }
int operator!(const Integer& a) { return !a.i; }
const Integer& operator++(Integer& a) { a.i++; return a; }
const Integer operator++(Integer& a, int) 
{ 
	Integer before(a.i); 
	a.i++; 
	return before; 
}
const Integer& operator--(Integer& a) { a.i--; return a; }
const Integer operator--(Integer& a, int)
{ 
	Integer before(a.i); 
	a.i--; 
	return before; 
}


/*********************************************
				Binary Operator
*********************************************/
const Integer  operator+(const Integer& left, const Integer& right) 
{
	return Integer(left.i + right.i);
}

const Integer operator-(const Integer& left, const Integer& right) 
{
	return Integer(left.i - right.i);
}

const Integer operator*(const Integer& left, const Integer& right) 
{
	return Integer(left.i * right.i);
}

const Integer operator/(const Integer& left, const Integer& right) 
{
	return Integer(left.i / right.i);
}

const Integer operator%(const Integer& left, const Integer& right) 
{
	return Integer(left.i % right.i);
}

const Integer operator^(const Integer& left, const Integer& right) 
{
	return Integer(left.i ^ right.i);
}

const Integer operator&(const Integer& left, const Integer& right) 
{
	return Integer(left.i & right.i);
}

const Integer operator|(const Integer& left, const Integer& right) 
{
	return Integer(left.i | right.i);
}

const Integer operator<<(const Integer& left, const Integer& right) 
{
	return Integer(left.i << right.i);
}

const Integer operator>>(const Integer& left, const Integer& right) 
{
	return Integer(left.i >> right.i);
}

// Assignments modify & return lvalue:
Integer& operator+=(Integer& left, const Integer& right) 
{
	if (&left == &right) {/* self-assignment */ }
	left.i += right.i;
	return left;
}

Integer& operator-=(Integer& left, const Integer& right) 
{
	if (&left == &right) {/* self-assignment */ }
	left.i -= right.i;
	return left;
}

Integer& operator*=(Integer& left, const Integer& right) 
{
	if (&left == &right) {/* self-assignment */ }
	left.i *= right.i;
	return left;
}

Integer& operator/=(Integer& left, const Integer& right) 
{
	if (&left == &right) {/* self-assignment */ }
	left.i /= right.i;
	return left;
}

Integer& operator%=(Integer& left, const Integer& right) 
{
	if (&left == &right) {/* self-assignment */ }
	left.i %= right.i;
	return left;
}

Integer& operator^=(Integer& left, 	const Integer& right) 
{
	if (&left == &right) {/* self-assignment */ }
	left.i ^= right.i;
	return left;
}

Integer& operator&=(Integer& left, const Integer& right) 
{
	if (&left == &right) {/* self-assignment */ }
	left.i &= right.i;
	return left;
}

Integer& operator|=(Integer& left, const Integer& right) 
{
	if (&left == &right) {/* self-assignment */ }
	left.i |= right.i;
	return left;
}

Integer& operator>>=(Integer& left, const Integer& right) 
{
	if (&left == &right) {/* self-assignment */ }
	left.i >>= right.i;
	return left;
}

Integer& operator<<=(Integer& left, const Integer& right) 
{
	if (&left == &right) {/* self-assignment */ }
	left.i <<= right.i;
	return left;
}

// Conditional operators return true/false:
int operator==(const Integer& left, const Integer& right) 
{
	return left.i == right.i;
}

int operator!=(const Integer& left, const Integer& right) 
{
	return left.i != right.i;
}

int operator<(const Integer& left, const Integer& right) 
{
	return left.i < right.i;
}

int operator>(const Integer& left, const Integer& right) 
{
	return left.i > right.i;
}

int operator<=(const Integer& left, const Integer& right) 
{
	return left.i <= right.i;
}

int operator>=(const Integer& left, const Integer& right) 
{
	return left.i >= right.i;
}

int operator&&(const Integer& left, const Integer& right) 
{
	return left.i && right.i;
}

int operator||(const Integer& left, const Integer& right) 
{
	return left.i || right.i;
} ///:~