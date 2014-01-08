#include "ThreadTest.h"
#include <thread>
#include <iostream>
#include <mutex>
using namespace std;

class MyClass
{
public:
	void foo(int& i)
	{
		std::mutex lock;
		std::lock_guard<std::mutex> guard(lock);
		cout<<"MyClass: "<<++i<<endl;
	}
};


void foo(int& i)
{
	//stdout is the shared resource
	std::mutex lock;
	std::lock_guard<std::mutex> guard(lock);
	cout<<"foo function: "<<++i<<endl;
}

void ThreadTest()
{
	
	MyClass myClass;
	int i = 4;
	thread t(&MyClass::foo, myClass, std::ref(i));
	thread t2(foo, std::ref(i));
	t2.join();
	t.join();
}