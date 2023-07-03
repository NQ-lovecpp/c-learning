#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//void mult(int* start,int len)
//{
//	for (int i = 0;i < len;i++)
//	{
//		*(start + i) = (*(start + i)) * 10;
//	}
//}
//void print(int* arr, int len)
//{
//	for (int i = 0;i < len;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	print(arr, size);
//	mult(arr,size);
//	print(arr, size);
//	return 0;
//}


//10.1 5.8
//#include <stdio.h>
//void swap(float* a, float* b)
//{
//	float tmp = *b;
//	*b = *a;
//	*a = tmp;
//}
//int main()
//{
//	float a = 10.1, b = 5.8;
//	printf("before:	%.1f	%.1f\n", a, b);
//	swap(&a, &b);
//	printf("after:	%.1f	%.1f", a, b);
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>
int* move(int* arr,int m,int len)
{
	return (arr + len - m);
}
int main()
{
	int n = 0, m = 0;
	int i = 0, j = 0;
	printf("输入几个数？");
	scanf("%d", &n);
	printf("移动多少位？");
	scanf("%d", &m);
	int* arr = (int*)calloc(2*n, sizeof(int));
	for (i = 0;i < n;i++)
	{
		printf("输入第%d个数：",i);
		scanf("%d", &arr[i]);
	}
	for (j = 0;j < n;i++, j++)
	{
		arr[i] = arr[j];
	}
	int* start = move(arr, m, n);
	for (i = 0;i < n;i++)
	{
		printf("%d ", *start);
		start++;
	}
	free(arr);
	arr = NULL;
	return 0;
}