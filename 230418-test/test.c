#define _CRT_SECURE_NO_WARNINGS


//#include <stdio.h>
//
//float temp(float f)
//{
//	return (5.0 / 9.0) * (f - 32);
//}
//int main()
//{
//	float f = 0;
//	printf("输入摄氏度：");
//	scanf("%f", &f);
//	printf("摄氏度是：%f", temp(f));
//	return 0;
//}

//#include <stdio.h>
//int fib(int n)
//{
//	if (n == 1 || n == 2)
//		return 1;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", fib(n));
//	return 0;
//}



//#include <stdio.h>
//
//void bubblesort(int* arr, int arrlen)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0;i < arrlen-1;i++)
//	{
//		for (j = 0;j < arrlen - 1 - i;j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[5] = { 0 };
//	printf("输入5个数据：");
//	for (int i = 0;i < 5;i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	bubblesort(arr, (sizeof(arr) / sizeof(arr[0])));
//	printf("修改后的数据：");
//	for (int i = 0;i < 5;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


#include <stdio.h>
int isprime(int a)
{
	int count = 0;
	for (int m = 1;m <= a;m++)
	{
		if (a % m == 0)
		{
			count++;
		}
	}
	if (count == 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int i = 0;
	int arr[100] = { 0 };
	for (i = 0;i < 100;i++)
	{
		arr[i] = i + 1;
	}
	printf("1~100的素数有：");
	for (i = 0; i < 100;i++)
	{
		if (arr[i] != -1)
		{
			if (isprime(arr[i]))
			{
				printf("%d ", arr[i]);
			}
		}
	}
	return 0;
}