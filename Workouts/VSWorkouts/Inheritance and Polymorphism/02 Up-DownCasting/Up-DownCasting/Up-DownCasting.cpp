#include <iostream>
using namespace std;

class Shape
{
public:
	Shape() {}
	virtual ~Shape() {}
	virtual void draw(void)		{ cout << "Shape: Draw Method" << endl; }
	virtual void move(void)		{ cout << "Shape: Move Method" << endl; }
	virtual void shrink(void)	{ cout << "Shape: Shrink Method" << endl; }
};

class Circle : public Shape
{
public:
	Circle(){}
	~Circle(){}
	void draw(void)		{ cout << "Circle: Draw Method" << endl; }
	void move(void)		{ cout << "Circle: Move Method" << endl; }
	void shrink(void)	{ cout << "Circle: Shrink Method" << endl; }
	void display(void)	{ cout << "Circle: Only CIRCLE has this" << endl; }
};

class Triangle : public Shape
{
public:
	Triangle(){}
	~Triangle(){}
	void draw(void)		{ cout << "Triangle: Draw Method" << endl; }
	void move(void)		{ cout << "Triangle: Move Method" << endl; }
	void shrink(void)	{ cout << "Triangle: Shrink Method" << endl; }
};

class Square : public Shape
{
public:
	Square(){}
	~Square(){}
	void draw(void)		{ cout << "Square: Draw Method" << endl; }
	void move(void)		{ cout << "Square: Move Method" << endl; }
	void shrink(void)	{ cout << "Square: Shrink Method" << endl; }
};

void play(Shape& s)
{
	s.draw();
	s.move();
	s.shrink();
}

int main(void)
{
	/************************************************************************
	UP-CASTING
	The process of converting a derived-class reference or pointer to a
	base-class. In other words, up-casting allows us to treat a derived
	type as though it were its base type. It is always allowed for public
	inheritance, without an explicit type cast. This is a result of the
	is-a relationship between the base and derived classes.
	************************************************************************/
	{
		Circle c;
		Triangle t;
		Square sq;
		play(c);	// Without an explicit type cast we are converting derived class pointer to base class
		play(t);	// Without an explicit type cast we are converting derived class pointer to base class
		play(sq);	// Without an explicit type cast we are converting derived class pointer to base class
	}
	/************************************************************************
	DOWN-CASTING
	The process of converting a base-class pointer (reference) to a derived-class
	pointer (reference) is called down-casting.
	************************************************************************/
	{
		{
			Shape newShape;
			// Down-casting is not allowed without an explicit type cast.
			// Circle *ptrCircle = &newShape;
			/****************************************************************
			Shape* pa =new Shape();
			Circle* pb =new Circle();
			Shape* paUpcast= new Circle();

			Shape *pa -->			+-+   new Shape()
									|a|
									+-+
			Circle* pb -->			+-+-+ new Circle()
									|a|b|
									+-+-+
			Shape* paUpcast--> 		+-+-+ new Circle()
									|a|b|
									+-+-+
			Circle* pbDowncast --> 	+-+ new Shape()
									|a|
									+-+
			****************************************************************/
			Circle *ptrCircle1 = (Circle *)&newShape;
			ptrCircle1->draw();
			ptrCircle1->move();
			ptrCircle1->shrink();
			/****Undefined Behaviour****/
			ptrCircle1->display();
			ptrCircle1 = nullptr;
			ptrCircle1->display();
			/****Undefined Behaviour****/
		}

		{
			Shape newShape;
			Circle *ptrCircle = dynamic_cast<Circle *>(&newShape);
			if (ptrCircle)
				ptrCircle->draw();
			else
				cout << "Can't be casted!!!" << endl;
		}
	}
	return EXIT_SUCCESS;
}