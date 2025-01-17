#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>

using std::string;
using std::invalid_argument;
using std::cin;
using std::cout;
using std::endl;

class Person
{
public:
	Person(){}
	Person(string name, int age)
	{
		if (name.empty())
			throw invalid_argument("Name can't be empty");
		if (age < 18)
			throw invalid_argument(name + " is minor!!!");
		_name = name;
		_age = age;
	}
	Person(Person&& that) : _name(std::move(that._name))
	{
		cout << "In move constructor" << endl;
		_age = that._age;
		that._name.clear();
	}
	Person& operator=(Person&& that)
	{
		cout << "In move assignment" << endl;
		_name = std::move(that._name);
		_age = that._age;
		that._name.clear();
		return *this;
	}

	Person(const Person& that)
	{
		_age = that._age;
		_name = that._name;
		cout << "In copy constructor" << endl;
	}
	Person& operator=(const Person& that)
	{
		_name = that._name;
		_age = that._age;
		cout << "In copy assignment" << endl;
		return *this;
	}

	~Person() { cout << "In person destructor: " << _name << endl; }
	string getName(void) const { return _name; }
private:
	string _name;
	int _age;
};

Person createPerson()
{
	while (1)
	{
		try
		{
			string name;
			int age;
			cout << "Enter name of the person: ";
			cin >> name;
			cout << "Enter age of the person: ";
			cin >> age;
			Person aNewPerson(name, age);
			return aNewPerson;
		}
		catch (invalid_argument& e)
		{
			cout << e.what() << endl;
			cout << "Please try again!!!" << endl;
		}
	}
}

int main(void)
{
	Person aNewPerson;
	
	aNewPerson = createPerson();
	cout << aNewPerson.getName() << " created" << endl;

	return 0;
}