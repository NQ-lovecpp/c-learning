//class base
//{
//private:
//	int a;
//};
//
//class dirived :private base
//{
//private:
//	int a;
//};

#include <iostream>
using namespace std;
//class A
//{
//public:
//	void f() { cout << "A::f()" << endl; }
//	int a;
//};
//
//class B : public A
//{
//public:
//	void f(int a) { cout << "B::f()" << endl; }
//	int a;
//};
//
//
//
//int main()
//{
//	B b;
//	b.f();
//	return 0;
//}



class A
{

public:

	A() { cout << "A::A()" << endl; }

	~A() { cout << "A::~A()" << endl; }

	int a;

};



class B : public A

{

public:

	B() { cout << "B::B()" << endl; }

	~B() { cout << "B::~B()" << endl; }

	int b;

};



void f()

{

	B b;

}

int main()
{
	f();
	return 0;
}