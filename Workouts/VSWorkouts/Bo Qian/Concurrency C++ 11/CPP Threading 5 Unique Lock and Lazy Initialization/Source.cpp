#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>

using namespace std;

#pragma region unique_lock
//class LogFile 
//{
//	std::mutex m_mutex;
//	ofstream f;
//public:
//	LogFile() 
//	{
//		f.open("log.txt");
//	}
//	void shared_print(string id, int value) 
//	{
//		// defer_lock make the locker not to lock the mutex
//		std::unique_lock<mutex> locker(m_mutex, std::defer_lock);
//		// Now the mutex is locked
//		locker.lock();  
//		f << "From " << id << ": " << value << endl;
//		// We can unlock the mutex
//		locker.unlock();
//	}
//};
#pragma endregion unique_lock

#pragma region Lazy Initialization
//class LogFile 
//{
//	std::mutex m_mutex;
//	ofstream f;
//public:
//	void shared_print(string id, int value) 
//	{
//		if (!f.is_open()) // lazy initialization   -- A
//		{   
//			std::unique_lock<mutex> locker(m_mutex);
//			if (!f.is_open()) 
//			{
//				f.open("log.txt");   // This must be synchronized  -- B
//			}
//		}
//		f << "From " << id << ": " << value << endl;  // I don't care this is not synchronized
//	}
//};
#pragma endregion Lazy Initialization


#pragma region call_once()

class LogFile 
{
	std::mutex m_mutex;
	ofstream f;
	std::once_flag _flag;
	void init() { f.open("log.txt"); }
public:
	void shared_print(string id, int value) 
	{
		std::call_once(_flag, &LogFile::init, this); // init() will only be called once by one thread
		//std::call_once(_flag, [&](){ f.open("log.txt"); });  // Lambda solution
		//std::call_once(_flag, [&](){ _f.open("log.txt"); });  // file will be opened only once by one thread
		cout << "From " << id << ": " << value << endl;
	}
};
#pragma endregion call_once()

class Fctor 
{
	LogFile& m_log;
public:
	Fctor(LogFile& log) :m_log(log) {}
	void operator()() 
	{
		for (int i = 0; i > -100; i--)
			m_log.shared_print("t1", i);
	}
};

int main(void) 
{
	LogFile log;

	Fctor fctor(log);
	std::thread t1(fctor);

	for (int i = 0; i < 100; i++)
		log.shared_print("main", i);

	t1.join();

	return 0;
}