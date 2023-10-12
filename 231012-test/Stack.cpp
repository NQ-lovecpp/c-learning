#include "Stack.h"

template<class T>
T Add(const T& left, const T& right)
{
	cout << "T Add(const T& left, const T& right)" << endl;
	return left + right;
}

void func()
{
	cout << "void func()" << endl;
}

template
int Add<int>(const int& left, const int& right);