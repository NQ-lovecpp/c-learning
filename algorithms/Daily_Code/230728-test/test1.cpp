//#include <iostream>
//using namespace std;
//
//class A
//{
//public:
//    A(int a)
//        :_a1(a)
//        , _a2(_a1)
//    {}
//
//    void Print()
//    {
//        cout << _a1 << " " << _a2 << endl;
//    }
//
//private:
//    int _a2;
//    int _a1;
//};
//
//
//
//int main()
//{
//    A aa(1);
//    aa.Print();
//}


//
//#include <iostream>
//using namespace std;
//
//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{
//			
//	}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	B(int a, int ref)
//		//:_aobj(a)
//		//, _ref(ref)
//		//, _n(10)
//	{}
//private:
//	int i = 0;
//	A _aobj;      // 没有默认构造函数
//	int& _ref;    // 引用
//	const int _n; // const
//};
//
//int main()
//{
//	A a1(1);
//	B b1(1,2);
//	return 0;
//}



//class Time
//{
//public:
//	Time(int hour = 0)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	Date(int day)
//	{}
//private:
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//	Date d(1);
//}

#include <iostream>
using namespace std;

class Date
{
public:
	// 初始化列表是每个成员定义的地方 
	// 对自定义类型会调用它的默认构造函数 内置类型没给初始值就赋予随机值
	// 不管写不写，每个成员都要走初始化列表
	Date(int year, int month, int day, int& i)
		: _year(year)//每个变量的定义处
		, _month(month)
		, _day(day)
		, _haha(1)
		, ref(i)

	{}
private:
	// 每个变量的声明处
	int _year = 121;
	// C++11支持给缺省值，这个值是给初始化列表的
	// 如果初始化列表没有显式给值，就用这个缺省值
	// 如果初始化列表给了值，就不用缺省值，而用初始化列表中的值
	// 缺省值就是一个备胎
	int _month;
	int _day;
	const int _haha;
	int& ref;
};