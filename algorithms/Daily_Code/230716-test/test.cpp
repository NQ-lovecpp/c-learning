#define _CRT_SECURE_NO_WARNINGS

//#include <stdlib.h>
//#include <stdio.h>
//
//namespace bit
//{
//	int rand = 0;
//
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	}Node;
//}

//全部展开（授权）
//using namespace std;
//部分展开（授权）
//using bit::Add;
//
//int main()
//{
//	//域作用限定符::
//	printf("%d", bit::rand);
//	printf("%d", bit::Add(1, 2));
//	struct bit::Node* haha = NULL;
//	return 0;
//}

//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int i = 0;
//	double j = 0;
//	cin >> i >> j;
//	cout << i << endl << j << endl;
//	cout << &i << endl << &j << endl;
//	return 0;
//}



#include <iostream>
using namespace std;


void func(int a)
{
	cout << "void func(int a)" << endl;
}

void func(int a, int b = 1)
{
	cout << "void func(int a,int b=1)" << endl;
}
int main()
{
	func(1, 2);
	func(1);
	return 0;
}