#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Employee
{
public:
	Employee(){}
	Employee(string name, int age) : _name(name), _age(age) {}
	~Employee(){}
	void setNamenAge(string name, int age){ _name = name, _age = age; }
	int getAge(void){ return _age; }
	string getName(void){ return _name; }
private:
	string _name;
	int _age;
};
int sortByAge(const void* a, const void* b )
{
	Employee *ptr1 = (Employee *)a;
	Employee *ptr2 = (Employee *)b;
	return ptr1->getAge() - ptr2->getAge();
}

int sortByName(const void* a, const void* b)
{
	Employee *ptr1 = (Employee *)a;
	Employee *ptr2 = (Employee *)b;
	return ptr1->getName().compare(ptr2->getName());
}

int main(void)
{
#define SIZE 5
	Employee myEmployeeArray[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		cout << "Enter the name of employee: ";
		string name;
		cin >> name;
		cout << "Enter the age of employee: ";
		int age;
		cin >> age;
		myEmployeeArray[i].setNamenAge(name, age);
	}

	qsort((void*)myEmployeeArray, SIZE, sizeof(myEmployeeArray[0]), sortByAge);

	cout << "List of sorted employee based on AGE:" << endl;

	for (int i = 0; i < SIZE;i++)
	{
		cout << myEmployeeArray[i].getName() << endl;
	}

	qsort((void*)myEmployeeArray, SIZE, sizeof(myEmployeeArray[0]), sortByName);

	cout << "List of sorted employee based on AGE:" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << myEmployeeArray[i].getName() << endl;
	}
	return 0;
}
