#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (i = 5)
//			printf("%d ", i);
//	}
//	return 0;
////}
//int func(int a)
//{
//    int b;
//    switch (a)
//    {
//        case 1: b = 30;
//        case 2: b = 20;
//        case 3: b = 16;
//        default: b = 0;
//    }
//    return b;
//}
//#include <stdio.h>
//int main() 
//{
//	int x = 3;
//	int y = 3;
//	switch (x % 2)
//	{
//		case 1:
//			switch (y)
//			{
//				case 0:
//					printf("first");
//				case 1:
//					printf("second");
//					break;
//				default: printf("hello");
//			}
//		case 2:
//			printf("third");
//	}
////	return 0;
////}
//
//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20) break;
//		if (b % 3 == 1)
//		{
//			b = b + 3;
//			continue;
//		}
//		b = b - 5;
//	}
//	printf("%d\n", a);
//	return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//	int a = 1;
//	for (a = 1; a <= 100; a++)
//	{
//		if(a%3==0)
//			printf("%d ", a);
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a >= b && b >= c && a >= c)//abc
//		printf("%d %d %d", a, b, c);
//	else if (a >= b && b <= c && a >= c)//acb
//		printf("%d %d %d", a, c, b);
//	else if (a <= b && b >= c && a >= c)//bac
//		printf("%d %d %d", b, a, c);
//	else if (a <= b && b >= c && a <= c)//bca
//		printf("%d %d %d", b, c, a);
//	else if (a >= b && b <= c && a <= c)//cab
//		printf("%d %d %d", c, a, b);
//	else if (a <= b && b <= c && a <= c)//cba
//		printf("%d %d %d", c, b, a);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a;
//	int i = 0;
//	int j = 0;
//	for (a = 100;a <= 200;a++)
//	{
//
//		for (i = 2;i < a;i++)
//		{
//			if (a % i == 0)
//			{
//				break;
//			}
//		}
//		if (a == i)
//		{
//			printf("%d ", a);
//		}
//	}
//	return 0;
//}
//
//


//for (i = 1;i <= 15;i++)
//if (a % i != 0)
//printf("%d ", a);
//
//#include <stdio.h>
//int main()
//{
//	int y;
// 	for (y = 1000;y <= 2000;y++)
//	{
//		if (y % 100 == 0)
//			if (y % 400 == 0)
//				printf("%d ", y);
//			else
//				continue;
//		else if (y % 4 == 0)
//			printf("%d ", y);
//	}
//	return 0;
//}
#include <stdio.h>
int main()
{
	int a, b, c;
	printf("请输入：\n");
	scanf("%d %d", &a, &b);  
	if (a < b)
	{
		c = a;
		a = b;
		b = c;
	}
	int i = 0;
	for (i = b;i > 0;i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			printf("最大公约数 %d\n",i);
			break;
		}
	}
	return 0;
}