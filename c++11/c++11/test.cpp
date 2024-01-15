#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <cassert>
#include <string>
#include <list>
#include <algorithm>
#include <functional>
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
			cout << "string(char* str)" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
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
		// 移动构造
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- 移动语义" << endl;
			swap(s);
		}
		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动语义" << endl;
			swap(s);
			return *this;
		}
		~string()
		{
			cout << "~string()" << endl;
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

//int main()
//{
//	cout << "------" << endl;
//	bit::string ret1 = bit::to_string(1234);
//	cout << "------" << endl;
//	bit::string ret2 = bit::to_string(-1234);
//	cout << "------" << endl;
//	
//	// ret1 = bit::to_string(2343);
//	return 0;
//}

//int main()
//{
//	//bit::string s1("hello world");
//	//// 这里s1是左值，调用的是拷贝构造
//	//bit::string s2(s1);
//	//// 这里我们把s1 move处理以后, 会被当成右值，调用移动构造
//	//// 但是这里要注意，一般是不要这样用的，因为我们会发现s1的
//	//// 资源被转移给了s3，s1被置空了。(因为移动构造中调用了swap)
//	//bit::string s3(std::move(s1)); 
//	//cout << typeid(move(s1)).name() << endl;
//
//	vector<bit::string> arr;
//	bit::string s1("nihao");
//	arr.push_back("hello world");
//	arr.push_back(move(s1));
//	return 0;
//}


//void Fun(int& x) { cout << "左值引用" << endl; }
//void Fun(const int& x) { cout << "const 左值引用" << endl; }
//void Fun(int&& x) { cout << "右值引用" << endl; }
//void Fun(const int&& x) { cout << "const 右值引用" << endl; }
//
// std::forward<T>(t)在传参的过程中保持了t的原生类型属性。
//template<typename T>
//void PerfectForward(T&& t)
//{
//	Fun(std::forward<T>(t));
//	Fun(t);
//
//}
//int main()
//{
//	PerfectForward(10); // 右值
//	int a;
//	PerfectForward(a); // 左值
//	PerfectForward(std::move(a)); // 右值
//	const int b = 8;
//	PerfectForward(b); // const 左值
//	PerfectForward(std::move(b)); // const 右值
//	return 0;
//}

//int main()
//{
//	list<bit::string> lt;
//
//	bit::string s1("hello world");
//	lt.push_back(s1);
//
//	lt.push_back(bit::to_string(12334));
//
//	return 0;
//}

//void Fun(int& x) { cout << "左值引用" << endl; }
//void Fun(const int& x) { cout << "const 左值引用" << endl; }
//void Fun(int&& x) { cout << "右值引用" << endl; }
//void Fun(const int&& x) { cout << "const 右值引用" << endl; }
//// std::forward<T>(t)在传参的过程中保持了t的原生类型属性。
//
//template<typename T>
//void PerfectForward(T&& t)
//{
//	Fun(std::forward<T>(t));
//	// Fun(t);
//}
//
//int main()
//{
//	PerfectForward(10); // 右值
//	int a;
//	PerfectForward(a); // 左值
//	PerfectForward(std::move(a)); // 右值
//	const int b = 8;
//	PerfectForward(b); // const 左值
//	PerfectForward(std::move(b)); // const 右值
//	return 0;
//}

// 以下代码在vs2013中不能体现，在vs2019下才能演示体现上面的特性。
//class Person
//{
//public:
//	Person(const char* name = "", int age = 0)
//		:_name(name)
//		, _age(age)
//	{}
//
//	Person(const Person& p)
//		:_name(p._name)
//		,_age(p._age)
//	{}
//
//	Person& operator=(const Person& p)
//	{
//		if(this != &p)
//		{
//			_name = p._name;
//			_age = p._age;
//		}
//		return *this;
//	}
//
//	// 不让生成实现
//	//Person(Person&& p) = delete;
//
//	// 强制编译器生成
//	Person(Person&& p) = default;
//	// Person(const Person& p) = default;
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//private:
//	bit::string _name;
//	int _age;
//};
//
//int main()
//{
//	Person s1;
//	Person s2 = s1;			   // 默认的拷贝构造
//	Person s3 = std::move(s1); // 默认的移动构造
//
//	//Person s4;
//	//s4 = std::move(s2);
//
//	return 0;
//}
//
//template<class ...Args>
//void ShowList(Args... args)
//{
//	cout << sizeof...(args) << endl;
//}
//
//
//int main()
//{
//	ShowList(1, 2, 3, 4);
//	ShowList(1, 2, 3);
//	ShowList(1, 2);
//	ShowList(1);
//
//}

//struct Goods
//{
//	string _name; // 名字
//	double _price; // 价格
//	int _evaluate; // 评价
//	Goods(const char* str, double price, int evaluate)
//		:_name(str)
//		, _price(price)
//		, _evaluate(evaluate)
//	{}
//};
//
//int main()
//{
//	auto f1 = [](int x)->int {cout << x << endl;return 0;};
//	f1(1);
//	
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2,3 }, { "菠萝", 1.5, 4 } };
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._price < g2._price;});
//	//sort(v.begin(), v.end(), greater<Goods>());
//
//	return 0;
//}


//#include <cstdarg>
//#include <iostream>
//
//// 这个函数计算可变数量参数的平均值
//double average(int count, ...) 
//{
//	// va_list是一个指向参数列表的类型
//	va_list args;
//	// va_start宏初始化args，使其指向参数列表的起始位置
//	va_start(args, count);
//
//	// sum用于累加参数的值
//	double sum = 0;
//	// 通过va_arg宏遍历参数列表，将每个参数的值加到sum上
//	for (int i = 0; i < count; ++i)
//	{
//		sum += va_arg(args, double);
//	}
//
//	// va_end宏清理args，结束对参数列表的访问
//	va_end(args);
//	
//	// 返回参数的平均值
//	return sum / count;
//}
//
//int main() 
//{
//	// 在main函数中调用average函数，传递3个参数（包括一个整数和两个浮点数）
//	std::cout << "Average: " << average(3, 2.0, 4.0, 6.0) << std::endl;
//
//	return 0;
//}


//#include <iostream>
//
//// 可变模板参数列表
//template <typename T>
//T sum(T value) 
//{
//	return value;
//}
//
//template <typename T, typename... Args>
//T sum(T first, Args... args) 
//{
//	return first + sum(args...);
//}
//
//int main() 
//{
//	std::cout << "Sum: " << sum(1, 2, 3, 4, 5) << std::endl;
//
//	return 0;
//}

//int main()
//{
//	// 最简单的lambda表达式, 该lambda表达式没有任何意义
//	auto lambda1 = [] {};
//
//	cout << typeid(lambda1).name() << endl;
//
//	// 省略参数列表和返回值类型，返回值类型由编译器推导为int
//	int a = 3, b = 4;
//	[=] {return a + 3; };
//
//	// 省略了返回值类型，无返回值类型
//	auto fun1 = [&](int c) {b = a + c; };
//	fun1(10);
//	cout << a << " " << b << endl;
//
//	// 各部分都很完善的lambda函数
//	auto fun2 = [=, &b](int c)->int {return b += a + c; };
//	cout << fun2(10) << endl;
//
//	// 复制捕捉x
//	int x = 10;
//	auto add_x = [x](int a) mutable { x *= 2; return a + x; };
//	cout << add_x(10) << endl;
//
//	return 0;
//}



//std::function<int(int, int)> createLambda() {
//	int capturedValue = 10;
//
//	// 返回一个 lambda 表达式，其中捕获了局部变量 capturedValue
//	return [capturedValue](int x, int y) {
//		return x + y + capturedValue;
//	};
//}
//
//int main() {
//	// 获取包装了 lambda 表达式的 std::function
//	std::function<int(int, int)> func = createLambda();
//
//	// 此时 createLambda 中的局部变量 capturedValue 已经超出作用域
//	// 访问 capturedValue 将导致未定义行为
//	// 由于 std::function 存储了 lambda 表达式的副本，因此此时 func 也无效
//	// 尝试调用 func 将导致未定义行为
//	std::cout << func(2, 3) << std::endl;
//
//	return 0;
//}


#include <iostream>
#include <functional>

std::function<int(int, int)> createLambda() {
	int capturedValue = 10;

	// 返回一个 lambda 表达式，其中捕获了局部变量 capturedValue
	return [capturedValue](int x, int y) {
		return x + y + capturedValue;
	};
}

int main() {
	// 获取包装了 lambda 表达式的 std::function
	std::function<int(int, int)> func1 = createLambda();
	std::function<int(int, int)> func2 = createLambda();

	// 输出 func1 和 func2 的地址
	std::cout << "Address of func1: " << &func1 << std::endl;
	std::cout << "Address of func2: " << &func2 << std::endl;

	return 0;
}
