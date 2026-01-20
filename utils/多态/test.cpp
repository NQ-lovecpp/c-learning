#include <iostream>
using namespace std;

//class Base1 
//{
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//
//class Base2 
//{
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//	int b2;
//};
//
//class Derive : public Base1, public Base2 
//{
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//
//class Derive2 :public Derive
//{
//public:
//	virtual void func1() { cout << "Derive2::func1" << endl; }
//	virtual void func3() { cout << "Derive2::func3" << endl; }
//private:
//	int d2;
//};
//
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//	cout << " 虚函数表地址(_vfptr) :" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf(" 第%d个虚函数地址 :%x		调用结果:", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int a = 0;
//	static int b = 1;
//	static int c;
//	const char* str = "hello world";
//	int* p = new int[10];
//
//	cout << "---高地址---" << endl;
//	printf("栈：%p\n", &a);
//	printf("堆：%p\n", &p);
//	printf("静态区/数据段(未初始化)：%p\n", &c);
//	printf("数据段(已初始化)：%p\n", &b);
//	printf("常量区：%p\n", str);
//	printf("代码段：%p\n", &PrintVTable);
//	cout << "---低地址---" << endl << endl;
//
//
//
//	Derive d;
//	Derive2 d2;
//
//	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
//	PrintVTable(vTableb1);
//
//	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
//	PrintVTable(vTableb2);
//
//	VFPTR* vTabled2 = (VFPTR*)(*(int*)&d2);
//	PrintVTable(vTabled2);
//
//
//
//	return 0;
//}


//class Parent {
//public:
//    int iparent;
//    Parent() :iparent(10) {}
//    virtual void f() { cout << " Parent::f()" << endl; }
//    virtual void g() { cout << " Parent::g()" << endl; }
//    virtual void h() { cout << " Parent::h()" << endl; }
//
//};
//
//class Child : public Parent {
//public:
//    int ichild;
//    Child() :ichild(100) {}
//    virtual void f() { cout << "Child::f()" << endl; }
//    virtual void g_child() { cout << "Child::g_child()" << endl; }
//    virtual void h_child() { cout << "Child::h_child()" << endl; }
//};
//
//class GrandChild : public Child {
//public:
//    int igrandchild;
//    GrandChild() :igrandchild(1000) {}
//    virtual void f() { cout << "GrandChild::f()" << endl; }
//    virtual void g_child() { cout << "GrandChild::g_child()" << endl; }
//    virtual void h_grandchild() { cout << "GrandChild::h_grandchild()" << endl; }
//};
//
//
//
//typedef void(*Fun)(void);
//
//GrandChild gc;
//
//int** pVtab = (int**)&gc;
//
//int main()
//{
//    cout << "[0] GrandChild::_vptr->" << endl;
//    for (int i = 0; (Fun)pVtab[0][i] != NULL; i++) 
//    {
//        Fun pFun = (Fun)pVtab[0][i];
//        cout << "    [" << i << "] ";
//        pFun();
//    }
//    cout << "[1] Parent.iparent = " << (int)pVtab[1] << endl;
//    cout << "[2] Child.ichild = " << (int)pVtab[2] << endl;
//    cout << "[3] GrandChild.igrandchild = " << (int)pVtab[3] << endl;
//    return 0;
//}




//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//int main()
//{
//	Base b;
//	cout << sizeof(Base) << endl; 
//	// sizeof(Base)是多少？
//	// 答：32位平台下8字节（4字节虚表指针 + 4字节int）
//	//     64位平台下16字节（8字节虚表指针 + 4字节int）
//	//     因为最后要结构体内存对齐，所以是16
//
//	cout << sizeof(int) << endl;  //4Byte
//	return 0;
//}


//class Base 
//{
//public:
//    virtual void someFunction()
//    {
//        cout << typeid(this).name() << endl;
//        cout << "Base::someFunction()" << endl;
//    }
//};
//
//class Derived : public Base 
//{
//public:
//    void someFunction() override
//    {
//        cout <<typeid(this).name() << endl;
//        cout << "Derived::someFunction()" << endl;
//    }
//};
//
//int main()
//{
//    Base b;
//    Derived d;
//    b.someFunction();
//    d.someFunction();
//    return 0;
//}


class A
{
public:
	virtual void func(int val = 1)
	{ 
		std::cout << "A->" << val << std::endl; 
	}

	virtual void test() 
	{ 
		this;
		func(); 
	}
};
class B : public A
{
public:
	void func(int val = 0)
	{
		this;
		std::cout << "B->" << val << std::endl; 
	}
};
int main(int argc, char* argv[])
{
	B* p = new B;
	p->test();
	return 0;
}