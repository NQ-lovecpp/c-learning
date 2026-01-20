#include <iostream>
using namespace std;
//
//class Base1 { public: int _b1; };
//class Base2 { public: int _b2; };
//class Derive : public Base2, public Base1
//{
//public: 
//	int _d;
//
//	static virtual void func()
//	{
//
//	}
//};
//
//
//
//int main() 
//{
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//
//	cout << (void*)p1 << endl;
//	cout << (void*)p2 << endl;
//	cout << (void*)p3 << endl;
//
//	return 0;
//
//}

//
//class A 
//{
//public:
//	void test(float a) 
//	{ 
//		cout << a; 
//	} 
//};
//
//class B :public A 
//{ 
//public: 
//	void test(int b) 
//	{ 
//		cout << b; 
//	} 
//}; 
//
//void main() 
//{ 
//	A* a = new A;
//	B* b = new B;
//	a = b;
//	b->A::test(1.1); 
//}

class Person
{
public:
	int _name; // 姓名
};

class Student : virtual public Person
{
public:
	int _num; //学号
};

class Teacher :virtual public Person
{
public:
	int _id; // 职工编号
};

class Assistant : public Student, public Teacher
{
public:
	int _majorCourse; // 主修课程
};
void Test()
{
	Assistant a;

	a.Student::_name = 1;
	a.Student::_num = 2;
	a.Teacher::_name = 3;
	a.Teacher::_id = 4;
	a._majorCourse = 5;
}

int main()
{
	Test();
	return 0;
}