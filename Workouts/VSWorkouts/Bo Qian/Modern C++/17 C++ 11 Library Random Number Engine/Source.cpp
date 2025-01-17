#include <iostream>
#include <random>
#include <sstream>
#include <chrono>
#include <vector>

using namespace std;
/*************************************************************
			Library Random Number Engine
	- Random number library is made of 2 parts...
	1. Random number engine.
	2. Random number distribution.
Random number engine.
- Stateful generator that generates random values within predefined
min and max.
- The numbers generated are not truly random but they are pseudo random.
**************************************************************/

void printRandom(std::default_random_engine e)
{
	for (int i = 0; i < 10; i++)
		cout << e() << " ";
	cout << endl;
}

int main(void) 
{ 
	{
		std::default_random_engine eng;

		cout << "Min: " << eng.min() << endl;
		cout << "Max: " << eng.max() << endl;

		// This will generate 1 random value
		cout << eng() << endl;
		// This will generate another random value
		cout << eng() << endl;

		//Engine has internal state which determines what kind of
		// random value it generates

		std::stringstream state;

		// Saves the current state into variable state.
		state << eng;

		cout << eng() << endl;
		cout << eng() << endl;

		// Will restore the state.
		state >> eng;

		// If the engine is in the same state, it will always generates the
		// same values!!!
		cout << eng() << endl;
		cout << eng() << endl;

	}

	{
		default_random_engine e;
		default_random_engine e2;
/*************************************************************
	Two different random engine are printing the same set of values
	Often times we don't want this. This is why we need seed!!!
**************************************************************/
		printRandom(e);
		printRandom(e2);

/*************************************************************
	So we will create a 3rd Random engine with seed!!!
	What is a seed then?
	- Seed is a number which determines the internal state of 
	the engine!!!
**************************************************************/
		unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
		std::default_random_engine e3(seed);

		printRandom(e3);

		// This will reset the engine 'e' to initial state!!!
		e.seed(); 
		// This will set the engine 'e' to a state according to seed 109
		e.seed(109);
		e2.seed(109);

		if (e == e2)
			cout << "e and e2 are in the same state!!!" << endl;
	}

	return 0; 
}