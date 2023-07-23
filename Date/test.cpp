#include <iostream>
using namespace std;

class Date
{
public:
	// 打印日期
	void Print()
	{
		cout << _year << '/' << _month << '/' << _day << endl;
	}

	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		int Leap[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
		int NLeap[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		
		if (month == 0)
		{
			return 0;
		}
		else if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return Leap[month-1];
		}
		else
		{
			return NLeap[month-1];
		}
	}

	// 获取某年的天数
	int GetYearDay(int year)
	{
		if (year == 0)
		{
			return 0;
		}
		else if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 366;
		}
		else
		{
			return 365;
		}
	}
	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// 拷贝构造函数
	// d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// 赋值运算符重载
	// d2 = d3 即 d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

	// 析构函数
	~Date()
	{
		_year = _month = _day = 0;
	}

	// 日期+=天数
	Date& operator+=(int day)
	{
		(*this) = (*this) + day;
		return (*this);
	}

	// 日期+天数
	Date operator+(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			if (_month == 12)
			{
				_year++;
			}
			_day -= GetMonthDay(_year, _month);
			_month = 1 + (_month % 12);
		}
		return *this;
	}

	// 日期-天数
	Date operator-(int day)
	{
		_day -= day;
		while (_day <= 0)
		{
			_day += GetMonthDay(_year, 1 + ((_month+10) % 12));
			if (_month == 1)
			{
				_year--;
			}
			_month = 1 + ((_month + 10) % 12);
		}
		return *this;
	}

	// 日期-=天数
	Date& operator-=(int day)
	{
		*this = (*this) - day;
		return *this;
	}

	// 前置++
	Date& operator++()
	{
		*this = *this + 1;
		return *this;
	}

	// 后置++
	Date operator++(int)
	{
		Date ret = *this;
		*this = *this + 1;
		return ret;
	}

	// 后置--
	Date operator--(int)
	{
		Date ret = *this;
		*this = *this - 1;
		return ret;
	}

	// 前置--
	Date& operator--()
	{
		*this = *this - 1;
		return *this;
	}

	// >运算符重载
	bool operator>(const Date& d)
	{
		
	}

	// ==运算符重载
	bool operator==(const Date& d)
	{

	}

	// >=运算符重载
	bool operator >= (const Date& d)
	{

	}

	// <运算符重载
	bool operator < (const Date& d)
	{

	}

	// <=运算符重载
	bool operator <= (const Date& d)
	{

	}

	// !=运算符重载
	bool operator != (const Date& d)
	{

	}

	// 日期-日期 返回天数
	int operator-(const Date& d)
	{
		int i = 0;
		//int retyear = _year - d._year;
		//int retmonth = _month - d._month;
		//int retday = _day - d._day;
		//while (_year != 0)
		//{
		//	if (_year > 0)
		//	{

		//	}
		//}
		long long dayt = _day;
		for (i = _year;i > 0;i--)
		{
			dayt += GetYearDay(i - 1);
		}
		for (i = _month;i > 0;i--)
		{
			dayt += GetMonthDay(_year, _month - 1);
		}

		long long dayd = d._day;
		for (i = d._year;i > 0;i--)
		{
			dayd += GetYearDay(i - 1);
		}
		for (i = d._month;i > 0;i--)
		{
			dayd += GetMonthDay(d._year, d._month - 1);
		}

		return (int)(dayt - dayd);
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2021, 3, 1);
	Date d2 = (2021, 3, 2);
	d1 = d1 - 1;
	d1.Print();
	//d1 = d1 + 759;
	//d1.Print();
	cout << d1 - d2 << endl;
	return 0;
}