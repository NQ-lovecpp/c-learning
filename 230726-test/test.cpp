//

//
//// 类中既有成员变量，又有成员函数
//class A1 
//{
//public:
//	void f1() {}
//private:
//	int _a;
//};
//
//// 类中仅有成员函数
//class A2 
//{
//public:
//	void f2() {}
//};
//
//// 类中什么都没有---空类
//class A3
//{
//
//};
//
//int main()
//{
//	A1 a1;
//	A2 a2;
//	A3 a3;
//
//	cout << sizeof(A1) << " " << sizeof(a1) << endl; //输出：4 4
//	cout << sizeof(A2) << " " << sizeof(a2) << endl; //输出：1 1
//	cout << sizeof(A3) << " " << sizeof(a3) << endl; //输出：1 1
//	return 0;
//}

//#include <iostream>
//using namespace std;
//// 1.下面程序编译运行结果是？ A、编译报错 B、运行崩溃 C、正常运行
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->PrintA();
//	return 0;
//}


//#include <array>
//#include <iostream>
//typedef std::array<int, 4> Myarray;
//int main()
//{
//	Myarray c0 = { 0, 1, 2, 3 };
//	// display contents " 0 1 2 3"
//	for (const auto& it : c0)
//	{
//		std::cout << " " << it;
//	}
//	std::cout << std::endl;
//	Myarray c1(c0);
//	// display contents " 0 1 2 3"
//	for (const auto& it : c1)
//	{
//		std::cout << " " << it;
//	}
//	std::cout << std::endl;
//	return (0);
//}
//
//class Date
//{
//public:
//	Date()
//	{
//		_year = 1900;
//		_month = 1;
//		_day = 1;
//	}
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// 以下测试函数能通过编译吗？
//void Test()
//{
//	Date d1;
//}

#include <iostream>
using namespace std;

class A1
{
public:
	A1()
	{
		cout << "A1()" << endl;
	}
	~A1()
	{
		cout << "~A1()" << endl;
	}
};

class A2
{
public:
	A2()
	{
		cout << "A2()" << endl;
	}
	~A2()
	{
		cout << "~A2()" << endl;
	}
};

class A3
{
public:
	A3()
	{
		cout << "A3()" << endl;
	}
	~A3()
	{
		cout << "~A3()" << endl;
	}
};

class B1
{
public:
	B1()
	{
		cout << "B1()" << endl;
	}
	~B1()
	{
		cout << "~B1()" << endl;
	}
};

class B2
{
public:
	B2()
	{
		cout << "B2()" << endl;
	}
	~B2()
	{
		cout << "~B2()" << endl;
	}
};

class B3
{
public:
	B3()
	{
		cout << "B3()" << endl;
	}
	~B3()
	{
		cout << "~B3()" << endl;
	}
};

class C1
{
public:
	C1()
	{
		cout << "C1()" << endl;
	}
	~C1()
	{
		cout << "~C1()" << endl;
	}
};

class C2
{
public:
	C2()
	{
		cout << "C2()" << endl;
	}
	~C2()
	{
		cout << "~C2()" << endl;
	}
};

class C3
{
public:
	C3()
	{
		cout << "C3()" << endl;
	}
	~C3()
	{
		cout << "~C3()" << endl;
	}
};

class D1
{
public:
	D1()
	{
		cout << "D1()" << endl;
	}
	~D1()
	{
		cout << "~D1()" << endl;
	}
};

class D2
{
public:
	D2()
	{
		cout << "D2()" << endl;
	}
	~D2()
	{
		cout << "~D2()" << endl;
	}
};

class D3
{
public:
	D3()
	{
		cout << "D3()" << endl;
	}
	~D3()
	{
		cout << "~D3()" << endl;
	}
};



static D1 d1;
static D2 d2;
static D3 d3;

C1 c1;
C2 c2;
C3 c3;

int main()
{
	A1 a1;
	A2 a2;
	A3 a3;
	static B1 b1;
	static B2 b2;
	static B3 b3;
	return 0;
}



//class D
//{
//public:
//	D()
//	{
//		cout << "D()" << endl;
//	}
//	~D()
//	{
//		cout << "~D()" << endl;
//	}
//};