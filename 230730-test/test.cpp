//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//
//	Date(int year, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//		
//	}
//
//	Date(const Date& d1)
//	{
//		_year = d1._year;
//		_month = d1._month;
//		_day = d1._day;
//	}
//
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1(2022);         // 使用单参数构造函数创建 d1 对象
//	Date d2 = 2023;        // 使用2023从int到Date的隐式转换创建 d2 对象，如果构造函数有explicit关键字，这行代码运行不通过。
//	d2 = 2024;
//	Date d3 = Date(2024);  // 显式地使用单参数构造函数创建临时对象，并使用拷贝构造函数初始化 d3，年份设置为 2024
//	Date(2025);           // 创建一个临时 Date 对象，年份设置为 2025。对象立即析构，所以其生命周期只有一行
//	Date d4 = { 2026,2,2 }; // 使用一个列表初始化，创建 d4 对象，如果构造函数有explicit关键字，这行代码运行不通过。
//	Date d5 = Date(2027, 3, 3); // 显式地使用三参数构造函数创建临时对象，并使用拷贝构造函数初始化 d5
//	Date(2028, 4, 4);      // 创建一个临时 Date 对象，对象立即析构，其生命周期只有一行
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d << endl;
//	return 0;
//}

class Time
{
	//friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{

	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{

	}
	void SetTimeOfDate(int hour, int minute, int second)
	{
		// 直接访问时间类私有的成员变量
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};