#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <assert.h>
#include <stdexcept>

using namespace std;
/************************************************************************
							C++11 Features
************************************************************************/

#pragma region Initializer List

int main(void)
{
	// In C++03, { 3, 2, 4, 5 } is called initializer list
	int arr[4] = { 3, 2, 4, 5 };

	// If we wanted to initialize a vector we have to use 
	// push_bach() API of vector.
	// Example:
	vector<int> vCPP03;

	vCPP03.push_back(3);
	vCPP03.push_back(2);
	vCPP03.push_back(4);
	vCPP03.push_back(5);

	// C++11 Extends the initializer list support to vector and
	// other classes
	// Calling initializer_list constructor and initializing vector
	vector<int> vCPP11 = { 3, 2, 4, 5 };

	/* All the relevant STL containers have been updated to accept
	initializer_list!!! */

	return 0;
}

#pragma endregion Initializer List

#pragma region initializer_list Constructor
/* Defining our own initializer_list constructor for our class*/
class boVector
{
	vector<int> vec_;
public:
	boVector(const initializer_list<int>& v)
	{
		for (auto itr = v.begin();
			itr != v.end();
			itr++
			)
		{
			vec_.push_back(*itr);
		}
	}
};

int main(void)
{
	// boVector constructor taking initializer_list as argument!!!
	boVector v = { 0, 2, 4, 6 };
	boVector av{ 0, 2, 4, 6 };
	return 0;
}
#pragma endregion initializer_list Constructor

#pragma region Uniform Initialization

// C++03
class dog
{
public:
	int age;
	string name;
};
dog d1 = { 5, "Bruce" };	// Aggregate Initialization

// C++11
class dogCPP11
{
public:
	dogCPP11(int age, string name){ }
};

int main(void)
{
	dogCPP11 d2 = { 5, "A Dog" };
	return 0;
}
#pragma endregion Uniform Initialization

#pragma region Uniform Initialization Search Order

/***************************************
Uniform Initialization Search Order:
1. initializer_list constructor.
2. Regular constructor that takes the appropriate parameters.
3. Aggregate initialization.
****************************************/

class dog
{
public:
	int age_;

	dog(int a)
	{
		cout << "Inside dog(int a)" << endl;
		age_ = a; 
	}
	dog(const initializer_list<int>& vec) // 3 is taken as single item array
	{
		cout << "Inside dog(const initializer_list<int>& vec)" << endl;
		age_ = *(vec.begin());
	}
};

int main(void)
{
	// Uniform Initialization will search for 
	// initializer_list constructor first and it will construct.
	// If initializer_list is not found, it will search for 
	// constructor that will take single integer as parameter.
	// If that is also not found, it will try to treat dog as
	// aggregate class and will call aggregate initializer.
	dog{ 3 };	

	return 0;
}

#pragma endregion Uniform Initialization Search Order

#pragma region auto Type
int main(void)
{
	vector<int> vec = { 2, 3, 4, 5 };

	// In C++03, to traverse a vector, we would have done...
	for (vector<int>::iterator itr = vec.begin();
		itr != vec.end();
		itr++)
	{
		cout << *itr << " ";
	}
	cout << endl;

	// C++11, we can use auto
	for (auto itr = vec.begin(); itr != vec.end(); itr++)
		cout << *itr << " ";
	cout << endl;

	return 0;
}
#pragma endregion auto Type

#pragma region Ranged based for
int main(void)
{
	vector<int> vec = { 2, 3, 4, 5 };

	// In C++03, to traverse a vector, we would have done...
	for (vector<int>::iterator itr = vec.begin();
		itr != vec.end();
		itr++)
	{
		cout << *itr << " ";
	}
	cout << endl;

	// C++11, we can use range based for
	for (auto i : vec)	// Works on any class of which has begin() and end()
		cout << i << " ";// read only access
	cout << endl;

	for (auto& i : vec)		
		cout << ++i << " ";
	cout << endl;

	return 0;
}
#pragma endregion Ranged based for

#pragma region nullptr
// To replace NULL in C++03
void foo(int i) { cout << "Inside foo_int " << endl; }
void foo(char* ptrC) { cout << "Inside foo_char* " << endl; }

int main(void)
{
	// This will call foo_int
	foo(NULL);

	// In C++11 it will call foo_char*
	foo(nullptr);

	return 0;
}
#pragma endregion nullptr

#pragma region enum class

int main(void)
{
	{
		// C++03 enumerators are basically integers
		enum apple { green_a, red_a };
		enum orange { big_o, small_o };

		apple a = green_a;
		orange o = big_o;

		if (a == o) // We can compare APPLE with ORANGE
			cout << "Green APPLE and big ORANGE are the same" << endl;
		else
			cout << "Green APPLE and big ORANGE are not same" << endl;
	}
	{
		// C++11 introduces enumerator class
		enum class apple { green_a, red_a };
		enum class orange { big_o, small_o };
		apple a = apple::green_a;
		orange o = orange::big_o;

		// Compilation fails here cos, APPLE is different from ORANGE
		// or else we have to define operator==
		//if (a == o) // We can compare APPLE with ORANGE
			//cout << "Green APPLE and big ORANGE are the same" << endl;
		//else
			//cout << "Green APPLE and big ORANGE are not same" << endl;
	}
	return 0;
}
#pragma endregion enum class

#pragma region static_assert
int main(void)
{
	int* myPointer = NULL;

	// Run-time assert. C++03
	assert(myPointer != NULL);
	// C++11 provides compile time assert
	// This code will not compile if the sizeof(int) is not 4
	static_assert(sizeof(int) == 4, "Message");

	return 0;
}
#pragma endregion static_assert

#pragma region Delegating Constructor

// This will only work in JAVA
//class dog	
//{
//public:
//	dog(){}
//	dog(int a)
//	{ 
//		dog(); // Reuse the code of 1st constructor and do something else
//		cout << "Inside dog(int a) " << endl; 
//	}
//};

// To achieve the same in C++03 is like below
class dogCPP03
{
	void init() { cout << "Inside init()" << endl; }
public:
	dogCPP03() { init(); }
	dogCPP03(int a) 
	{ 
		init();  
		cout << "Inside dogCPP03(int a)" << endl;
	}
	/* PROBLEM 
	1. Cumbersome code.
	2. init() could be invoked by other functions.
	*/
};

// C++11 provides a new way to share the code of constructor!!!
class dogCPP11
{
public:
	dogCPP11() 
	{
		cout << "Inside dogCPP11()" << endl; 
		cout << "My age is: " << age_ << endl;
	}
	
	// The first constructor can be called at the initializer list part
	// of the second constructor. This will invoke the first constructor
	// before the second constructor starts!!!
	// Limitation is, first constructor can't be invoked in the middle
	// or at the end of the second constructor.
	dogCPP11(int a) : dogCPP11()
	{ 
		age_ = a;
		cout << "Inside dogCPP11(int a)" << endl; 
		cout << "My age is: " << age_ << endl;
	}

private:
	// C++11 also supports "in class data member initialization"
	// age_ will be initialized to 9, at every constructor!!!
	int age_ = 9;
};


int main(void)
{
	dogCPP11 a;
	dogCPP11 b(10);
	return 0;
}
#pragma endregion Delegating Constructor

#pragma region Override for Virtual Functions

// C++03
class dogCPP03
{
public:
	virtual void A(int) {}
	virtual void B() const {}
};

class yellowDog : public dogCPP03
{
public:
	virtual void A(float) {} // C++03, In Polymorphism, A(float) will not be called
	virtual void B(){}
};


// C++11

class dogCPP11
{
public:
	virtual void A(int) { cout << "dogCPP11::void A(int) " << endl; }
	virtual void B() const { cout << "dogCPP11::void B() const " << endl; }
	void c() { cout << "dogCPP11::void c() " << endl; }
};

class yellowDogCPP11 : public dogCPP11
{
	// ERRORS, compiler will through error
	//virtual void A(float) override { cout << "yellowDogCPP11::void A(float) " << endl; }
	//virtual void B() override { cout << "yellowDogCPP11::void B() " << endl; }
	//void c() override { cout << "yellowDogCPP11::void c() " << endl; }
};

int main(void)
{
	return 0;
}
#pragma endregion Override for Virtual Functions

#pragma region final


class dog final
{
public:
	dog() { cout << "dog::dog() " << endl; }
};

// Below code will through error since the base class dog is final!!!
//class yellowDog : public dog { };

class anotherDog
{
public:
	anotherDog() { cout << "anotherDog::anotherDog() " << endl; }
	virtual void bark(void) final
	{
		cout << "I am barking!!!" << endl;
	}
};

class yellowDog : public anotherDog
{
public:
	yellowDog() { cout << "yellowDog::yellowDog() " << endl; }
	// Below code will give error as the bark() is final!!!
	//void bark(void)
	//{
	//	cout << "I am barking!!!" << endl;
	//}
};

int main(void)
{
	return 0;
}

#pragma endregion final

#pragma region Compiler Generated Default Constructor

class dogCPP03
{
	int age_;
public:
	dogCPP03(int a) : age_(a) { cout << "dogCPP03::dogCPP03(int a) " << endl; }
};

class dogCPP11
{
	int age_;
public:
	dogCPP11(int a) : age_(a) { cout << "dogCPP11::dogCPP11(int a) " << endl; }
	// This will force the compiler to generate the 
	// default constructor!!!
	dogCPP11() = default;	
};
int main(void)
{
	// Below code will be ERROR, because we have already provided 
	// a constructor and the compiler will not generate any default 
	// constructor for us.
	//dogCPP03 d1;

	dogCPP11 d1;	// This is OK

	return 0;
}
#pragma endregion Compiler Generated Default Constructor

#pragma region delete
class dogCPP03
{
	int age_;
public:
	dogCPP03(int a) : age_(a) { cout << "dogCPP03::dogCPP03(int a) " << endl; }
};

class dogCPP11
{
	int age_;
public:
	dogCPP11(int a) : age_(a) { cout << "dogCPP11::dogCPP11(int a) " << endl; }
	dogCPP11(double) = delete;
	dogCPP11& operator=(const dogCPP11&) = delete;
};
int main(void)
{
	// C++03
	// This will work
	dogCPP03 d1(2);	

	// This will also work since the double is converted to int
	dogCPP03 d2(3.0);
	dogCPP03 d3(9);

	// This will also work, because compiler generates operator= for us
	d3 = d2; 
						
	// This is OK
	dogCPP11 d1_11(9);	
	// This will not work, because we have deleted the function
	//dogCPP11 d2_11(3.0);
	dogCPP11 d3_11(9);

	// This will not work, because we have deleted operator=
	//d3_11 = d1_11;

	return 0;
}
#pragma endregion delete

#pragma region constexpr

int return3(void) { return 3; }
constexpr int Aconstexpr(void) { return 3; }

int main(void)
{
	int arr[6];
	// This will not compile!!!
	//int arr6[return3() + 3];

	// C++11
	// This will work and the compiler will compute the expression 
	// during compile time!!!
	int arr6[Aconstexpr() + 3];

	return 0;
}

#pragma endregion constexpr

#pragma region New String Literals

int main(void)
{
	// C++03
	char* a = "string";

	// C++11
	char* aa = u8"string";		// to define UTF-8 string
	char16_t* b = u"string";	// to define UTF-16 string
	char32_t* c = U"string";	// to define UTF-32 string
	char* d = R"foo(string )foo";// to define raw string.

	return 0;
}

#pragma endregion New String Literals

#pragma region lambda function

template<typename func>
void filter(func f, vector<int> arr)
{
	for (auto i : arr)
	{
		if (f(i))
			cout << i << " ";
	}
	cout << endl;
}

int main(void)
{
	cout << [](int x, int y) { return x + y; }(3, 4) << endl;

	auto f = [](int x, int y) { return x + y; };
	cout << f(3, 4) << endl;

	vector<int> v = { 1, 2, 3, 4, 5, 6 };
		   /********* LAMBDA *********/
	filter([](int x) { return (x > 3); }, v);

	filter([](int x) { return ((x > 2) && (x < 5)); }, v);

	int y = 4;

	filter([&](int x) { return (x > y); }, v);

	return 0;
}

#pragma endregion lambda function