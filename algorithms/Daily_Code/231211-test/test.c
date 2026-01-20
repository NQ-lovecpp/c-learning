#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//Hoare 法
int PartSort(int* arr, int left, int right)
{
	int keyi = left;
	while (left < right)
	{
		// 右边找小
		while (left < right && arr[right] >= arr[keyi])
		{
			--right;
		}
		// 左边找大
		while (left < right && arr[left] <= arr[keyi])
		{
			++left;
		}

		Swap(&arr[left], &arr[right]);
	}

	Swap(&arr[keyi], &arr[left]);
	return left;
}

//挖坑法
int PartSort2(int* arr, int left, int right)
{
	int key = arr[left];
	int hole = left;

	while (left < right)
	{
		// 右边找小
		while (left < right && arr[right] >= key)
		{
			--right;
		}

		arr[hole] = arr[right];
		hole = right;
		// 左边找大
		while (left < right && arr[left] <= key)
		{
			++left;
		}

		arr[hole] = arr[left];
		hole = left;
	}

	arr[hole] = key;
	return hole;
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
		if (arr[cur] <= arr[key] && ++prev != cur)	//这里做了优化：如果prev+1等于cur则不用交换，该语句顺便将prev加一
		{
			Swap(&arr[cur], &arr[prev]);
		}
		cur++;
	}

	Swap(&arr[key], &arr[prev]);
	return prev;
}

//快速排序_递归
void QuickSort(int* arr, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int keyi = PartSort3(arr, begin, end);

	QuickSort(arr, begin, keyi - 1);
	QuickSort(arr, keyi + 1, end);
}

//快速排序_非递归
void QuickSortNonR(int* arr, int begin, int end)
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

		int keyi = PartSort3(arr, left, right);

		if (keyi + 1 < right)
		{
			STPush(&st, right);
			STPush(&st, keyi + 1);
		}

		if (left < keyi - 1)
		{
			STPush(&st, keyi - 1);
			STPush(&st, left);
		}
	}
}

void PrintArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr1[6] = { 8, 10, 5, 6, 3, 13 };
	QuickSort(arr1, 0, -1+sizeof(arr1) / sizeof(arr1[0]));
	printf("测试1：");
	PrintArray(arr1, sizeof(arr1) / sizeof(arr1[0]));

	int arr2[10] = { 4,7,1,9,3,6,5,8,3,2 };
	QuickSort(arr2, 0, -1+sizeof(arr2) / sizeof(arr2[0]));
	printf("测试2：");
	PrintArray(arr2, sizeof(arr2) / sizeof(arr2[0]));

	return 0;
}

