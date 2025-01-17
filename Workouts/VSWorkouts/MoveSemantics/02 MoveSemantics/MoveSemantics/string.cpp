#include "string.h"

using namespace myString;

string::string() { }

string::string(const char* p)
{
	size_t size = strlen(p) + 1;
	data = new char[size];
	memcpy(data, p, size);
}

string::string(const string& that)
{
	size_t size = strlen(that.data) + 1;
	data = new char[size];
	memcpy(data, that.data, size);
}

string::string(string&& that)   // string&& is an rvalue reference to a string
{
	data = that.data;
	that.data = 0;
}

string& string::operator=(string that)
{
	std::swap(data, that.data);
	return *this;
}

string::~string() { delete[] data; }