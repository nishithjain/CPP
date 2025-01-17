#include <iostream>
#include <string>
#include <vector>

using namespace std;


#pragma region TheProblem
//// Person owns the string through its pointer
//class Person
//{
//public:
//	Person(string name) { ptrname_ = new string(name); }
//	~Person() { delete ptrname_; }
//
//	// CRASHES!!!
//	void printName(void) { cout << *ptrname_; }
//
//	unsigned getAge(void) const { return age_; }
//	void setAge(unsigned age) { age_ = age; }
//
//private:
//	string* ptrname_;
//	unsigned age_;
//};
//
//int main(void)
//{
//	vector<Person> persons;
//	persons.push_back(Person("Nishith"));
//	// Older C++ version
//	// 1. "Nishith" is constructed.
//	// 2. A copy of "Nishith" is saved in the vector persons (shallow copy)
//	// 3. "Nishith" is destroyed because it is rvalue.
//	persons.back().printName();
//
//	cout << "Goodbye!!!" << endl;
//	return 0;
//}
#pragma endregion TheProblem

// Solution 1: Define copy constructor and copy assignment operator for deep copying

#pragma region Solution1
// Person owns the string through its pointer
class Person
{
public:
	Person(string name) { ptrname_ = new string(name); }
	~Person() { delete ptrname_; }

	void printName(void) { cout << *ptrname_; }

	unsigned getAge(void) const { return age_; }
	void setAge(unsigned age) { age_ = age; }

	Person(const Person&rhs)
	{
		ptrname_ = new string(*(rhs.ptrname_));
	}

	Person& operator=(const Person& rhs)
	{

	}

private:
	string* ptrname_;
	unsigned age_;
};

int main(void)
{
	vector<Person> persons;
	persons.push_back(Person("Nishith"));
	// Older C++ version
	// 1. "Nishith" is constructed.
	// 2. A copy of "Nishith" is saved in the vector persons (shallow copy)
	// 3. "Nishith" is destroyed because it is rvalue.
	persons.back().printName();

	cout << "Goodbye!!!" << endl;
	return 0;
}
#pragma endregion Solution1

// Solution 2: Delete copy constructor and copy assignment operator, define clone function

#pragma region Solution 2
// Person owns the string through its pointer
class Person
{
public:
	Person(string name) { ptrname_ = new string(name); }
	~Person() { delete ptrname_; }

	// CRASHES!!!
	void printName(void) { cout << *ptrname_; }

	unsigned getAge(void) const { return age_; }
	void setAge(unsigned age) { age_ = age; }

	Person(const Person&rhs) = delete;
	Person& operator=(const Person& rhs) = delete;
	Person* clone()
	{
		return (new Person(*(ptrname_)));
	}

private:
	string* ptrname_;
	unsigned age_;
};

int main(void)
{
	vector<Person> persons;
	persons.push_back(Person("Nishith"));
	// Older C++ version
	// 1. "Nishith" is constructed.
	// 2. A copy of "Nishith" is saved in the vector persons (shallow copy)
	// 3. "Nishith" is destroyed because it is rvalue.
	persons.back().printName();

	cout << "Goodbye!!!" << endl;
	return 0;
}
#pragma endregion Solution 2