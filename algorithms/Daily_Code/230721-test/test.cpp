#define _CRT_SECURE_NO_WARNINGS

//#include <iostream>
//using namespace std;
//
//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//};
//class Date
//{
//public:
//	bool operator==(const Date& d)
//	{
//		return operator<=
//	}
//	Date(int year = 1, int month = 1,int day=1)
//	{
//		cout << "Date()" << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	~Date()
//	{
//		cout << "~Date()" << endl;
//		_month = _year = _day = 0;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	Date d2(2022, 7, 21);
//	return 0;
//}

#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// Date(Date d) 错误写法：编译报错，会引发无穷递归
//	Date(const Date& d) 
//	{
//		cout << "拷贝构造函数被调用" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void haha(Date& dx)
//{
//	;
//}
//int main()
//{
//	Date d1;
//	Date d2(d1);
//	haha(d1);
//	return 0;
//}


//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	Stack s2(s1);
//	return 0;
//}


class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void DatePrint()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
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

	Date& operator++()
	{
		_day += 1;
		return *this;
	}

	Date operator++(int)
	{
		Date tmp(*this);
		_day += 1;
		return tmp;
	}
private:
	int _year;
	int _month;
	int _day;
};



int main()
{
	Date d1(1900,1,1);
	Date d2(2000,2,2);
	cout << "before" << endl;
	d1.DatePrint();
	d2.DatePrint();
	cout << "after" << endl;
	d1 = d2;
	d1.DatePrint();
	d2.DatePrint();
	cout << "test" << endl;
	++d1;
	++d1;
	d1++;
	d1++;
	d1.DatePrint();
	return 0;
}