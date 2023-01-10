#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int a = 1;
//	int b = 1;
//	for (a = 1; a < 10; a++)
//	{
//		for (b = 1; b < 10; b++)
//		{
//			printf("%d * %d = %d	", b, a, a * b);
//		}
//		printf("\n");
//	}
//	return 0;
////}
//
//#include <stdio.h>
//int main()
////{
////	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
////	int left = 0;
////	int right = sizeof(arr) / sizeof(arr[0])-1;//要减一是因为我们要找的是数组的下标
////	
////}
//#include <stdio.h>
//int max(int a,int b)
//{
//	if (a > b)
//		return a;
//	else
//		return b;
//}
//
//int main()
//{
//	int m;
//	int i;
//	int arr[10];
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	m = max(arr[0], arr[1]);
//	for (i = 1;i < 10; i++)
//	{
//		m = max(m, arr[i]);
//	}
//	printf("最大的数是：%d", m);
//}、
//
//
//#include <stdio.h>
//int main()
//{
//	float sum = 0;
//	float even = 2;
//	float odd = 1;
//	while (odd <= 99)
//	{
//		sum = sum + (1 / odd);
//		odd = odd + 2;
//	}
//	while (even <= 100)
//	{
//		sum = sum - (1 / even);
//		even = even + 2;
//	}
//	printf("%f", sum);
//	return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//	int i;
//	for (i = 1;i <= 100;i++)
//	{
//		if (i % 10 == 9)
//			printf("%d ", i);
//		else if (i / 10 == 9)
//			printf("%d ", i);
//		else
//			continue;
//	}
//	return 0;
//}

#include <stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;// 0 1 2 3 4 5 6 7 8 9 
	int right = sizeof(arr) / sizeof(arr[1])-1;
	int key = 7;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] > key)
			right = mid - 1;
		else if (arr[mid] < key)
			left = mid + 1;
		else
			break;
	}
	if (left <= right)
		printf("找到了，下表是%d\n", mid);
	else
		printf("找不到\n");
	return 0;


}