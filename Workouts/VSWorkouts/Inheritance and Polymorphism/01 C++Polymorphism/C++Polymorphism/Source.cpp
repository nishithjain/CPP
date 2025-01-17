#include <iostream>
using namespace std;

class Animal
{
public:
	Animal() { cout << "Animal: Allocation memory to int" << endl; };
	virtual ~Animal() { cout << "Animal: De-Allocation memory to int" << endl; };
	virtual void WhoAmI(void) { cout << "I am an Animal!!!" << endl; }
	void eat(void){ cout << "Animal is eating!!!" << endl; }
private:
};

class Cat : public Animal
{
public:
	Cat(){ cout << "CAT: Allocation memory to int" << endl; }
	~Cat(){ cout << "CAT: De-Allocation memory to int" << endl; }
	void WhoAmI(void) { cout << "I am a CAT!!!" << endl; }
	void eat(void){ cout << "CAT is eating!!!" << endl; }
private:
};

class Dog : public Animal
{
public:
	Dog(){ cout << "DOG: Allocation memory to int" << endl; }
	~Dog(){ cout << "DOG: De-Allocation memory to int" << endl; }
	void WhoAmI(void) 
	{
		cout << "I am a DOG!!!" << endl; 
	}
private:
};

class Horse : public Animal
{
public:
	Horse(){ cout << "HORSE: Allocation memory to int" << endl; }
	~Horse(){ cout << "HORSE: De-Allocation memory to int" << endl; }
	void WhoAmI(void) { cout << "I am a Horse!!!" << endl; }
private:
};

void DrawAniaml(Animal* ptr)
{
	ptr->WhoAmI();
}

int main(void)
{
	int choice = 0;
	cout << "Which animal you want to draw?" << endl;
	cout << "1 For CAT" << endl << "2 For DOG" << endl << "3 For Horse" << endl;
	cout << "Your Choice: ";
	cin >> choice;

	//while (1)
	{
		switch (choice)
		{
		case 1:
		{
				  Animal* temp = new Cat();
				  DrawAniaml(temp);
				  delete(temp);
				  break;
		}
		case 2:
		{
				  Animal* temp = new Dog;
				  DrawAniaml(temp);
				  delete(temp);
				  break;
		}
		case 3:
		{
				  Animal* temp = new Horse;
				  DrawAniaml(temp);
				  delete(temp);
				  break;
		}
		default:
			cout << "Invalid Choice!!!" << endl;
			break;
		}
	}
	return 0;
}