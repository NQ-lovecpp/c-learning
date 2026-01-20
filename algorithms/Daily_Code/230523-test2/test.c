#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int sum(int a, int b)
//{
//	return a + b;
//}
//int mul(int a, int b)
//{
//	return a * b;
//}
//
//void op(int x, int y, int (*f)(int, int))
//{
//	printf("计算结果：%d", (*f)(x, y));
//}
//
//int main()
//{
//	int a = 10;
//	int b = 11;
//	int val = 0;
//	int (*f[2])(int, int) = { &sum,&mul };
//	printf("请选择：\n0. 加法\n1. 乘法\n>");
//	scanf("%d", &val);
//	printf("输入操作数：");
//	scanf("%d %d", &a, &b);
//	op(a, b, f[val]);
//	return 0;
//}


//#include <stdio.h>
//char* fun(char* str, char c)
//{
//	while ((*str) != '\0' && (*str) != c)
//	{
//		str++;
//	}
//	if (*str == '\0')
//	{
//		return NULL;
//	}
//	else
//	{
//		return str;
//	}
//}
//int main()
//{
//	char a[20] = "hello world";
//	char b = 'w';
//
//	printf("%s",fun(a, b));
//	return 0;
//}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* fun(char* str)
{
	char* left = str;
	char* right = str;
	int flag = 1;
	while (*right)
	{
		right++;
	}
	right--;
	while (left < right)
	{
		if (*left != *right)
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1)
	{
		char* ret = (char*)calloc(10,sizeof(char));
		strcpy(ret, "Yes!");
		return ret;
	}
	else
	{
		char* ret = (char*)calloc(10, sizeof(char));
		strcpy(ret, "No!");
		return ret;
	}
	
}
int main()
{
	char a[20] = "abcdefggfedcba";
	char* ret = fun(a);
	printf("是不是回文？\n%s",ret);
	free(ret);
	ret = NULL;
	return 0;
}