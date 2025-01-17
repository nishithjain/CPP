#include <iostream>
#include <string>

using namespace std;

class Shape {
public:
	virtual ~Shape() { } // A virtual destructor
	virtual void draw() = 0; // A pure virtual function
	virtual void move() = 0;
	// ...
	virtual Shape* clone() const = 0; // Uses the copy constructor
	virtual Shape* create() const = 0; // Uses the default constructor
};
class Circle : public Shape {
public:
	// Covariant Return Types; see below
	Circle* clone() const { return new Circle(*this); }
	// Covariant Return Types; see below
	Circle* create() const { return new Circle(); }
	void draw() { cout << "Drawing Circle!!!\n"; }
	void move() { cout << "Moving Circle!!!\n"; }
};

class Square : public Shape
{
public:
	// Covariant Return Types; see below
	Square* clone() const
	{
		return new Square(*this);
	}
	// Covariant Return Types; see below
	Square* create() const
	{
		return new Square();
	}

	void draw() { cout << "Drawing Square!!!\n"; }
	void move() { cout << "Moving Square!!!\n"; }
};

void userCode(Shape& s)
{
	Shape* aShape = s.create();
	
	aShape->draw();
	aShape->move();

	delete aShape;
}
int main(void) 
{ 
	Square aSquare;
	Circle aCircle;

	userCode(aSquare);
	userCode(aCircle);

	return 0; 
}