/******************Integer.h******************/
class Integer
{
	long i;
	Integer* This() { return this; }
public:
	Integer(long ll = 0) : i(ll) { }

	// Either we can use friend or can be implemented as member functions
	// since the unary operator needs to access the private members.
	friend const Integer& operator+(const Integer& a);
	friend const Integer operator-(const Integer& a);
	friend const Integer operator~(const Integer& a);
	friend Integer* operator&(Integer& a);
	friend int operator!(const Integer& a);
	friend const Integer& operator++(Integer& a);
	friend const Integer operator++(Integer& a, int);
	friend const Integer& operator--(Integer& a);
	friend const Integer operator--(Integer& a, int);

	friend const Integer operator+(const Integer& left, const Integer& right);
	friend const Integer operator-(const Integer& left, const Integer& right);
	friend const Integer operator*(const Integer& left, const Integer& right);
	friend const Integer operator/(const Integer& left, const Integer& right);
	friend const Integer operator%(const Integer& left, const Integer& right);
	friend const Integer operator^(const Integer& left, const Integer& right);
	friend const Integer operator&(const Integer& left, const Integer& right);
	friend const Integer operator|(const Integer& left, const Integer& right);
	friend const Integer operator<<(const Integer& left, const Integer& right);
	friend const Integer operator>>(const Integer& left, const Integer& right);
	// Assignments modify & return lvalue:
	friend Integer& operator+=(Integer& left, const Integer& right);
	friend Integer& operator-=(Integer& left, const Integer& right);
	friend Integer& operator*=(Integer& left, const Integer& right);
	friend Integer& operator/=(Integer& left, const Integer& right);
	friend Integer& operator%=(Integer& left, const Integer& right);
	friend Integer& operator^=(Integer& left, const Integer& right);
	friend Integer& operator&=(Integer& left, const Integer& right);
	friend Integer& operator|=(Integer& left, const Integer& right);
	friend Integer& operator>>=(Integer& left, const Integer& right);
	friend Integer& operator<<=(Integer& left, const Integer& right);
	friend int operator==(const Integer& left, const Integer& right);
	friend int operator!=(const Integer& left, const Integer& right);
	friend int operator<(const Integer& left, const Integer& right);
	friend int operator>(const Integer& left, const Integer& right);
	friend int operator<=(const Integer& left, const Integer& right);
	friend int operator>=(const Integer& left, const Integer& right);
	friend int operator&&(const Integer& left, const Integer& right);
	friend int operator||(const Integer& left, const Integer& right);
	// Write the contents to an ostream:
	void print(std::ostream& os) const { os << i; }
};