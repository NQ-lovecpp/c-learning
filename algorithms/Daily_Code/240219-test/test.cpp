//#include <iostream>
//
//int main() 
//{
//    double doubleValue = 3.14;
//    int intValue = static_cast<int>(doubleValue);
//
//    std::cout << "Double value: " << doubleValue << std::endl;
//    std::cout << "Converted to int: " << intValue << std::endl;
//
//    return 0;
//}


//#include <iostream>
//
//class Base 
//{
//public:
//    virtual void print() 
//    {
//        std::cout << "Base class" << std::endl;
//    }
//};
//
//class Derived : public Base 
//{
//public:
//    virtual void print() override 
//    {
//        std::cout << "Derived class" << std::endl;
//    }
//};
//
//int main() 
//{
//    Derived derivedObj;
//    Base* basePtr = &derivedObj;
//
//    // 使用 static_cast 进行基类指针到派生类指针的转换
//    Derived* derivedPtr = static_cast<Derived*>(basePtr);
//
//    derivedPtr->print();  // 输出 "Derived class"
//
//    return 0;
//}


//int main()
//{
//	int a = 123;
//	int* int_ptr = &a;
//	char* char_ptr1 = int_ptr; // 编译错误
//	char* char_ptr2 = (char*)int_ptr; // 没有编译错误
//	char* char_ptr3 = static_cast<char*> (int_ptr); // 编译错误：类型转换无效
//}

//#include <iostream>
//
//int main() 
//{
//    double doubleValue = 3.14;
//
//    // C 语言风格的强制类型转换
//    int intValueCStyle = (int)doubleValue;
//
//    // C++ 的 static_cast
//    int intValueStaticCast = const_cast<int>(doubleValue);
//
//    std::cout << "C-style cast result: " << intValueCStyle << std::endl;
//    std::cout << "static_cast result: " << intValueStaticCast << std::endl;
//
//    return 0;
//}


//#include <iostream>
//
//int main() 
//{
//    int Value = 42;
//    
//    //四种指针
//    int* int_Ptr = &Value;
//    const int* const_int_Ptr = &Value;
//    int const* int_const_Ptr = &Value;
//    const int* const  const_int_const_Ptr = &Value;
//
//
//    // 使用 const_cast 修改 const 属性
//    int* Ptr1 = const_cast<int*>(int_Ptr);   // int* -> int*
//    const int* Ptr2 = const_cast<const int*>(int_Ptr); // int* -> const int*
//    // 续写...
//    const int* ConstPtr2 = const_cast<const int*>(constPtr); // 这样没有语法错误，但是没有意义
//
//
//
//    //int* nonConstPtr2 = static_cast<int*>(constPtr); //static_cast 无法丢掉常量或其他类型限定符
//
//
//    // 修改变量的值
//    *nonConstPtr1 = 55;
//
//    // 输出修改后的值
//    std::cout << "Modified value: " << nonConstValue << std::endl;
//
//    return 0;
//}


//#include <iostream>
//
//int main() {
//    const int Value = 42;
//
//    // 四种指针
//    int* int_Ptr = &Value;
//    const int* const_int_Ptr = &Value;
//    int const* int_const_Ptr = &Value;
//    const int* const const_int_const_Ptr = &Value;
//
//    // 使用 const_cast 修改 const 属性
//
//    // 1. int* -> int*
//    int* Ptr1 = const_cast<int*>(int_Ptr);
//
//    // 2. int* -> const int*
//    const int* Ptr2 = const_cast<const int*>(int_Ptr);
//
//    // 3. const int* -> int*
//    int* Ptr3 = const_cast<int*>(const_int_Ptr);
//
//    // 4. const int* -> const int*
//    const int* Ptr4 = const_cast<const int*>(const_int_Ptr);
//
//    // 5. int const* -> int*
//    int* Ptr5 = const_cast<int*>(int_const_Ptr);
//
//    // 6. int const* -> const int*
//    const int* Ptr6 = const_cast<const int*>(int_const_Ptr);
//
//    // 7. const int* const -> int*
//    int* Ptr7 = const_cast<int*>(const_int_const_Ptr);
//
//    // 8. const int* const -> const int*
//    const int* Ptr8 = const_cast<const int*>(const_int_const_Ptr);
//
//    // 9. int* const -> int*
//    int* Ptr9 = const_cast<int*>(int_const_Ptr);
//
//    // 10. int* const -> const int*
//    const int* Ptr10 = const_cast<const int*>(int_const_Ptr);
//
//    // 11. const int* const -> int* const
//    int* const Ptr11 = const_cast<int* const>(const_int_const_Ptr);
//
//    // 12. const int* const -> const int* const
//    const int* const Ptr12 = const_cast<const int* const>(const_int_const_Ptr);
//
//    // 13. const int* const -> int const*
//    int const* Ptr13 = const_cast<int const*>(const_int_const_Ptr);
//
//    // 14. const int* const -> const int const*
//    const int const* Ptr14 = const_cast<const int const*>(const_int_const_Ptr);
//
//    // 15. int const* const -> int*
//    int* Ptr15 = const_cast<int*>(int_const_Ptr);
//
//    // 16. int const* const -> const int*
//    const int* Ptr16 = const_cast<const int*>(int_const_Ptr);
//
//    // 输出测试结果
//    std::cout << "Value: " << Value << std::endl;
//    std::cout << "Modified Values:" << std::endl;
//    std::cout << "Ptr1: " << *Ptr1 << std::endl;
//    std::cout << "Ptr2: " << *Ptr2 << std::endl;
//    std::cout << "Ptr3: " << *Ptr3 << std::endl;
//    std::cout << "Ptr4: " << *Ptr4 << std::endl;
//    std::cout << "Ptr5: " << *Ptr5 << std::endl;
//    std::cout << "Ptr6: " << *Ptr6 << std::endl;
//    std::cout << "Ptr7: " << *Ptr7 << std::endl;
//    std::cout << "Ptr8: " << *Ptr8 << std::endl;
//    std::cout << "Ptr9: " << *Ptr9 << std::endl;
//    std::cout << "Ptr10: " << *Ptr10 << std::endl;
//    std::cout << "Ptr11: " << *Ptr11 << std::endl;
//    std::cout << "Ptr12: " << *Ptr12 << std::endl;
//    std::cout << "Ptr13: " << *Ptr13 << std::endl;
//    std::cout << "Ptr14: " << *Ptr14 << std::endl;
//    std::cout << "Ptr15: " << *Ptr15 << std::endl;
//    std::cout << "Ptr16: " << *Ptr16 << std::endl;
//
//    return 0;
//}

//#include <string>
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int a = 123;
//	int* ip = &a;
//	char* pc1 = reinterpret_cast<char*>(ip);
//	char* pc2 = static_cast<char*>(ip);     //这里使用static_cast会报错：类型转化无效
//	char* pc3 = const_cast<char*>(ip);     //const_cast不能修改基础类型
//
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class A
//{
//public:
//	virtual void f() {}
//};
//
//class B : public A
//{
//	virtual void f() override {}
//};
//
//void fun(A* pa)
//{
//	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回0
//	B* pb1 = static_cast<B*>(pa);
//	B* pb2 = dynamic_cast<B*>(pa);
//	cout << "pb1:" << pb1 << endl;
//	cout << "pb2:" << pb2 << endl;
//}
//
//int main()
//{
//	A a;
//	B b;
//	fun(&a);
//	fun(&b);
//	return 0;
//}

//#include <iostream>
//
//int main() 
//{
//    int intValue = 0x12345678;
//
//    // 使用 reinterpret_cast 将 int* 转化为 char*
//    char* charPtr = reinterpret_cast<char*>(&intValue);
//
//    // 输出每个字节的十六进制表示
//    std::cout << "Memory content: ";
//    for (int i = 0; i < sizeof(int); ++i) 
//    {
//        std::cout << std::hex << static_cast<int>(charPtr[i]) << " ";
//    }
//    std::cout << std::endl;
//
//    // 判断平台是大端还是小端
//    if (charPtr[0] == 0x78) 
//    {
//        std::cout << "该平台是小端" << std::endl;
//    }
//    else if (charPtr[sizeof(int) - 1] == 0x78) 
//    {
//        std::cout << "该平台是大端" << std::endl;
//    }
//    else 
//    {
//        std::cout << "大小端未知" << std::endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <typeinfo>
//
//class A
//{
//public:
//    virtual void f() {}
//};
//
//class B : public A
//{
//    virtual void f() override {}
//};
//
//int main()
//{
//    A a;
//    B b;
//
//
//    // 子类对象指针/引用 -> 父类指针/引用
//    // dynamic_cast<type*>(e)
//    A* ptrA = dynamic_cast<A*>(&b);
//    if (ptrA) 
//    {
//        std::cout << "从B*到A*的动态转换成功。" << std::endl;
//    }
//    else 
//    {
//        std::cout << "从B*到A*的动态转换失败。" << std::endl;
//    }
//
//    // dynamic_cast<type&>(e)
//    try 
//    {
//        A& refA = dynamic_cast<A&>(b);
//        std::cout << "从B&到A&的动态转换成功。" << std::endl;
//    }
//    catch (const std::bad_cast& e) 
//    {
//        std::cout << "从B&到A&的动态转换失败。" << std::endl;
//    }
//
//    // dynamic_cast<type&&>(e) - 注意：这种用法不常见，通常情况下我们不会将右值引用作为 dynamic_cast 的目标
//    try 
//    {
//        A&& rrefA = dynamic_cast<A&&>(std::move(b));
//        std::cout << "从B&&到A&&的动态转换成功。" << std::endl;
//    }
//    catch (const std::bad_cast& e) 
//    {
//        std::cout << "从B&&到A&&的动态转换失败。" << std::endl;
//    }
//
//    // 父类对象指针/引用 -> 子类指针/引用
//    // dynamic_cast<type*>(e)
//    B* ptrB = dynamic_cast<B*>(&a);
//    if (ptrB)
//    {
//        std::cout << "从A*到B*的动态转换成功。" << std::endl;
//    }
//    else 
//    {
//        std::cout << "从A*到B*的动态转换失败。" << std::endl;
//    }
//
//    // dynamic_cast<type&>(e)
//    try
//    {
//        B& refB = dynamic_cast<B&>(a);
//        std::cout << "从A&到B&的动态转换成功。" << std::endl;
//    }
//    catch (const std::bad_cast& e)
//    {
//        std::cout << "从A&到B&的动态转换失败。" << std::endl;
//    }
//
//    // dynamic_cast<type&&>(e)
//    try
//    {
//        B&& rrefB = dynamic_cast<B&&>(std::move(a));
//        std::cout << "从A&&到B&&的动态转换成功。" << std::endl;
//    }
//    catch (const std::bad_cast& e)
//    {
//        std::cout << "从A&&到B&&的动态转换失败。" << std::endl;
//    }
//
//
//    return 0;
//}


//#include <iostream>
//#include <typeinfo>
//
//class Base
//{
//public:
//    virtual ~Base() {}
//};
//
//class Derived : public Base {};
//
//int main()
//{
//    Base* basePtr = new Derived();
//
//    // 使用 typeid 获取对象的类型信息
//    const std::type_info& typeInfo = typeid(*basePtr);
//
//    // 比较类型信息
//    if (typeInfo == typeid(Derived))
//    {
//        std::cout << "basePtr 指向 Derived 类型的对象。" << std::endl;
//    }
//    else if (typeInfo == typeid(Base))
//    {
//        std::cout << "basePtr 指向 Base 类型的对象。" << std::endl;
//    }
//
//    delete basePtr;
//
//    return 0;
//}


//#include <iostream>
//#include <typeinfo>
//
//using namespace std;
//
//// decltype的一些使用使用场景
//template<class T1, class T2>
//void F(T1 t1, T2 t2)
//{
//	decltype(t1 * t2) ret;
//	cout << typeid(ret).name() << endl;
//}
//
//int main()
//{
//	const int x = 1;
//	double y = 2.2;
//	decltype(x * y) ret; // ret的类型是double
//	decltype(&x) p; // p的类型是const int*
//	cout << typeid(ret).name() << endl;
//	cout << typeid(p).name() << endl;
//	F(1, 'a');
//	return 0;
//}


//#include <stdarg.h>
//#include <stdio.h>
//
//int sum(int count, ...) 
//{
//    int result = 0;
//    va_list args;
//    va_start(args, count);
//
//    for (int i = 0; i < count; ++i) 
//    {
//        result += va_arg(args, int);
//    }
//
//    va_end(args);
//    return result;
//}
//
//int main() 
//{
//    int total = sum(3, 10, 20, 30);
//    printf("Sum: %d\n", total);
//
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//// Args是一个模板参数包，args是一个函数形参参数包
//// 声明一个参数包Args...args，这个参数包中可以包含0到任意个模板参数。
//template <class ...Args>
//void ShowList(Args... args)
//{
//	cout << sizeof...(args) << endl;
//	cout << sizeof...(Args) << endl;
//}
//
//int main()
//{
//	ShowList(1, 2, 3, 4, 5, 6);
//	ShowList(1, 2, 3, 4, 5);
//	ShowList(1, 2, 3, 4);
//	ShowList(1, 2, 3);
//	return 0;
//}

//#include <iostream>
//
//// 递归展开模板参数包
//// 递归终止函数
//template<typename T>
//void print(T value)
//{
//    std::cout << value << std::endl;
//}
//
//// 展开函数
//template<typename T, typename... Args>
//void print(T first, Args... args)
//{
//    std::cout << first << ", ";
//    print(args...);
//}
//
//int main()
//{
//    print(1, 2.5, "Hello", 'a');
//
//    return 0;
//}


//#include <iostream>
//
//template <class T>
//void PrintArg(T t)
//{
//	cout << t << " ";
//}
////展开函数
//template <class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { (PrintArg(args), 0)... };
//	cout << endl;
//}
//int main()
//{
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//	return 0;
//}



#include <iostream>
#include <string>
#include <list>
using namespace std;
//
////支持无参调用
//void ShowList()
//{
//	cout << endl;
//}
////处理函数
//template<class T>
//void PrintArg(const T& t)
//{
//	cout << t << " ";
//}
////展开函数
//template<class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { (PrintArg(args), 0)... }; //列表初始化+逗号表达式
//	cout << endl;
//}
//
//int main()
//{
//	list<pair<int, string>> ls;
//	ls.emplace_back(1, "nihao");
//	ls.emplace_back(pair<int,string>(1, "nihao"));
//	ls.emplace_back(make_pair(1, static_cast<string>("nihao")));
//	ls.emplace_back(static_cast<pair<int, string>>(make_pair(1, "nihao")));
//	ls.push_back({ 1,static_cast<string>("nihao") });
//	static_cast<pair<int, string>>(pair<int, const char*>( 1, "nihao" ));
//	return 0;
//}



template<class F, class T>
T useF(F f, T x)
{
	static int count = 0;
	cout << "count:" << ++count << endl;
	cout << "count:" << &count << endl;
	return f(x);
}
double f(double i)
{
	return i / 2;
}
struct Functor
{
	double operator()(double d)
	{
		return d / 3;
	}
};
int main()
{
	// 函数名
	cout << useF(f, 11.11) << endl;
	// 函数对象
	cout << useF(Functor(), 11.11) << endl;
	// lambda表达式
	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
	return 0;
}


// 使用方法如下：
//#include <functional>
//int f(int a, int b)
//{
//	return a + b;
//}
//struct Functor
//{
//public:
//	int operator() (int a, int b)
//	{
//		return a + b;
//	}
//};
//class Plus
//{
//public:
//	static int plusi(int a, int b)
//	{
//		return a + b;
//	}
//	double plusd(double a, double b)
//	{
//		return a + b;
//	}
//};
//int main()
//{
//	// 函数名(函数指针)
//	std::function<int(int, int)> func1 = f;
//	cout << func1(1, 2) << endl;
//
//	// 函数对象
//	std::function<int(int, int)> func2 = Functor();
//	cout << func2(1, 2) << endl;
//
//	// lambda表达式
//	std::function<int(int, int)> func3 = [](const int a, const int b)
//		{return a + b; };
//	cout << func3(1, 2) << endl;
//
//	// 类的成员函数
//	std::function<int(int, int)> func4 = &Plus::plusi;
//	cout << func4(1, 2) << endl;
//	std::function<double(Plus, double, double)> func5 = &Plus::plusd;
//	cout << func5(Plus(), 1.1, 2.2) << endl;
//
//	return 0;
//}

//#include <functional>
//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	return f(x);
//}
//double f(double i)
//{
//	return i / 2;
//}
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};
//int main()
//{
//	// 函数名
//	std::function<double(double)> func1 = f;
//	cout << useF(func1, 11.11) << endl;
//	// 函数对象
//	std::function<double(double)> func2 = Functor();
//	cout << useF(func2, 11.11) << endl;
//	// lambda表达式
//	std::function<double(double)> func3 = [](double d)->double { return d / 4; };
//	cout << useF(func3, 11.11) << endl;
//	return 0;
//}