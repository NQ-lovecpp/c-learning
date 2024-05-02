//#include <iostream>  
//#include <thread>  
//#include <mutex>  
//#include <condition_variable>  
//#include <atomic>  
//
//using namespace std;
//
//// 使用互斥量  
//std::mutex mtx;
//
//void print_block(int n, char c) {
//    mtx.lock();
//    for (int i = 0; i < n; ++i) { std::cout << c; }
//    std::cout << '\n';
//    mtx.unlock();
//}
//
//void thread_func1() {
//    print_block(50, '*');
//}
//
//void thread_func2() {
//    print_block(50, '$');
//}
//
//// 使用条件变量  
//std::mutex cv_mtx;
//std::condition_variable cv;
//bool ready = false;
//
//void wait_for_signal() {
//    std::unique_lock<std::mutex> lock(cv_mtx);
//    while (!ready) {
//        cv.wait(lock);
//    }
//    std::cout << "Signal received, doing work...\n";
//}
//
//void send_signal() {
//    std::unique_lock<std::mutex> lock(cv_mtx);
//    ready = true;
//    cv.notify_one();
//}
//
//// 使用信号量（C++标准库没有直接提供信号量，但可以用其他机制模拟）  
//std::mutex sem_mtx;
//std::condition_variable sem_cv;
//std::atomic<int> sem_count{ 0 };
//
//void wait_for_semaphore() {
//    std::unique_lock<std::mutex> lock(sem_mtx);
//    while (sem_count == 0) {
//        sem_cv.wait(lock);
//    }
//    --sem_count;
//}
//
//void release_semaphore() {
//    std::unique_lock<std::mutex> lock(sem_mtx);
//    ++sem_count;
//    sem_cv.notify_one();
//}
//
//int main() {
//    int a = 10e100;
//    cout << a << endl;
//    std::thread t1(thread_func1);
//    std::thread t2(thread_func2);
//    t1.join();
//    t2.join();
//
//    std::thread waiter(wait_for_signal);
//    std::this_thread::sleep_for(std::chrono::seconds(1)); // 模拟一些工作  
//    send_signal();
//    waiter.join();
//
//    std::thread sem_waiter(wait_for_semaphore);
//    release_semaphore();
//    sem_waiter.join();
//
//    return 0;
//}


//#include <thread>
//#include <iostream>
//#include <functional>
//#include <Windows.h>
//using namespace std;
//
////1. 函数指针
////2. 仿函数
////3. lambda表达式
////4. 函数对象
////5. 被bind或functional包装器包装后的可调用对象等
//
//void func1(int start, int end)
//{
//	for (int i = start; i <= end; i++) { cout << i << " "; }
//	cout << endl;
//}
//
//
//struct My_class
//{
//	void operator()(int start, int end)
//	{
//		for (int i = start; i <= end; i++) { cout << i << " "; }
//		cout << endl;
//	}
//};
//My_class my_instance;
//
//int main()
//{
//	//1. 函数指针
//	thread t1(&func1, 1, 10);
//
//	Sleep(1);
//
//	//2. 仿函数 (函数对象)
//	thread t2(My_class(), 10, 20);
//
//	Sleep(1);
//
//	//3. lambda表达式
//	thread t3([](const string& str) ->void {cout << str << endl;}, "I am thread-3");
//
//	Sleep(1);
//
//	//4. 被bind或functional包装器包装后的可调用对象等
//	thread t4(std::function<void(int, int)>(func1), 100, 110);
//
//	Sleep(1);
//
//	thread t5(std::bind(&My_class::operator(), &my_instance, std::placeholders::_1, std::placeholders::_2), 220, 230);
//
//	Sleep(100);
//
//	cout << "thread-1: " << t1.get_id() << endl;
//	cout << "thread-2: " << t2.get_id() << endl;
//	cout << "thread-3: " << t3.get_id() << endl;
//	cout << "thread-4: " << t4.get_id() << endl;
//	cout << "thread-5: " << t5.get_id() << endl;
//
//	t1.join();
//	t2.join();
//	t3.join();
//	t4.join();
//	t5.join();
//	return 0;
//}



//#include <thread>
//#include <iostream>
//
//void ThreadFunc1(int& x)
//{
//	x += 10;
//}
//void ThreadFunc2(int* x)
//{
//	*x += 10;
//}
//int main()
//{
//	int a = 10;
//
//	// 问题：在线程函数中对a修改，不会影响外部实参
//	// 因为：线程函数参数虽然是引用方式，但其实际引用的是线程栈中的拷贝
//	//std::thread t1(ThreadFunc1, a);
//	//t1.join();
//	//std::cout << a << std::endl;
//
//	// 解决方法：
//	// 1. 如果想要通过形参改变外部实参时，必须借助std::ref()函数
//	std::thread t2(ThreadFunc1, std::ref(a));
//	t2.join();
//	std::cout << a << std::endl;
//
//	// 2. 地址的拷贝
//	std::thread t3(ThreadFunc2, &a);
//	t3.join();
//	std::cout << a << std::endl;
//
//	// 3. lambda表达式，在捕捉列表中添加a的引用
//	std::thread t4([&a] {a += 10;});
//	t4.join();
//	std::cout << a << std::endl;
//
//	return 0;
//}


//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//using namespace std;
//
//int main()
//{
//	try
//	{
//		recursive_mutex mtx;
//		mtx.lock();
//		mtx.lock();
//		mtx.lock();
//
//
//		mtx.unlock();
//		mtx.unlock();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}


//#include <iostream>  
//#include <thread>  
//#include <mutex>  
//
//std::mutex mtx1, mtx2;
//
//void thread_function1() {
//    mtx1.lock();
//    std::cout << "Thread 1 acquired mtx1.\n";
//    std::this_thread::sleep_for(std::chrono::seconds(1));
//    mtx2.lock(); // 尝试锁定mtx2  
//    std::cout << "Thread 1 acquired mtx2.\n";
//    mtx2.unlock();
//    mtx1.unlock();
//}
//
//void thread_function2() {
//    mtx2.lock();
//    std::cout << "Thread 2 acquired mtx2.\n";
//    std::this_thread::sleep_for(std::chrono::seconds(1));
//    mtx1.lock(); // 尝试锁定mtx1  
//    std::cout << "Thread 2 acquired mtx1.\n";
//    mtx1.unlock();
//    mtx2.unlock();
//}
//
//int main() {
//    std::thread t1(thread_function1);
//    std::thread t2(thread_function2);
//
//    t1.join();
//    t2.join();
//    return 0;
//}

//#include <iostream>  
//#include <thread>  
//#include <mutex>  
//
//std::recursive_mutex mtx;
//
//void recursive_function() 
//{
//    mtx.lock();
//    std::cout << "Thread " << std::this_thread::get_id() << " locked the mutex.\n";
//
//    // Recursive call  
//    recursive_function();
//
//    std::cout << "Thread " << std::this_thread::get_id() << " is about to unlock the mutex.\n";
//    mtx.unlock();
//}
//
//int main() 
//{
//    std::thread t(recursive_function);
//    t.join();
//    return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <mutex>
//#include <thread>
//#include <cstdio>
//#include "LockGuard.hpp"
//
//
//
//std::mutex mtx;
//void func()
//{
//	
//	//...
//	//匿名局部域
//	{
//		chen::lock_guard<std::mutex> lg(mtx); //调用构造函数加锁
//		FILE* fout = fopen("data.txt", "r");
//		if (fout == nullptr)
//		{
//			//...
//			return; //调用析构函数解锁
//		}
//	} //调用析构函数解锁
//	//...
//}
//int main()
//{
//	std::thread(t1)
//	std::cout << std::this_thread::get_id() << std::endl;
//	func();
//	return 0;
//}


//#include <iostream>
//#include <thread>
//#include <mutex>
//
//using namespace std;
//
//unsigned long sum = 0L;
//std::mutex mtx;
//
//void fun(size_t num)
//{
//	for (size_t i = 0; i < num; ++i)
//	{
//		mtx.lock();
//		sum++;
//		mtx.unlock();
//	}
//}
//
//int main()
//{
//	cout << "Before joining,sum = " << sum << std::endl;
//	thread t1(fun, 10000000);
//	thread t2(fun, 10000000);
//	t1.join();
//	t2.join();
//	cout << "After joining,sum = " << sum << std::endl;
//	return 0;
//}


#include <iostream>  
#include <mutex>  
#include <thread>  
#include <atomic>  
#include <chrono>  

using namespace std;
using namespace chrono;

struct my_class
{
    my_class(long num)
        :_number(num)
    {}

    long operator++(int)
    {
        _number++;
    }

    long _number;
};

std::mutex mtx;
long sum = 0;
atomic_long sum_atomic{ 0 };

atomic<my_class> amc(0);

// 方法1：加锁  
void fuc(size_t num)
{
    for (size_t i = 0; i < num; ++i)
    {
        mtx.lock();
        sum++; // 非原子操作  
        mtx.unlock();
    }
}

// 方法2：原子性操作  
void fuc_atomic(size_t num)
{
    for (size_t i = 0; i < num; ++i)
        amc++; // 原子操作  
}

int main()
{
    // 测量方法1的时间  
    auto start = high_resolution_clock::now();

    thread t1(fuc, 1000000);
    thread t2(fuc, 1000000);

    t1.join();
    t2.join();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Method 1 (mutex) took " << duration.count() << " milliseconds." << endl;
    cout << "After joining, sum = " << sum << endl;

    // 重置sum以便进行下一次测量  
    sum = 0;

    // 测量方法2的时间  
    start = high_resolution_clock::now();

    thread t3(fuc_atomic, 1000000);
    thread t4(fuc_atomic, 1000000);

    t3.join();
    t4.join();

    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);

    cout << "Method 2 (atomic) took " << duration.count() << " milliseconds." << endl;
    cout << "After joining, sum_atomic = " << sum_atomic << endl;

    return 0;
}


