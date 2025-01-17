#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>

using namespace std;


#pragma region Dead Lock


/*************************************************************
Why there is a dead lock?
Analysis:
	- Let say the function_1() calls shared_print() and it locks
	_mu_2 mutex. Before locking _mu mutex, main thread calls
	shared_print_2() function and locks mutex _mu. Now main thread
	is waiting for _mu_2 mutex and the t1() thread is waiting for
	_mu mutex. This is dead lock!!!
**************************************************************/
//class LogFile {
//	std::mutex _mu;
//	std::mutex _mu_2;
//public:
//	LogFile() {	}
//	void shared_print(string id, int value) 
//	{
//		std::lock_guard<mutex> locker(_mu);
//		std::lock_guard<mutex> locker1(_mu_2);
//		cout << "From " << id << ": " << value << endl;
//	}
//	void shared_print_2(string id, int value) 
//	{
//		std::lock_guard<mutex> locker1(_mu_2);
//		std::lock_guard<mutex> locker(_mu);
//		cout << "From " << id << ": " << value << endl;
//	}
//};
//

#pragma endregion Dead Lock

#pragma region Solution 1 - Lock in the same order
//class LogFile {
//	std::mutex _mu;
//	std::mutex _mu_2;
//public:
//	LogFile() {	}
//	void shared_print(string id, int value)
//	{
//		// Solution: lock the mutexes in a fixed order
//		std::lock_guard<mutex> locker(_mu);
//		std::lock_guard<mutex> locker1(_mu_2);
//		cout << "From " << id << ": " << value << endl;
//	}
//	void shared_print_2(string id, int value)
//	{
//		// Solution: lock the mutexes in a fixed order
//		std::lock_guard<mutex> locker(_mu);
//		std::lock_guard<mutex> locker1(_mu_2);
//		cout << "From " << id << ": " << value << endl;
//	}
//};
//

#pragma endregion Solution 1 - Lock in the same order

#pragma region std::lock()
class LogFile 
{
	std::mutex m_mutex;
	std::mutex m_mutex_2;
public:
	LogFile() { }
	void shared_print(string id, int value) 
	{
		// This lock() function provided by C++11 standard library can 
		// be used to lock arbitrary number of lockable objects such as
		// mutex using certain dead lock avoidance algorithm.
		std::lock(m_mutex, m_mutex_2);
		// adopt_lock, mutex is already locked and adopt to the ownership
		// of the lock.
		std::lock_guard<mutex> locker(m_mutex, std::adopt_lock);
		std::lock_guard<mutex> locker1(m_mutex_2, std::adopt_lock);
		cout << "From " << id << ": " << value << endl;
	}
	void shared_print_2(string id, int value) 
	{
		// The lock() function!!!
		std::lock(m_mutex, m_mutex_2);
		std::lock_guard<mutex> locker1(m_mutex_2, std::adopt_lock);
		std::lock_guard<mutex> locker(m_mutex, std::adopt_lock);
		cout << "From " << id << ": " << value << endl;
	}
};
#pragma endregion std::lock()

void function_1(LogFile& log)
{
	for (int i = 0; i > -100; --i)
		log.shared_print("t1", i);
}

int main(void)
{
	LogFile log;
	thread t1(&function_1, std::ref(log));

	for (int i = 0; i < 100; ++i)
		log.shared_print_2(string("From main"), i);

	t1.join();

	return 0;
}

/* Avoiding deadlock
1. Prefer locking single mutex at a time.
2. Avoid locking a mutex and then calling a user provided function.
3. Use std::lock() to lock more than one mutex.
4. Lock the mutex in same order.


Locking Granularity:
- Fine-grained lock:  protects small amount of data
- Coarse-grained lock: protects big amount of data
*/