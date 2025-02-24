#pragma once
#include <algorithm>

template<typename T>
class Nullable
{
public:
	Nullable() : m_value(), m_isSet(false) {}
	Nullable(T value) : m_value(value), m_isSet(true) {}
	Nullable(const Nullable& other) : m_value(other.m_value), m_isSet(other.m_isSet) {}

	friend void swap(Nullable& a, Nullable& b)
	{
		using std::swap;
		swap(a.m_isSet, b.m_isSet);
		swap(a.m_value, b.m_value);
	}

	Nullable& operator=(Nullable other)
	{
		swap(*this, other);
		return *this;
	}

	T operator=(T value) { set(value); return m_value; }
	bool operator==(T value) { return m_isSet && value == m_value; }
	operator T() const { return get(); }

	T get() const
	{
		if (m_isSet) return m_value;
		else throw std::logic_error("Value of Nullable is not set.");
	}

	bool is_set() const { return m_isSet; }

	void reset() { m_isSet = false; m_value = T(); }

private:
	void set(T value) { m_value = value; m_isSet = true; }

private:
	T m_value;
	bool m_isSet;
};
