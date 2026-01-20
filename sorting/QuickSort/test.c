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

// Hoare法单趟排序
int PartSort(int* a, int left, int right)
{
	// 选择基准元素的索引为 left
	int KeyIndex = left;
	while (left < right)
	{
		// right 从右侧开始，找到第一个小于基准元素的值
		while (left < right && a[right] >= a[KeyIndex])
		{
			--right;
		}
		// left 从左侧开始，找到第一个大于基准元素的值
		while (left < right && a[left] <= a[KeyIndex])
		{
			++left;
		}
		// 交换 left 和 right 的元素
		Swap(&a[left], &a[right]);
	}

	// 将基准元素放置在最终的位置
	Swap(&a[KeyIndex], &a[left]);
	return left;
}

// 挖坑法单趟排序
int PartSort2(int* a, int left, int right)
{
	// 选择基准元素为左侧第一个元素
	int Key = a[left];
	int HoleIndex = left; // 坑的下标，初始为基准元素位置

	while (left < right)
	{
		// 从右侧开始，找到第一个小于基准元素的值
		while (left < right && a[right] >= Key)
		{
			--right;
		}

		// 将右侧小于基准元素的值填充到左侧的坑中
		a[HoleIndex] = a[right];
		HoleIndex = right;

		// 从左侧开始，找到第一个大于基准元素的值
		while (left < right && a[left] <= Key)
		{
			++left;
		}

		// 将左侧大于基准元素的值填充到右侧的坑中
		a[HoleIndex] = a[left];
		HoleIndex = left;
	}

	// 将基准元素放置到最后一个坑中，即填充到最终的位置
	a[HoleIndex] = Key;
	return HoleIndex;
}

// 前后指针法
int PartSort3(int* arr, int left, int right)
{
	int key = left; // 将最左边的元素作为基准值
	int prev = left; // 后指针（动得慢）
	int cur = left + 1; // 前指针（动得快）

	while (cur <= right)
	{
		// 当cur遍历到的元素小于等于基准值时，先将prev指针向后移动一位，再将cur交换到prev指针指向的位置
		if (arr[cur] <= arr[key] && ++prev != cur)
		{
			Swap(&arr[cur], &arr[prev]);
		}
		cur++;
	}

	// 最后将基准值交换到prev指针指向的位置，以完成单趟排序
	Swap(&arr[key], &arr[prev]);
	return prev; // 返回基准值的位置，用于后续的划分
}

// 快速排序的递归实现
void QuickSort(int* a, int begin, int end)
{
	//两种情况下直接返回：1. 区间只有一个值 2. 区间不存在
	if (begin >= end)
	{
		return;
	}

	// 使用单趟排序函数 PartSort 对序列进行划分，并获取基准元素的位置
	int KeyIndex = PartSort(a, begin, end);

	// 对基准元素左侧的子序列排序
	QuickSort(a, begin, KeyIndex - 1);

	// 对基准元素右侧的子序列排序
	QuickSort(a, KeyIndex + 1, end);
}

// 非递归快速排序实现
void QuickSortNonR(int* a, int begin, int end)
{
	ST st; // 定义一个栈，用于模拟递归过程
	STInit(&st); // 初始化栈

	// 将初始的 begin 和 end 压入栈，相当于递归的入口
	STPush(&st, end);
	STPush(&st, begin);

	while (!STEmpty(&st))
	{
		// 从栈中取出当前处理的 begin 和 end
		int left = STTop(&st);
		STPop(&st);

		int right = STTop(&st);
		STPop(&st);

		// 调用 PartSort 函数对序列进行划分，并得到基准元素的位置
		int KeyIndex = PartSort(a, left, right);

		// 判断是否需要对右侧子序列进行排序，并将其入栈
		if (KeyIndex + 1 < right)
		{
			STPush(&st, right);
			STPush(&st, KeyIndex + 1);
		}

		// 判断是否需要对左侧子序列进行排序，并将其入栈
		if (left < KeyIndex - 1)
		{
			STPush(&st, KeyIndex - 1);
			STPush(&st, left);
		}
	}

	// 栈中所有任务处理完毕，排序完成
	STDestroy(&st);
}

// 三值取中法优化的快速排序递归实现
void QuickSortOptimized(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	// 三值取中法选取基准数
	int mid = begin + (end - begin) / 2;
	if (a[begin] > a[mid])
	{
		Swap(&a[begin], &a[mid]);
	}
	if (a[mid] > a[end])
	{
		Swap(&a[mid], &a[end]);
	}
	if (a[begin] > a[mid])
	{
		Swap(&a[begin], &a[mid]);
	}

	// 将基准数交换到子序列的第二个位置
	Swap(&a[mid], &a[begin + 1]);

	// 使用霍尔法进行划分
	int KeyIndex = PartSort(a, begin, end);

	// 对左右子序列递归进行排序
	QuickSortOptimized(a, begin, KeyIndex - 1);
	QuickSortOptimized(a, KeyIndex + 1, end);
}

//插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		// [0, end] 有序，插入tmp依旧有序
		int end = i;
		int tmp = a[i + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

// 三数取中法优化的快速排序递归实现（带小区间优化）
void QuickSortOptimizedWithInsertion(int* a, int begin, int end)
{
	// 小区间优化：当待排序子序列的长度小于等于10时，使用插入排序
	if (end - begin + 1 <= 10)
	{
		InsertSort(a + begin, end - begin + 1);
		return;
	}

	// 三数取中法选取基准数
	int mid = begin + (end - begin) / 2;
	if (a[begin] > a[mid])
	{
		Swap(&a[begin], &a[mid]);
	}
	if (a[mid] > a[end])
	{
		Swap(&a[mid], &a[end]);
	}
	if (a[begin] > a[mid])
	{
		Swap(&a[begin], &a[mid]);
	}

	// 将基准数交换到子序列的第二个位置
	Swap(&a[mid], &a[begin + 1]);

	// 使用霍尔法进行划分
	int KeyIndex = PartSort(a, begin, end);

	// 对左右子序列递归进行排序
	QuickSortOptimizedWithInsertion(a, begin, KeyIndex - 1);
	QuickSortOptimizedWithInsertion(a, KeyIndex + 1, end);
}

int main()
{
	int arr[8] = { 55,74,32,67,12,23,49,87 };
	printf("Before:\n");
	PrintArray(arr, (sizeof(arr) / sizeof(int)));
	printf("After:\n");
	QuickSortOptimizedWithInsertion(arr, 0, (sizeof(arr) / sizeof(int))-1);
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