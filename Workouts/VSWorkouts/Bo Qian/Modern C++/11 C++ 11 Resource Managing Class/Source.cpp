#include<iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;
#pragma region Resource Managing C++03

//class Person
//{
//	string* pName_;
//public:
//	Person(string name) : pName_(new string(name)) { }
//	~Person() { delete pName_; }
//	void printName(void) { cout << *pName_ << endl; }
//};
//
//
//int main(void) 
//{ 
//	vector<Person> persons;
//	persons.push_back(Person("George"));
//	persons.front().printName();	// CRASH
//
//	/*********************************************
//	To solve the crash:
//	1. Define copy constructor and copy assignment operator
//	2. Delete copy constructor and copy assignment operator
//	**********************************************/
//	cout << "Good bye!!!" << endl;
//
//	return 0; 
//}

#pragma endregion Resource Managing C++03

#pragma region Resource Managing C++11

#pragma region Solution 1
///*********************************************
//To solve the crash:
//1. C++11 provides delete keyword to delete copy 
//constructor and copy assignment operator.
//**********************************************/
//class Person
//{
//	string* pName_;
//public:
//	Person(string name) : pName_(new string(name)) { }
//	
//	Person(const Person&) = delete;
//	Person& operator=(const Person&) = delete;
//	
//	~Person() { delete pName_; }
//	void printName(void) { cout << *pName_ << endl; }
//};
//
//
//int main(void)
//{
//	vector<Person> persons;
//	persons.push_back(Person("George"));
//	
//	//persons.front().printName();	// CRASH
//	// C++11 provides a way to construct an object in place
//	// in a container. Instead of using push_back(), we can use
//	// emplace_back()
//	// This will construct the object in place
//	persons.emplace_back("George");
//
//	cout << "Good bye!!!" << endl;
//
//	return 0;
//}
#pragma endregion Solution 1

#pragma region Solution 2
//// What if we want to use copy constructor and 
//// copy assignment operator?
//
//// We can use shared_ptr
//class Person
//{
//	// With shared_ptr we don't need to define copy constructor
//	// or copy assignment operator
//	shared_ptr<string> pName_;
//
//public:
//	Person(string name) : pName_(new string(name)) { }
//	//Person(const Person&) = delete;
//	//Person& operator=(const Person&) = delete;
//
//	//~Person() { delete pName_; }
//	void printName(void) { cout << *pName_ << endl; }
//};
//
//
//int main(void)
//{
//	vector<Person> persons;
//	persons.push_back(Person("George"));
//
//	persons.front().printName();	// CRASH
//
//	cout << "Good bye!!!" << endl;
//
//	return 0;
//}
#pragma endregion Solution 2

#pragma region Solution 3

class Person
{
	// We can use unique_ptr since shared_ptr pName_
	// is really not shared and also unique_ptr is light weight.
	//shared_ptr<string> pName_;

	// But the code will not compile. Since persons.push_back() will 
	// copy the person "George" into vector. Here we are using compiler
	// generated copy constructor and compiler generated copy 
	// constructor does the member by member copy and we have a member
	// pName_ which is a unique_ptr and which can't be copied. 
	// unique_ptr can only be moved.
	unique_ptr<string> pName_;

public:
	Person(string name) : pName_(new string(name)) { }
	//Person(const Person&) = delete;
	//Person& operator=(const Person&) = delete;

	~Person() { }
	// Since the destructor has been declared, compiler will not
	// provide move constructor. So we have to bring it back.

	// Visual Studio 2013 doesn't support defaulting move constructor
	// and move assignment operator.
	Person(Person&&) = default;
	void printName(void) { cout << *pName_ << endl; }
};


int main(void)
{
	vector<Person> persons;

	Person p = Person("George");
	persons.push_back(std::move(p));
	persons.front().printName();

	return 0;
}
#pragma endregion Solution 3

#pragma endregion Resource Managing C++11