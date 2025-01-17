#include <iostream>
#include <memory>
#include <forward_list>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

template<typename T>
class Stack
{
private:
	forward_list<T> aList;
public:
	void push(T value)
	{
		aList.push_front(value);
	}

	T pop(void)
	{
		if (aList.empty())
		{
			throw std::out_of_range("Stack is Empty!!!");
		}

		T val = aList.front();
		aList.remove(val);
		return val;
	}

	T peek(void) const
	{
		if (aList.empty())
		{
			throw std::out_of_range("Stack is Empty!!!");
		}
		return aList.front();
	}

	bool isEmpty(void)
	{
		return aList.empty() ? true: false;
	}
};

bool is_number(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

int main(void)
{
	Stack<int> myStack;

	string args = "5 6 7 * + 1 -";
	string buf;				// Have a buffer string
	stringstream ss(args);	// Insert the string into a stream

	vector<string> tokens;	// Create vector to hold our words

	while (ss >> buf)
		tokens.push_back(buf);

	for(string val : tokens)
	{
		int value;
		if (is_number(val))
			myStack.push(stoi(val));

		else
		{
			int rhs = myStack.pop();
			int lhs = myStack.pop();


			const char *mycharp = val.c_str();


			switch (mycharp[0])
			{
			case '+':
				myStack.push(lhs + rhs);
				break;
			case '-':
				myStack.push(lhs - rhs);
				break;
			case '*':
				myStack.push(lhs * rhs);
				break;
			case '/':
				myStack.push(lhs / rhs);
				break;
			}
		}

	}

	cout << myStack.peek() << endl;
	
	return 0;
}

