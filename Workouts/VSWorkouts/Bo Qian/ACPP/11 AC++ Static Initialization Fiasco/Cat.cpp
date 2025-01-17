#include "Cat.h"
#include "Dog.h"
#include "Singleton.h"

//Dog dd("Bruce");
Cat::Cat(char* name)
{
	cout << "Cat born with name " << name << endl;
	_name = name;
	//dd.bark();
	SingleTon::getDog()->bark();
}
void Cat::meow(void)
{
	cout << "I am just a cat. My name is " << _name << endl;
}
