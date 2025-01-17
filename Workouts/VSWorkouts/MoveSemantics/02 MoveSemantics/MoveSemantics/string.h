#pragma once
#include <cstring>
#include <algorithm>

namespace myString
{
	class string
	{
		char* data;

	public:
		string();
		string(const char* p);
		string(const string& that);
		string(string&& that);
		string& operator=(string that);
		~string();
	};
}

namespace yourString
{
	class string
	{
	public:
		string();
		~string();

	private:

	};

	string::string()
	{
	}

	string::~string()
	{
	}
}