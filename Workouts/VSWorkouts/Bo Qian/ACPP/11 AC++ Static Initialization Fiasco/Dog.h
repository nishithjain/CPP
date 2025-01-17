#ifndef DOG_H
#define DOG_H

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Dog
{
private:
	string _name;
public:
	Dog(char* name);
	void bark(void);
	~Dog() { }
};
#endif // !DOG_H
