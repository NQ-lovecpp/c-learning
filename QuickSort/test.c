#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Stack.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* a, int* b)
{
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

//Hoare
int PartSort(int* a, int left, int right)
{
	int KeyIndex = left;
	while (left < right)
	{
		// 右边找小
		while (left < right && a[right] >= a[KeyIndex])
		{
			--right;
		}
		// 左边找大
		while (left < right && a[left] <= a[KeyIndex])
		{
			++left;
		}

		Swap(&a[left], &a[right]);
	}

	Swap(&a[KeyIndex], &a[left]);
	return left;
}

//挖坑法
int PartSort2(int* a, int left, int right)
{
	int Key = a[left];
	int HoleIndex = left;//坑的下标

	while (left < right)
	{
		// 右边找小
		while (left < right && a[right] >= Key)
		{
			--right;
		}

		a[HoleIndex] = a[right];
		HoleIndex = right;
		// 左边找大
		while (left < right && a[left] <= Key)
		{
			++left;
		}

		a[HoleIndex] = a[left];
		HoleIndex = left;
	}

	a[HoleIndex] = Key;
	return HoleIndex;
}

//前后指针法
int PartSort3(int* arr, int left, int right)
{
	int key = left;
	int prev = left;
	int cur = left + 1;

	while (cur <= right)
	{
		//arr[cur]小于基准值就交换
		if (arr[cur] <= arr[key] && ++prev != cur)
		{
			Swap(&arr[cur], &arr[prev]);
		}
		cur++;
	}

	Swap(&arr[key], &arr[prev]);
	return prev;
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int KeyIndex = PartSort3(a, begin, end);

	QuickSort(a, begin, KeyIndex - 1);
	QuickSort(a, KeyIndex + 1, end);
}

void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	STInit(&st);
	STPush(&st, end);
	STPush(&st, begin);

	while (!STEmpty(&st))
	{
		int left = STTop(&st);
		STPop(&st);

		int right = STTop(&st);
		STPop(&st);

		int KeyIndex = PartSort(a, left, right);

		if (KeyIndex + 1 < right)
		{
			STPush(&st, right);
			STPush(&st, KeyIndex + 1);
		}

		if (left < KeyIndex - 1)
		{
			STPush(&st, KeyIndex - 1);
			STPush(&st, left);
		}
	}
}

int main()
{
	int arr[8] = { 55,74,32,67,12,23,49,87 };
	printf("Before:\n");
	PrintArray(arr, (sizeof(arr) / sizeof(int)));
	printf("After:\n");
	QuickSort(arr, 0, (sizeof(arr) / sizeof(int))-1);
	PrintArray(arr, (sizeof(arr) / sizeof(int)));

	return 0;
}


////Hoare
//int PartSort(int* a, int left, int right)
//{
//	int KeyIndex = left;
//	while (left < right)
//	{
//		// 右边找小
//		while (left < right && a[right] >= a[KeyIndex])
//		{
//			--right;
//		}
//		// 左边找大
//		while (left < right && a[left] <= a[KeyIndex])
//		{
//			++left;
//		}
//
//		Swap(&a[left], &a[right]);
//	}
//
//	Swap(&a[KeyIndex], &a[left]);
//	return left;
//}
//
////挖坑法
//int PartSort2(int* a, int left, int right)
//{
//	int key = a[left];
//	int HoleIndex = left;
//
//	while (left < right)
//	{
//		// 右边找小
//		while (left < right && a[right] >= key)
//		{
//			--right;
//		}
//
//		a[HoleIndex] = a[right];
//		HoleIndex = right;
//		// 左边找大
//		while (left < right && a[left] <= key)
//		{
//			++left;
//		}
//
//		a[HoleIndex] = a[left];
//		HoleIndex = left;
//	}
//
//	a[HoleIndex] = key;
//	return HoleIndex;
//}
//
////前后指针法
//int PartSort3(int* arr, int left, int right)
//{
//	int key = left;
//	int prev = left;
//	int cur = left + 1;
//
//	while (cur <= right)
//	{
//		//arr[cur]小于基准值就交换
//		if (arr[cur] <= arr[key] && ++prev != cur)	//这里做了优化：如果prev+1等于cur则不用交换，该语句顺便将prev加一
//		{
//			Swap(&arr[cur], &arr[prev]);
//		}
//		cur++;
//	}
//
//	Swap(&arr[key], &arr[prev]);
//	return prev;
//}
//
//void QuickSort(int* a, int begin, int end)
//{
//	if (begin >= end)
//	{
//		return;
//	}
//	int KeyIndex = PartSort(a, begin, end);
//
//	QuickSort(a, begin, KeyIndex - 1);
//	QuickSort(a, KeyIndex + 1, end);
//}
//
//void QuickSortNonR(int* a, int begin, int end)
//{
//	ST st;
//	STInit(&st);
//	STPush(&st, end);
//	STPush(&st, begin);
//
//	while (!STEmpty(&st))
//	{
//		int left = STTop(&st);
//		STPop(&st);
//
//		int right = STTop(&st);
//		STPop(&st);
//
//		int KeyIndex = PartSort(a, left, right);
//
//		if (KeyIndex + 1 < right)
//		{
//			STPush(&st, right);
//			STPush(&st, KeyIndex + 1);
//		}
//
//		if (left < KeyIndex - 1)
//		{
//			STPush(&st, KeyIndex - 1);
//			STPush(&st, left);
//		}
//	}
//}