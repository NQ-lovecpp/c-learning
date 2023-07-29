//#include <iostream>
//#include <stdlib.h>
//typedef int DataType;
//class Stack
//{
//public:
//	void Init()
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * 3);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//		_capacity = 3;
//		_size = 0;
//	}
//	void Push(DataType data)
//	{
//		CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	void Pop()
//	{
//		if (Empty())
//			return;
//		_size--;
//	}
//
//	DataType Top() { return _array[_size - 1]; }
//
//	int Empty() { return 0 == _size; }
//
//	int Size() { return _size; }
//
//	void Destroy()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	void CheckCapacity()
//	{
//		if (_size == _capacity)
//		{
//			int newcapacity = _capacity * 2;
//			DataType* temp = (DataType*)realloc(_array, newcapacity *
//				sizeof(DataType));
//			if (temp == NULL)
//			{
//				perror("realloc申请空间失败!!!");
//				return;
//			}
//			_array = temp;
//			_capacity = newcapacity;
//		}
//	}
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//
//
//class Date
//{
//public:
//	// 初始化列表是每个成员定义的地方 对自定义类型会调用它的默认构造函数 内置类型没给初始值就赋予随机值
//	// 不管写不写，每个成员都要走初始化列表
//	Date(int year, int month, int day, int& i)
//		: _year(year)//每个变量的定义处
//		, _month(month)
//		, _day(day)
//		, _haha(1)
//		, ref(i)
//
//	{}
//private:
//	// 每个变量的声明处
//	int _year = 121;
//	// C++11支持给缺省值，这个值是给初始化列表的
//	// 如果初始化列表没有显式给值，就用这个缺省值
//	// 如果初始化列表给了值，就不用缺省值，而用初始化列表中的值
//	// 缺省值就是一个备胎
//	int _month;
//	int _day;
//	const int _haha;
//	int& ref;
//
//};
//
//
//
//
//
//
//int main()
//{
//	Stack s;
//	s.Init();
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//	printf("%d\n", s.Top());
//	printf("%d\n", s.Size());
//	s.Pop();
//	s.Pop();
//	printf("%d\n", s.Top());
//	printf("%d\n", s.Size());
//	s.Destroy();
//	return 0;
//}


//
//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//class A
//{
//public:
//	A(int i)
//		:_a(i)
//	{
//		cout << "A(int i)" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	B(int i,int j)
//		:_b(i)
//	{
//		cout << "B(int i,int j)" << endl;
//	}
//private:
//	int _b;
//};
//
//int main()
//{
//	A aa1(1);
//
//	//单参数的构造函数支持隐式类型转换
//	A aa2 = 2;
//	const A& ref = 2;
//
//	//单参数的构造函数支持隐式类型转换
//	B bb2 = { 1,2 };
//	const B& bb2 = { 1,2 };
//
//	// 有名对象
//	A aa6(6);
//
//	// 匿名对象 声明周期只在这一行
//	A(7);
//
//
//
//	double d = 1.1;
//	int i = d;
//	int& ir = d;
//	//
//	const int& ir2 = d;
//	return 0;
//}

#include <iostream>
#include <stdlib.h>
using namespace std;

class Date
{
public:
	// 1. 单参构造函数，没有使用explicit修饰，具有类型转换作用
// explicit修饰构造函数，禁止类型转换---explicit去掉之后，代码可以通过编译
	//Date(int year)
	//	:_year(year)
	//{}

	// 2. 虽然有多个参数，但是创建对象时后两个参数可以不传递，没有使用explicit修饰，具有类型转换作用
	// explicit修饰构造函数，禁止类型转换
	Date(int year, int month = 1, int day = 1)
	: _year(year)
	, _month(month)
	, _day(day)
	{}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};
void Test()
{
	Date d1(2022);
	// 用一个整形变量给日期类型对象赋值
	// 实际编译器背后会用2023构造一个无名对象，最后用无名对象给d1对象进行赋值
	d1 = { 2023 ,2,3 };
	// 将1屏蔽掉，2放开时则编译失败，因为explicit修饰构造函数，禁止了单参构造函数类型转换的作用
}

int main()
{
	Test();
	return 0;
}