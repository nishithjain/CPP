#ifndef CAT_H
#define CAT_H

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Cat
{
private:
	string _name;
public:
	Cat(char* name);
	void meow(void);
	~Cat() { }
};
#endif // !CAT_H
