#include <iostream>
using namespace std;

//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person()" << endl;
//
//	}
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	Student()
//	{
//		cout << "Student()" << endl;
//	}
//	virtual ~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};
//
//int main()
//{
//	Person* ptr = new Person;
//	delete ptr;
//
//	ptr = new Student;
//	delete ptr;
//
//	return 0;
//}

	// p调用是正常调用，因为B作为派生类没有重写test，只能调用A的test，把B*类型的this指针
	// 强制转化为了A*类型的this指针（切片）
//class A
//{
//public:
//	virtual void func(int val = 1) 
//	{ 
//		std::cout << "A->" << val << std::endl;
//	}
//	virtual void test()
//	{
//		this->func();
//	}
//};
//class B : public A
//{
//public:
//	void func(int val = 0) 
//	{ 
//		std::cout << "B->" << val << std::endl; 
//	}
//};
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//
//	p->test();
//	return 0;
//}

class car
{
public:
	virtual void Drive() = 0;
};

int main()
{

}