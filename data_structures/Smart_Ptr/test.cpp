//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{
//		cout << "SmartPtr(T* ptr)" << endl;
//	}
//
//	~SmartPtr()
//	{
//		if (_ptr != nullptr)
//		{
//			delete _ptr;
//			cout << "~SmartPtr()" << endl;
//		}
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//private:
//	T* _ptr;
//};
//
//
//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//	{
//		throw invalid_argument("除0错误");
//	}
//
//	return a / b;
//}
//
//void Func()
//{
//	SmartPtr<int> sp1(new int);
//	SmartPtr<int> sp2(new int);
//
//	cout << div() << endl;
//}
//
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch(const std::exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}

//
//int main()
//{
//	std::auto_ptr<int> ap1(new int(1));
//	*ap1 = 10; //ok
//	std::auto_ptr<int> ap2(ap1); // 拷贝或赋值后，所有权转移，ap1无法继续使用，
//	*ap2 = 20; //ok
//	*ap1 = 10; //错误
//
//	return 0;
//}

//int main()
//{
//	std::unique_ptr<int> up1(new int(0));
//	std::unique_ptr<int> up2(up1); //error
//	return 0;
//}


//int main()
//{
//	std::shared_ptr<int> sp1(new int(1));
//	std::shared_ptr<int> sp2(sp1);
//	*sp1 = 10;
//	*sp2 = 20;
//	cout << sp1.use_count() << endl; //2
//
//	std::shared_ptr<int> sp3(new int(1));
//	std::shared_ptr<int> sp4(new int(2));
//	sp3 = sp4;
//	cout << sp3.use_count() << endl; //2
//	return 0;
//}
//

//#include <memory>
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	std::auto_ptr<int> ap1(new int(1));
//	std::auto_ptr<int> ap2(ap1);
//	*ap2 = 10;
//	*ap1 = 20; //error
//
//	std::auto_ptr<int> ap3(new int(1));
//	std::auto_ptr<int> ap4(new int(2));
//	ap3 = ap4;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//namespace chen
//{
//	template<class T>
//	class auto_ptr
//	{
//	public:
//		auto_ptr(T* in)
//			:_ptr(in)
//		{
//
//		}
//
//		auto_ptr(auto_ptr<T>& in)
//			:_ptr(in._ptr)
//		{
//			in._ptr = nullptr;
//		}
//
//		auto_ptr& operator=(auto_ptr<T>& in)
//		{
//			if (this != &in)
//			{
//				// 先释放自己的资源
//				delete _ptr;
//				// 再把in的资源拿来
//				_ptr = in._ptr;
//				// 把in的_ptr置空
//				in._ptr = nullptr;
//			}
//			return *this;
//		}
//
//
//		// 像指针一样使用auto_ptr
//		T& operator*()
//		{
//			return *_ptr;
//		}
//
//		T* operator->()
//		{
//			return _ptr;
//		}
//
//		~auto_ptr()
//		{
//			if (_ptr != nullptr)
//			{
//				std::cout << "delete: " << _ptr << std::endl;
//				delete _ptr;
//				_ptr = nullptr;
//			}
//		}
//
//	private:
//		T* _ptr;
//	};
//}
//
//// 示例类
//class MyClass 
//{
//public:
//	void print() 
//	{
//		std::cout << "Hello from MyClass!" << std::endl;
//	}
//};
//
//int main() 
//{
//	chen::auto_ptr<MyClass> ptr(new MyClass());
//
//	// 使用 -> 访问对象的方法
//	// 下面三种方法都是一样的
//	ptr->print();
//	ptr.operator->()->print();
//	(*ptr).print();
//
//	return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

namespace chen
{

	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr != nullptr)
			{
				std::cout << "delete: " << _ptr << std::endl;
				delete _ptr;
				_ptr = nullptr;
			}
		}

		// 防拷贝
		unique_ptr(unique_ptr<T>&) = delete;
		unique_ptr& operator=(unique_ptr<T>&) = delete;

		// 像指针一样使用
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};

}

int main()
{
	//chen::unique_ptr<int> up1(new int(0));
	//chen::unique_ptr<int> up2(up1); //error: 尝试引用已删除的函数
	vector<int> arr = { 14, 15, 16,17, 18 };
	for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
	{
		cout << i << " ";
	}
	return 0;
}