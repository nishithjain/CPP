#include "Singleton.h"

Dog* SingleTon::ptrDog = nullptr;
Cat* SingleTon::ptrCat = nullptr;

Dog* SingleTon::getDog()
{
	if (!ptrDog)
		ptrDog = new Dog("Gunner!!!");
	return ptrDog;
}

Cat* SingleTon::getCat()
{
	if (!ptrCat)
		ptrCat = new Cat("Smokey");
	return ptrCat;
}

SingleTon::~SingleTon()
{
	if (ptrCat) delete ptrCat;
	if (ptrDog) delete ptrDog;
	ptrDog = nullptr;
	ptrCat = nullptr;
}