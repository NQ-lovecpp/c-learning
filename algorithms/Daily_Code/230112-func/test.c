#define _CRT_SECURE_NO_WARNINGS
////int get_max(int x, int y)
////{
////	if (x > y)
////		return x;
////	else
////		return y;
////}
//#include <stdio.h>
////void Swap(int* pa,int* pb)
////{
////	int tmp = *pa;
////	*pa = *pb;
////	*pb = tmp;
////}
////int main()
////{
////	int a = 0;
////	int b = 0;
////	scanf("%d %d", &a, &b);
////	printf("交换前：%d %d", a, b);
////	Swap(&a, &b);
////	printf("交换后：%d %d", a, b);
////	return 0;
////
////}
////#include <math.h>
////int is_prime(int i)
////{
////	int j = 0;
////	for (j = 2;j < sqrt(i);j++)
////	{
////		if (i % j == 0)
////			return 0;
////	}
////	return 1;
////}
////
////int main()
////{
////	int i = 0;
////	int count = 0;
////	for (i = 100;i <= 200;i++)
////	{
////		if (i == is_prime(i))
////		{
////			count++;
////			printf("%d", i);
////		}
////	}
////	printf("%d", count);
////	return 0;
//////}
////
//#include <stdio.h>
//is_leap_year(int y)
//{
//	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	int y = 0;
//	for (y = 1000; y <= 2000; y++)
//	{
//
//		if (is_leap_year(y))
//		{
//			printf("%d ", y);
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[10] = { 1.2,3,4,5,6,7,8,9,10 };
//	int k = 0;
//	scanf("%d", &k);
//
//}
//#include <stdio.h>
//
//void formula(int a)
//{
//	int i,m;
//	for (i = 1; i <= a; i++)
//	{
//		for (m = 1;m <= a; m++)
//		{
//			printf("i*m=%d", i * m);
//		}
//	}
//}
//int main()
//{
//	int h = 0;
//	printf("几阶乘法口诀表？");
//	scanf("%d", h);
//	formula(h);
//}
#include <stdio.h>
int prime(int a)
{
	int i = 2;
	for (i = 2; i < a; i++)
	{
		if (a % i != 0)
			continue;
		else
			break;
	}
	if (i == a)
		return 1;
	else
		return 0;
}

int main()
{
	int m;
0;	for (m = 100;m <= 200;m++)
	{
		if (prime(m)==1)
			printf("%d	", m);
	}
}