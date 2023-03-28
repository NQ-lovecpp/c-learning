#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
//struct S
//{
//	int n;
//	char c;
//	int arr[0];//柔性数组成员
//};
//
//int main()
//{
//
//	return 0;
//}
//struct S
//{
//	int n;
//	char c;
//	int* arr;
//};
//int main()
//{
//
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
//	int* ptr = malloc(10 * sizeof(int));
//	if (ptr == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	else
//	{
//		ps->arr = ptr;
//	}
//	ps->n = 100;
//	ps->c = 100;
//	for (int i = 0;i < 10;i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (int i = 0;i < 10;i++)
//	{
//		printf("%d", ps->arr[i]);
//	}
//
//
//	//释放
//	free(ps->arr);
//	ps->arr = NULL;
//	free(ps);
//	ps = NULL;
//	return 0;
//}



#include <stdio.h>
int main()
{
	unsigned char a = 200;
	unsigned char b = 100;
	unsigned char c = 0;
	c = a + b;
	printf("%d %d", (a + b), c);
	return 0;
}

