#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <cassert>
using namespace std;

class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}

	int _year;
	int _month;
	int _day;
};

//int main()
//{
//	//Date d1 = { 2023,10,11 };
//	//Date d2{ 2023,10,12 };
//	//Date d3(2023, 11, 11);
//
//	//Date* pDate1 = new Date[3]{ d1,d2,d3 };
//	//Date* pDate2 = new Date[3]{ {2023,3,2},{2024,12,2},{2023,9,9} };
//	//
//	//auto ls = { 2025,1,1 };
//
//	//const Date& d4 = { 2023,8,23 };
//	//cout << d4._day << endl;
//
//	
//	//vector<int> v1 = { 1,2,3,4,5 };
//
//	//// 类型转换(右边的被隐式类型转换成Date类型 赋值给d1) 构造+拷贝构造->优化成直接构造d1
//	//Date d1 = { 2023,10,11 };
//
//	//std::pair<string, string> kv1("joker", "小丑");
//	//map<string, string> dict = { {"hello","你好"},make_pair("sort","排序"),kv1 };
//
//	//for (auto kv : dict)
//	//{
//	//	cout << kv.first << ":" << kv.second << endl;
//	//}
//
//	//array<int, 6> arr = { 1,2,3,4,5 };
//
//
//	// 以下的p、b、c、*p都是左值
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//	// 以下几个是对上面左值的左值引用
//	int*& rp = p;
//	int& rb = b;
//	const int& rc = c;
//	int& pvalue = *p;
//
//
//	return 0;
//}

//int main()
//{
//	double x = 1.1, y = 2.2;
//	// 以下几个都是常见的右值
//	10;
//	x + y;
//	fmin(x, y);
//	// 以下几个都是对右值的右值引用
//	int&& rr1 = 10;
//	cout << rr1 << endl;
//
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//
//	rr1 = 20;
//	cout << rr1 << endl;
//	// 这里编译会报错：error C2106: “=”: 左操作数必须为左值
//	//10 = 1;
//	//x + y = 1;
//	//fmin(x, y) = 1;
//	return 0;
//}

//
//int main()
//{
//	int a = 10;
//	int&& b = std::move(a);  // 告诉编译器可以移动a的资源
//	b = 20;
//	cout << a << " " << b << endl;
//	return 0;
//}

namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			//cout << "string(char* str)" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;
			string tmp(s._str);
			swap(tmp);
		}
		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
			string tmp(s);
			swap(tmp);
			return *this;
		}
		//// 移动构造
		//string(string&& s)
		//	:_str(nullptr)
		//	, _size(0)
		//	, _capacity(0)
		//{
		//	cout << "string(string&& s) -- 移动语义" << endl;
		//	swap(s);
		//}
		//// 移动赋值
		//string& operator=(string&& s)
		//{
		//	cout << "string& operator=(string&& s) -- 移动语义" << endl;
		//	swap(s);
		//	return *this;
		//}
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // 不包含最后做标识的\0
	};
}


namespace bit
{
	bit::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}
		bit::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;
			str += ('0' + x);
		}
		if (flag == false)
		{
			str += '-';
		}
		std::reverse(str.begin(), str.end());
		return str;
	}
}
int main()
{
	// 在bit::string to_string(int value)函数中可以看到，这里
	// 只能使用传值返回，传值返回会导致至少1次拷贝构造(如果是一些旧一点的编译器可能是两次拷贝构造)。
	bit::string ret1 = bit::to_string(1234);
	bit::string ret2 = bit::to_string(-1234);
	return 0;
}