#include "Date.h"

// 打印日期
void Date::Print() const
{
	cout << _year << '/' << _month << '/' << _day << endl;
}

// 获取某年某月的天数
int Date::GetMonthDay(int year, int month)
{
	int Leap[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int NLeap[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	if (month == 0)
	{
		return 0;
	}
	else if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
	{
		return Leap[month - 1];
	}
	else
	{
		return NLeap[month - 1];
	}
}

// 获取某年的天数
int Date::GetYearDay(int year)
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
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

// 拷贝构造函数
// d2(d1)
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

// 赋值运算符重载
// d2 = d3 即 d2.operator=(&d2, d3)
Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

// 析构函数
Date::~Date()
{
	_year = _month = _day = 0;
}

// 日期+=天数
Date& Date::operator+=(int day)
{
	(*this) = (*this) + day;
	return (*this);
}

// 日期+天数
Date Date::operator+(int day)
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
Date Date::operator-(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		_day += GetMonthDay(_year, 1 + ((_month + 10) % 12));
		if (_month == 1)
		{
			_year--;
		}
		_month = 1 + ((_month + 10) % 12);
	}
	return *this;
}

// 日期-=天数
Date& Date::operator-=(int day)
{
	*this = (*this) - day;
	return *this;
}

// 前置++
Date& Date::operator++()
{
	*this = *this + 1;
	return *this;
}

// 后置++
Date Date::operator++(int)
{
	Date ret = *this;
	*this = *this + 1;
	return ret;
}

// 后置--
Date Date::operator--(int)
{
	Date ret = *this;
	*this = *this - 1;
	return ret;
}

// 前置--
Date& Date::operator--()
{
	*this = *this - 1;
	return *this;
}

// >运算符重载
bool Date::operator>(const Date& d)
{
	if ((*this - d) > 0)
		return true;
	else
		return false;
}

// ==运算符重载
bool Date::operator==(const Date& d)
{
	if ((*this - d) == 0)
		return true;
	else
		return false;
}

// >=运算符重载
bool Date::operator >= (const Date& d)
{
	if ((*this - d) >= 0)
		return true;
	else
		return false;
}

// <运算符重载
bool Date::operator < (const Date& d)
{
	if ((*this - d) < 0)
		return true;
	else
		return false;
}

// <=运算符重载
bool Date::operator <= (const Date& d)
{
	if ((*this - d) <= 0)
		return true;
	else
		return false;
}

// !=运算符重载
bool Date::operator != (const Date& d)
{
	if ((*this - d) != 0)
		return true;
	else
		return false;
}

// 日期-日期 返回天数
int Date::operator-(const Date& d)
{


	// 计算起始日期之前的天数
	long long days1 = _year * 365 + _day;
	for (int i = 1; i < _month; ++i)
	{
		days1 += GetMonthDay(_year, i);

	}

	// 计算结束日期之前的天数
	long long days2 = d._year * 365 + d._day;
	for (int i = 1; i < d._month; ++i)
	{
		days2 += GetMonthDay(d._year, i);
	}

	return (int)(days1 - days2 + 1);
}



