#include <deque>
#include <functional>
#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include <mutex>
#include <condition_variable>

std::deque<int> q;
std::mutex mu;
std::condition_variable cond;

using namespace std;

//void function_1() 
//{
//	int count = 10;
//	while (count > 0) 
//	{
//		std::unique_lock<mutex> locker(mu);
//		q.push_front(count);
//		locker.unlock();
//		std::this_thread::sleep_for(chrono::seconds(1));
//		count--;
//	}
//}
//
///*************************************************************
//Thread t2(function_2) is busy looping. It will unlock the locker
//if the queue is empty and will wait.
//**************************************************************/
//void function_2() 
//{
//	int data = 0;
//	while (data != 1) 
//	{
//		std::unique_lock<mutex> locker(mu);
//		if (!q.empty())
//		{
//			data = q.back();
//			q.pop_back();
//			locker.unlock();
//			cout << "t2 got a value from t1: " << data << endl;
//		}
//		else 
//		{
//			locker.unlock();
//		}
//		// This will largely reduce number of looping
//		std::this_thread::sleep_for(chrono::milliseconds(10));
//	}
//}
// It is hard to set the sleep time.

void function_1() 
{
	int count = 10;
	while (count > 0) 
	{
		std::unique_lock<mutex> locker(mu);
		q.push_front(count);
		locker.unlock();
		cond.notify_one();  // Notify one waiting thread, if there is one.
		std::this_thread::sleep_for(chrono::seconds(1));
		count--;
	}
}

void function_2() 
{
	int data = 0;
	while (data != 1) 
	{
		std::unique_lock<mutex> locker(mu);
		cond.wait(locker, [](){ return !q.empty(); });  // Unlock mu and wait to be notified
		// relock mu
		data = q.back();
		q.pop_back();
		locker.unlock();
		cout << "t2 got a value from t1: " << data << endl;
	}
}
int main(void) 
{
	std::thread t1(function_1);
	std::thread t2(function_2);
	t1.join();
	t2.join();
	return 0;
}