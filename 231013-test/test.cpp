//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//
//	void Print()
//	{
//		cout << "name:" << _person_name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _person_name = "person"; // 姓名
//	int _age = 18;  // 年龄
//};
//
//
//class Student : public Person
//{
//public:
//	int* func()
//	{
//		cout << _stuid << endl;
//		return &_stuid;
//	}
//protected:
//	int _stuid = 123; // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid = 456; // 工号
//};
//
//int main()
//{
//	Student s;
//
//	Person p1 = s;
//	Person* pp1 = &s;
//	Person& refp1 = s;
//	int* ret=((Student*)pp1)->func();
//	cout << *ret << endl;
//
//	return 0;
//}
//
#include <iostream>
#include <string>
using namespace std;
//
//class Person
//{
//public:
//	Person()
//		:_name("person name")
//		, _sex("person sex")
//		, _age(18)
//	{}
//protected:
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//private:
//	int haha = 0;
//};
//
//class Student : public Person
//{
//public:
//	int _No = 123; // 学号
//};
//
//
//
//int main()
//{
//	Student sobj;
//	Person p;
//
//	// 1.子类对象可以赋值给父类对象/指针/引用
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//
//	
//	//2.基类对象不能赋值给派生类对象
//	//sobj = pobj;
//
//	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
//	pp = &sobj;
//	Student* ps1 = (Student*)pp; // 这种情况转换时可以的。
//	ps1->_No = 10;
//	pp = &pobj;
//	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
//	ps2->_No = 10;
//	return 0;
//}

// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//void Test()
//{
//	Student s1;
//	s1.Print();
//};
//
//int main()
//{
//	Test();
//	return 0;
//}
//
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}

//class Person
//{
//public:
//	string _name; // 姓名
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//void Test()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	a._name = "peter";
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//	cout << &(a.Student::_name) << endl;
//	cout << &(a.Teacher::_name) << endl;
//
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//class A
//{
//public:
//	int _a;
//};
//// class B : public A
//class B : virtual public A
//{
//public:
//	int _b;
//};
//// class C : public A
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	return 0;
//}


//#include<iostream>
//
//using namespace std;
//class A
//{
//public:
//	A(const char* s) { cout << s << endl; }
//	~A() {}
//};
//class B :public A
//{
//public:
//	B(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//class C :public A
//{
//public:
//	C(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//class D :public C, public B
//{
//public:
//	D(const char* s1, const char* s2, const char* s3, const char* s4)
//		:B(s1, s2)
//		,C(s1, s3)
//	{
//		cout << s4 << endl;
//	}
//};
//int main() {
//	D* p = new D("class A", "class B", "class C", "class D");
//	delete p;
//	return 0;
//} 


class Person
{
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
};
class Student : public Person 
{
public:
	virtual void BuyTicket() { cout << "买票-半价" << endl; }
};
void Func(Person& p)
{
	p.BuyTicket();
}

int main()
{
	Person ps;
	Student st;
	Func(ps);
	Func(st);
	return 0;
}