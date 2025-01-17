#ifndef SINGLETON_H
#define SINGLETON_H

#include "Cat.h"
#include "Dog.h"

class SingleTon
{
	static Dog* ptrDog;
	static Cat* ptrCat;
public:
	~SingleTon();
	static Dog* getDog();
	static Cat* getCat();
};

#endif // !SINGLETON_H
