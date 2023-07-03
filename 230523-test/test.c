#define _CRT_SECURE_NO_WARNINGS

//#include <string.h>
//#include <stdio.h>
//char* my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	while (*dest)
//	{
//		dest++;
//	}
//
//	for (;(*src) != '\0';src++, dest++)
//	{
//		*dest= *src;
//	}
//	*dest = '\0';
//	return ret;
//}
//
//int main()
//{
//	char a[10] = "abcd";
//	char b[10] = "efgh";
//	my_strcat(a, b);
//	printf("%s", a);
//	return 0;
//}


#include <stdio.h>

int sum(int a, int b)
{
	return a + b;
}
int mul(int a, int b)
{
	return a * b;
}

void op(int x, int y, int (*f)(int, int))
{
	printf("计算结果：%d", (*f)(x, y));
}

int main()
{
	int a = 10;
	int b = 11;
	int val = 0;
	int (*f[2])(int, int) = { &sum,&mul };
	printf("请选择：\n0. 加法\n1. 乘法\n>");
	scanf("%d", &val);
	printf("输入操作数：");
	scanf("%d %d", &a, &b);
	op(a, b, f[val]);
	return 0;
}

