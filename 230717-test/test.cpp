#define _CRT_SECURE_NO_WARNINGS

//#include <iostream>
//using namespace std;
//
//void func(int i, double d)
//{
//	cout << "void func(int i, double d)" << endl;
//}
//
//void func(double i, int d)
//{
//	cout << "void func(double i, int d)" << endl;
//}
//
//int main()
//{
//	int a = 0;
//	int& b = a;
//	printf("%p\n%p\n", &a, &b);
//	func(1, 1.1);
//	func(1.1, 1);
//	return 0;
//}
//#include <iostream>
//using namespace std;

//int& Count()
//{
//	int n = 0;
//	n++;
//
//	return n;
//}
//
//int main()
//{
//	int& ret = Count();
//	int& ret2 = Count();
//	cout << ret << endl << ret2 << endl;
//
//	return 0;
//}

#include <iostream>
#include <assert.h>
#define N 10
using namespace std;

struct SeqList
{
	//成员函数
	int& at(int i)
	{
		assert(i < size);
		return a[i];
	}

	//成员变量
	int a[10];
	int size;
};

int main()
{
	SeqList s2;

	for (size_t i = 0;i < N;i++)
	{
		s2.at(i) = i;
	}

	for (size_t i = 0;i < N;i++)
	{
		cout<<s2[i]<<" "
	}
	return 0;
}