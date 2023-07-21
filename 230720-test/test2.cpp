#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
extern class A;
extern class B;

class A
{

};

inline void test()
{
	cout << "test2.cpp" << endl;
	A a;
	B b;
}