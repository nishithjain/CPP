#include "Dog.h"
#include "Cat.h"
#include "Singleton.h"

//Cat c("Smokey");

Dog::Dog(char* name)
{
	cout << "Dog born with name " << name << endl;
	_name = name;
	//c.meow();
	//SingleTon::getCat()->meow();
}
void Dog::bark(void)
{
	cout << "I am just a dog. My name is " << _name << endl;
}
