#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

namespace bit
{
	int rand = 0;
}

int main()
{
	printf("hello world!");
	printf("%d", bit::rand);
	return 0;
}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	cout << "hello world" << endl;
//
//	return 0;
//}