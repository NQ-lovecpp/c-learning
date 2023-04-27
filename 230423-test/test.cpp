#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int max(int a, int b)
//{
//	return a > b ? a : b;
//}
//
//int max(int a, int b, int c)
//{
//	int m = a > b ? a : b;
//	return m > c ? m : c;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 50;
//	int c = 90;
//	printf("abc中最大数是：%d\n", max(a, b, c));
//	return 0;
//}

//#include <stdio.h>
//int pow(int base, int expo)
//{
//	int ret = 1;
//	for (int i = 0;i < expo;i++)
//	{
//		ret *= base;
//	}
//	return ret;
//}
//
//int pow(int expo)
//{
//	int ret = 1;
//	for (int i = 0;i < expo;i++)
//	{
//		ret *= 2;
//	}
//	return ret;
//}
//
//int main()
//{
//	//默认为2的情况
//	int sum = 0;
//	int base = 0;
//	for (int i = 1;i <= 10;i++)
//	{
//		sum += pow(i);
//	}
//	printf("默认为2时，sum=%d\n", sum);
//	//其他情况
//	sum = 0;
//	printf("指定底数时，请输入底数：");
//	scanf("%d", &base);
//	for (int i = 1;i <= 10;i++)
//	{
//		sum += pow(base, i);
//	}
//	printf("sum=%d", sum);
//	return 0;
//}

#include <stdio.h>
int age(int i)//i表示第i个人
{
	if (i == 1)
		return 10;
	else
		return age(i - 1) + 2;
}

int main()
{
	int i = 1;
	for (i = 1;i < 6;i++)
	{
		printf("第%d个人%d岁\n", i, age(i));
	}
	return 0;
}