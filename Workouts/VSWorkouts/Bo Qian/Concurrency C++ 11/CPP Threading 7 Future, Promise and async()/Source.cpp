#include <iostream>
#include <future>
#include <thread>

using namespace std;

#pragma region async()
//int factorial(int N)
//{
//	int res = 1;
//	for (int i = N; i > 1; i--)
//		res *= i;
//
//	return res;
//}
//
//int main()
//{
//	//future<int> fu = std::async(factorial, 4); 
//	future<int> fu = std::async(std::launch::deferred | std::launch::async, factorial, 4);
//	cout << "Got from child thread #: " << fu.get() << endl;
//	// fu.get();  // crash
//	return 0;
//}
#pragma endregion async()



/* Asynchronously provide data with promise */
int factorial(future<int>& f)
{
	// do something else

	int N = f.get();     // If promise is destroyed, exception: std::future_errc::broken_promise
	cout << "Got from parent: " << N << endl;
	int res = 1;
	for (int i = N; i > 1; i--)
		res *= i;

	return res;
}

int main() {
	promise<int> p;
	future<int> f = p.get_future();

	future<int> fu = std::async(std::launch::async, factorial, std::ref(f));

	// Do something else
	std::this_thread::sleep_for(chrono::milliseconds(20));
	//p.set_value(5);   
	//p.set_value(28);  // It can only be set once
	p.set_exception(std::make_exception_ptr(std::runtime_error("Flat tire")));

	cout << "Got from child thread #: " << fu.get() << endl;
	return 0;
}