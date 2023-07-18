#include <iostream>
#include <thread>
#include <mutex>
using std::thread;
std::mutex mutest;

void func1() {
	for (int i = 0; i < 10; ++i) 
	{
		mutest.lock();
		std::cout << "쓰레드 1 작동중! " <<  i << "\n";
		mutest.unlock();
	}
}

void func2() {
	for (int i = 0; i < 30; ++i) 
	{
		mutest.lock();
		std::cout << "쓰레드 2 작동중! " << i << "\n";
		mutest.unlock();

		
	}
}

void func3() {
	for (int i = 0; i < 10; ++i) 
	{
		mutest.lock();
		std::cout << "쓰레드 3 작동중! " << i << "\n";
		mutest.unlock();
	}
}


int main() {

	thread t1(func1);
	thread t2(func2);
	thread t3(func3);

	t1.join();
	t2.join();
	t3.join();
}