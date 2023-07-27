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

#include <iostream>
using namespace std;
// 1.下面程序编译运行结果是？ A、编译报错 B、运行崩溃 C、正常运行
class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}
private:
	int _a;
};

int main()
{
	A* p = nullptr;
	p->PrintA();
	return 0;
}