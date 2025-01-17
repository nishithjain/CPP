#include <iostream>
#include <random>
#include <sstream>
#include <chrono>
#include <vector>
#include <string>

using namespace std;

int main(void) 
{
	unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
	default_random_engine e(seed);
	// This generates the random number in the range e.min to e.max()
	cout << e() << endl;

	// What if I want to generate the random number between 0 to 5?
	// How can we do that?
	cout << e() % 6 << endl;
	// 1. Bad quality of randomness.
	// 2. Can only provide uniform distribution 
	// What if we want values to be more distributed between 2 and 5
	// and less distributed at 2 and 5? This is why we need library 
	// of distribution.
	cout << e() % 6 << endl;


	// This will generate the random numbers between 0 and 5 (including 0 and 5)
	std::uniform_int_distribution<int> dist(0, 5);

	// Here 3 provides a sauce of randomness and dist provides a way to 
	// distribute the random number within certain range and with certain
	// probability.
	cout << dist(e) << endl;

	// Range is half open [0,5)
	std::uniform_real_distribution<double> distr(0, 5);
	cout << distr(e) << endl;

	std::poisson_distribution<int> disp(1.0);
	cout << disp(e) << endl;

	cout << "Normal Distribution.." << endl;
	// Mean and standard deviation
	std::normal_distribution<double> disNormal(10.0, 6.0);
	vector<int> v(20);
	for (int i = 0; i < 800; i++)
	{
		// Convert double to int
		int num = disNormal(e);
		if (num >= 0 && num < 20)
			v[num]++;
	}

	for (int i = 0; i < 20; i++)
		cout << i << ": " << std::string(v[i], '*') << endl;
	cout << endl;

	return 0; 
}