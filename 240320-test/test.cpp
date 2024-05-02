//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//using namespace std;
//
//void Print(size_t n, const string& str, mutex& m, int& x)
//{
//	for (size_t i = 0; i < n; i++)
//	{
//		m.lock();
//		cout << str << this_thread::get_id() << ", counter: " << i << endl;
//		m.unlock();
//	}
//}
//
//int main()
//{
//	mutex mtx;
//
//	int x = 0;
//	thread t1(Print, 1000, "我是鹏哥：", ref(mtx), ref(x)); // ?
//	thread t2(Print, 1000, "我是蛋哥：", ref(mtx), ref(x));
//	thread t3(move(t2));
//
//	cout << "线程1：" << t1.get_id() << endl;
//	cout << "线程2：" << t1.get_id() << endl;
//	
//	t1.join();
//	// t2.join();
//	t3.join();
//	return 0;
//} 

//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//using namespace std;
//
//void Print(size_t n, const string& str, mutex& m, int& x)
//{
//	for (size_t i = 0; i < n; i++)
//	{
//		m.lock();
//		cout << str << this_thread::get_id() << ", counter: " << i << endl;
//		m.unlock();
//	}
//}
//
//int main()
//{
//	std::mutex mtx;
//	std::condition_variable cv;
//
//	this_thread::sleep_for(chrono::hours(1));
//
//	int sz = 1000;
//
//	thread t1([&]()
//		{
//			int i = 0;
//			while (i < sz)
//			{
//				std::lock_guard<std::mutex> lock(mtx);
//				cv.wait(lock, []() {});
//			}
//		
//		
//		});
//	return 0;
//}

//#include <exception>
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	try
//	{
//		new long long[99999999];
//	}
//	catch (std::exception & e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}

#include <mutex>
#include <thread>
#include <exception>
#include <iostream>
using namespace std;

// t1打印奇数
// t2打印偶数
// 交替打印
int main()
{
	mutex mtx;
	int x = 1;
	condition_variable cv;
	bool flag = false;


	// 如果保证t1先运行 condition_variable+flag
	// 交替运行
	thread t1([&]() {
		for (size_t i = 0; i < 10; i++)
		{
			unique_lock<mutex> lock(mtx);
			if (flag)
				cv.wait(lock);

			cout << this_thread::get_id() << ":" << x << endl;
			++x;

			flag = true;

			cv.notify_one(); // t1notify_one的时候 t2还没有wait
		}
		});


	thread t2([&]() {
		for (size_t i = 0; i < 10; i++)
		{
			unique_lock<mutex> lock(mtx);
			if (!flag)
				cv.wait(lock);

			cout << this_thread::get_id() << ":" << x << endl;
			++x;
			flag = false;

			cv.notify_one();
		}
		});

	t1.join();
	t2.join();

	return 0;
}