#include <iostream>
#include <memory>
using namespace std;

#pragma region VirtualDestructor
//class Dog
//{
//public:
////	virtual ~Dog() { cout << "Dog destroyed!!!" << endl; }
//	~Dog() { cout << "Dog destroyed!!!" << endl; }
//};
//
//class YellowDog : public Dog
//{
//public:
//	~YellowDog() { cout << "Yellow dog destroyed!!!" << endl; }
//};
//
//class DogFactory
//{
//public:
//	static Dog* createYellowDog() { return (new YellowDog()); }
//	// Create other dogs
//};
//
//int main(void)
//{
//	Dog* ptrDog = DogFactory::createYellowDog();
//
//	// 1. When ptrDog gets deleted, only Dog's destructor gets called this
//	// is bad, because we have created YellowDog and only a part of YellowDog
//	// gets destroyed. This is why we need virtual destructor for base class
//	delete ptrDog;
//	return 0;
//}
#pragma endregion VirtualDestructor

/************************************************************************
	All the classes in STL have no virtual destructor, so we should be
	careful when inheriting from them. We better use shared_ptr for that.
************************************************************************/
#pragma region Using shared_ptr
class Dog
{
public:
	~Dog() { cout << "Dog destroyed!!!" << endl; }
};

class YellowDog : public Dog
{
public:
	~YellowDog() { cout << "Yellow dog destroyed!!!" << endl; }
};

class DogFactory
{
public:
	//static Dog* createYellowDog() { return (new YellowDog()); }
	static shared_ptr<Dog> createYellowDog()
	{
		return shared_ptr<YellowDog>(new YellowDog());
	}
	// Create other dogs
};

int main(void)
{
	// If we don't want to have virtual destructor, then we can use 
	// shared_ptr
	shared_ptr<Dog> ptrDog = DogFactory::createYellowDog();

	// shared_ptr is responsible to delete the pointer.
	//delete ptrDog;
	return 0;
}
#pragma endregion Using shared_ptr