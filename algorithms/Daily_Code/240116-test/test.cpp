//#include <iostream>
//#include <map>
//#include <string>
//#include <utility>
//using namespace std;



// 饿汉模式
// 优点：简单
// 缺点：可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不确定。
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return m_instance;
//	}
//
//private:
//	// 构造函数私有
//	Singleton()
//	{};
//
//	//// C++98 防拷贝
//	//Singleton(Singleton const&);
//	//Singleton& operator=(Singleton const&);
//
//	// or
//
//	// C++11
//	Singleton(Singleton const&) = delete;
//	Singleton& operator=(Singleton const&) = delete;
//
//	static Singleton* m_instance;
//};
//// 在程序入口之前就完成单例对象的初始化
//Singleton* Singleton::m_instance = new Singleton;
//
//
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return &m_instance;
//	}
//
//	void Add(const string& key, const string& value)
//	{
//		_dict[key] = value;
//	}
//
//	void Print()
//	{
//		for (auto& kv : _dict)
//		{
//			cout << kv.first << ":" << kv.second << endl;
//		}
//		cout << endl;
//	}
//
//private:
//	// 构造函数私有
//	Singleton()
//	{};
//
//	// C++11
//	Singleton(Singleton const&) = delete;
//	Singleton& operator=(Singleton const&) = delete;
//
//	map<string, string> _dict;
//	int _n = 0;
//
//	static Singleton m_instance;
//};
//
//// 静态成员变量必须在类外进行定义。
//// 这是因为静态成员变量不属于任何类的对象或实例，
//// 它们是类的一部分。在类外定义静态成员变量可以为其分配内存。
//// 如果不在类外定义，编译器就不会为其分配内存，从而导致链接错误。
//Singleton Singleton::m_instance;
//
//int main()
//{
//	Singleton::GetInstance()->Add("hello", "你好");
//	Singleton::GetInstance()->Add("sort", "排序");
//	Singleton::GetInstance()->Add("patience", "耐心");
//	Singleton::GetInstance()->Print();
//	cout << (void*)Singleton::GetInstance() << endl;
//	cout << (void*)Singleton::GetInstance() << endl;
//	cout << (void*)Singleton::GetInstance() << endl;
//	return 0;
//}



//// 懒汉
//// 优点：第一次使用实例对象时，创建对象。进程启动无负载。多个单例实例启动顺序自由控制。
//// 缺点：复杂
//#include <iostream>
//#include <mutex>
//#include <thread>
//using namespace std;
//
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
//		if (nullptr == m_pInstance)
//		{
//			m_mtx.lock();
//			if (nullptr == m_pInstance)
//			{
//				m_pInstance = new Singleton();
//			}
//			m_mtx.unlock();
//		}
//		return m_pInstance;
//	}
//	// 实现一个内嵌垃圾回收类
//	class CGarbo
//	{
//	public:
//		~CGarbo()
//		{
//			if (Singleton::m_pInstance)
//				delete Singleton::m_pInstance;
//		}
//	};
//	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
//	static CGarbo Garbo;
//private:
//	// 构造函数私有
//	Singleton() {};
//	// 防拷贝
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//	static Singleton* m_pInstance; // 单例对象指针
//	static mutex m_mtx; //互斥锁
//};
//Singleton* Singleton::m_pInstance = nullptr;
//Singleton::CGarbo Garbo;
//mutex Singleton::m_mtx;
//void func(int n)
//{
//	cout << Singleton::GetInstance() << endl;
//}
//
//// 多线程环境下才能演示上面GetInstance()加锁和不加锁的区别
//int main()
//{
//	thread t1(func, 10);
//	thread t2(func, 10);
//	t1.join();
//	t2.join();
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//}


#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

//class CopyBan
//{
//public:
//    CopyBan() {}
//private:
//    CopyBan(const CopyBan&);
//    CopyBan& operator=(const CopyBan&);
//};
//
//
//int main() 
//{
//    CopyBan obj1;
//    // 尝试复制构造
//    CopyBan obj2 = obj1;  // 编译错误:"CopyBan::CopyBan(const CopyBan &)" 不可访问
//
//    // 尝试赋值
//    CopyBan obj3;
//    obj3 = obj1;  // 编译错误:"CopyBan &CopyBan::operator=(const CopyBan &)" 不可访问	
//
//
//    return 0;
//}


//class HeapOnly
//{
//public:
//	static HeapOnly* CreateObject()
//	{
//		return new HeapOnly; //在HeapOnly的类作用域里可以调到private的构造函数
//	}
//private:
//	HeapOnly() {}
//
//	// C++98
//	//  1.只声明,不实现。因为实现可能会很麻烦，而你本身不需要
//	//  2.声明成私有
//	HeapOnly(const HeapOnly&);
//
//	// C++11
//	HeapOnly(const HeapOnly&) = delete;
//};
//
//int main()
//{
//	HeapOnly* hp = new HeapOnly; // 编译错误，因为new创建对象也要调用构造函数的，但是你已经私有化构造函数了
//	return 0;
//}


//class StackOnly
//{
//public:
//	static StackOnly CreateObj()
//	{
//		return StackOnly();
//	}
//	// 禁掉operator new可以把下面用new 调用拷贝构造申请对象给禁掉
//	// StackOnly obj = StackOnly::CreateObj();
//	// StackOnly* ptr3 = new StackOnly(obj);
//	void* operator new(size_t size) = delete;
//	void operator delete(void* p) = delete;
//private:
//	StackOnly()
//		:_a(0)
//	{}
//private:
//	int _a;
//};


//class StackOnly
//{
//public:
//	StackOnly() {}
//private:
//	void* operator new(size_t size) = delete;
//	void operator delete(void* p) = delete;
//};
//
//int main()
//{
//	StackOnly so;
//	StackOnly* p = new StackOnly;
//
//	static StackOnly sso;
//	return 0;
//}


//class NonInherit
//{
//public:
//	static NonInherit GetInstance()
//	{
//		return NonInherit();
//	}
//private:
//	NonInherit()
//	{}
//};
//
//class B : public NonInherit
//{
//	B()
//		:NonInherit()
//	{}
//};
//
//
//int main()
//{
//	B b;
//	return 0;
//}


class A final
{
	// ...
};

class B :public A
{
	// ...
};