#include <iostream>
using namespace std;
//
//class Base
//{
//public:
//	virtual void func1()
//	{
//		cout << "Base::func1()" << endl;
//	}
//	virtual void func2()
//	{
//		cout << "Base::func2()" << endl;
//	}
//
//private:
//};
//
//// 打印虚表
//typedef void (*VFUNC)();
//void PrintVFT(VFUNC a[])
//{
//	for (size_t i = 0;a[i] != 0;i++)
//	{
//		printf("[%d]:%p -> ", i, a[i]);
//		VFUNC f = a[i];
//		f();
//	}
//	printf("\n");
//}
//
//int main()
//{
//	Base b;
//	PrintVFT((VFUNC*)(*((int*)&b)));
//	return 0;
//}

//int main()
//{
//	Base B1;
//	Base B2;
//
//	static int a = 0;
//	int b = 0;
//	int* p1 = new int;
//	const char* p2 = "hello world";
//	printf("静态区域：%p\n", &a);
//	printf("栈：%p\n", &b);
//	printf("堆：%p\n", &p1);
//	printf("代码段：%p\n", &p2);
//	printf("虚表：%p\n", *((int*)&B1));
//	printf("虚函数地址：%p\n", &Base::func2);
//
//	return 0;
//}

//class Person 
//{
//public:
//	virtual void BuyTicket() 
//	{
//		cout << "买票-全价" << endl; 
//	}
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person 
//{
//public:
//	virtual void BuyTicket() 
//	{ 
//		cout << "买票-半价" << endl; 
//	}
//	virtual ~Student() { cout << "~Student()" << endl; }
//
//};
//
//class Chushen: public Student 
//{
//public:
//	virtual void BuyTicket() 
//	{
//		cout << "买票-免费" << endl;
//	}
//	virtual ~Chushen() { cout << "~Chushen()" << endl; }
//
//};
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	//Person ps;
//	//Student st;
//	//Chushen cs;
//	//Func(ps);
//	//Func(st);
//	//Func(cs);
//
//	Person* pp = new Person;
//	Person* ps = new Student;
//	Person* pc = new Chushen;
//
//	delete pp;
//	delete ps;
//	delete pc;
//	return 0;
//}
//

//
//// 针对上面的代码我们做出以下改造
//// 1.我们增加一个派生类Derive去继承Base
//// 2.Derive中重写Func1
//// 3.Base再增加一个虚函数Func2和一个普通函数Func3
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//
//// 打印虚表
//typedef void (*VFUNC)();
//void PrintVFT(VFUNC a[])
//{
//	for (size_t i = 0;a[i] != 0;i++)
//	{
//		printf("[%d]:%p -> ", i, a[i]);
//		VFUNC f = a[i];
//		f();
//	}
//	printf("\n");
//}
//
//int main()
//{
//	Base b;
//	Derive d;
//
//	PrintVFT((VFUNC*)(*((int*)&b)));
//	PrintVFT((VFUNC*)(*((int*)&d)));
//
//	return 0;
//}

//
//class Car
//{
//public:
//	virtual void Drive() {}
//};
//class Benz : public Car  
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};


class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};

class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};

// 打印虚表
typedef void (*VFUNC)();
void PrintVFT(VFUNC a[])
{
	for (size_t i = 0;a[i] != 0;i++)
	{
		printf("[%d]:%p -> ", i, a[i]);
		VFUNC f = a[i];
		f();
	}
	printf("\n");
}

int main()
{
	Base b;
	Derive d;

	Base& refb = d;
	refb.Func2();

	//PrintVFT((VFUNC*)(*((int*)&b)));
	//PrintVFT((VFUNC*)(*((int*)&d)));

	return 0;
}