#include <iostream>

using namespace std;

#pragma region Compiler Generated Functions
/*********************************************
C++03
	Compiler generates 4 functions for us
	1. Default constructor	(Generated only if no constructor is declared by user)
	2. Copy constructor
	3. Copy assignment operator
	4. Destructor
**********************************************/

/*********************************************
C++11
	C++11 compiler generates 6 functions for us
	1. Default constructor	(Generated only if no constructor is declared by user)
	2. Copy constructor
	3. Copy assignment operator
	4. Destructor
	5. Move constructor
	6. Move assignment operator

C++11 has added more rules on how to generate these functions

Copy constructor:
- Copy constructor will not generated if we have declared our own 
	1. Move constructor
	2. Move assignment operator
	3. Copy assignment operator	- (Deprecated rule of C++03)
	4. Destructor	- (Deprecated rule of C++03)

Copy assignment operator:
- Copy assignment operator will not generated if we have declared our own 
	1. Move constructor
	2. Move assignment operator
	3. Copy constructor - (Deprecated rule of C++03)
	4. Destructor - (Deprecated rule of C++03)

Move constructor:
-  Move constructor will not generated if we have declared our own 
	1. Copy constructor
	2. Copy assignment operator
	3. Destructor
	4. Move assignment operator

Move assignment operator:
-  Move assignment operator will not generated if we have declared our own 
	1. Copy constructor
	2. Copy assignment operator
	3. Destructor
	4. Move constructor
**********************************************/

class EmptyDog{};

class EquivalentEmptyDog
{
	/********* C++03 *********/
	// Default constructor
	EquivalentEmptyDog();
	// Copy constructor
	EquivalentEmptyDog(const EquivalentEmptyDog& rhs);
	// Copy assignment operator
	EquivalentEmptyDog& operator=(const EquivalentEmptyDog& rhs);
	// Destructor
	~EquivalentEmptyDog();

	/********* C++11 *********/
	// Move constructor
	EquivalentEmptyDog(EquivalentEmptyDog&& rhs);
	// Move assignment operator
	EquivalentEmptyDog& operator=(EquivalentEmptyDog&& rhs);
};

#pragma endregion Compiler Generated Functions

#pragma region Example 1

class Cat
{
	// Copy constructor
	Cat(const Cat& rhs){ }

/*********************************************
What are the function generate for 'class Cat' if we have Copy 
constructor as in the above example?
1. Default constructor		- This will not be generated since we 
	already have a constructor (Copy constructor).
2. Copy assignment operator - YES (Deprecated rule of C++03)
3. Destructor				- YES
4. Move constructor			- This will not be generated since we 
	have declared Copy constructor.
5. Move assignment operator	- This will not be generated since we
	have declared Copy constructor.
**********************************************/
	Cat& operator=(const Cat& rhs) = default;
};
#pragma endregion Example 1

#pragma region Example 2

class Duck
{
	// Move constructor
	Duck(Duck&& rhs) { }

/*********************************************
What are the function generate for 'class Duck' if we have Move 
constructor defined?
1. Default constructor		- NO, this will not be generated since we
already have a constructor (Move constructor).
2. Copy constructor			- NO
3. Copy assignment operator - NO
4. Destructor				- YES
5. Move assignment operator	- NO
**********************************************/
};

#pragma endregion Example 2

#pragma region Example 3

class Frog
{
// Move constructor - because if the second parameter is not
// specified, Frog can be constructed using another Frog!!!
Frog(Frog&&, int = 0){ }

/*********************************************
What are the function generate for 'class Frog' if we have Move
constructor defined?
1. Default constructor		- NO, this will not be generated since we
already have a constructor (Move constructor).
2. Copy constructor			- NO
3. Copy assignment operator - NO
4. Destructor				- YES
5. Move assignment operator	- NO
**********************************************/
// Side note:
//Frog(int = 0){ } - Default constructor
//Frog(const Frog&, int = 0) {} - Copy constructor
};

#pragma endregion Example 3

#pragma region Example 4

class Fish
{
	~Fish() {}

/*********************************************
What are the function generate for 'class Fish' if we have 
Destructor defined?
1. Default constructor		- YES	
2. Copy constructor			- YES	(Deprecated rule of C++03)
3. Copy assignment operator - YES	(Deprecated rule of C++03)
4. Move constructor			- NO this will not be generated since we
have defined Destructor.
5. Move assignment operator	- NO this will not be generated since we
have defined Destructor.
**********************************************/
	// Bring it back, since it is deprecated
	Fish(const Fish&) = default;
	Fish& operator=(const Fish&) = default;

};

#pragma endregion Example 4

#pragma region Example 5

class Cow
{
	Cow& operator=(const Cow&) = delete;

/*********************************************
What are the function generated for 'class Cow' if we have
copy assignment operator that is being DELETED!!!?
1. Default constructor		- YES
2. Copy constructor			- YES	(Deprecated rule of C++03)
3. Destructor				- YES
4. Move constructor			- NO this will not be generated since we
have declared Copy assignment operator even though it is deleted.
5. Move assignment operator	- NO this will not be generated since we
have declared Copy assignment operator even though it is deleted.
**********************************************/
	// This will bring back the compiler generated copy constructor
	Cow(const Cow&) = default;	
};

#pragma endregion Example 5


