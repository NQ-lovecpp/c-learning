#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


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


// 插入排序
void InsertSort(int* a, int n)
{
	for (int i = 1;i < n;i++)
	{
		int end = i;
		int tmp = a[end];
		while (end > 0)
		{
			if (a[end - 1] > tmp)
			{
				a[end] = a[end - 1];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end] = tmp;
	}
}


// 希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;	//调整希尔增量
		for (int i = 0; i < n - gap; i++)	//从0遍历到size-gap-1
		{
			for (int i = 1;i < n;i++)
			{
				int end = i;
				int tmp = a[end];
				while (end > 0)
				{
					if (a[end - gap] > tmp)
					{
						a[end] = a[end - gap];
						end-=gap;
					}
					else
					{
						break;
					}
				}
				a[end] = tmp;
			}
		}
	}
}


// 选择排序
void SelectSort(int* a, int n)
{

}


// 堆排序
void AdjustDwon(int* a, int n, int root)
{

}
void HeapSort(int* a, int n)
{

}


// 冒泡排序
void BubbleSort(int* a, int n)
{
	int i = 0, j = 0;
	for (int i = n;i >=0;i--)
	{
		for (int j = 1;j < i;j++)
		{
			if (a[j-1] > a[j])
			{
				Swap(&a[j-1], &a[j]);
			}
		}
	}
}


// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	int key = a[left];
	int keyIndex = left;
	while (left < right)
	{
		while (left<right && a[right]>=key)
		{
			right--;
		}

		while (left < right && a[left] <= key)
		{
			left++;
		}

		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyIndex], &a[left]);
	return left;
}


// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int temp = a[left];
	int holeIndex = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[holeIndex])
		{
			right--;
		}
		a[holeIndex] = a[right];
		holeIndex = right;

		while (left < right && a[left] <= a[holeIndex])
		{
			left++;
		}
		a[holeIndex] = a[left];
		holeIndex = left;
	}
	a[holeIndex] = temp;
	return holeIndex;
}


// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int keyIndex = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyIndex] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[left], &a[prev]);
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int key = PartSort3(a, left, right);
	QuickSort(a, left, key - 1);
	QuickSort(a, key + 1, right);
}


// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{

}


// 归并排序递归实现
void MergeSort(int* a, int n)
{

}


// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{

}


// 计数排序
void CountSort(int* a, int n)
{

}


// 测试排序的性能对比
void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();
	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();
	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();
	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}

void TestInsertSort()
{
	printf("InsertSort:\n");
	//int a[] = { 4,7,1,9,3,4,5,8,3,2 };
	int a[] = { 4,7,1,9,3,6,5,8,3,2,0 };
	PrintArray(a, sizeof(a) / sizeof(int));
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

void TestBubbleSort()
{
	printf("BubbleSort:\n");
	int a[] = { 4,7,1,9,3,6,5,8,3,2,0 };
	PrintArray(a, sizeof(a) / sizeof(int));
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

void TestSelectSort()
{
	//int a[] = { 4,7,1,9,3,6,5,8,3,2,0 };
	int a[] = { 9,7,1,3,3,0,5,8,3,2,3 };
	PrintArray(a, sizeof(a) / sizeof(int));
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestShellSort()
{
	printf("ShellSort:\n");
	int a[] = { 4,7,1,9,3,6,5,8,3,2,0 };
	PrintArray(a, sizeof(a) / sizeof(int));
	//InsertSort(a, sizeof(a) / sizeof(int));
	//PrintArray(a, sizeof(a) / sizeof(int));

	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

int compar(int* p1, int* p2)
{
	if (*p1 > *p2)
	{
		return 1;
	}
	else if (*p1 < *p2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void Testqsort()
{
	printf("qsort:\n");
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };
	PrintArray(a, sizeof(a) / sizeof(int));
	//QuickSort(a, 0, (sizeof(a) / sizeof(int)) - 1);
	qsort(a, sizeof(a)/sizeof(int), sizeof(int),compar);
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

void TestQuickSort()
{
	printf("QuickSort:\n");
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };
	PrintArray(a, sizeof(a) / sizeof(int));
	QuickSort(a, 0, (sizeof(a) / sizeof(int)) - 1);
	//QuickSortNonR(a, 0, (sizeof(a) / sizeof(int)) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

void TestMergeSort()
{
	printf("MergeSort:\n");
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };
	PrintArray(a, sizeof(a) / sizeof(int));
	MergeSort(a, (sizeof(a) / sizeof(int)));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

void TestCountSort()
{
	printf("CountSort:\n");
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };
	PrintArray(a, sizeof(a) / sizeof(int));
	CountSort(a, (sizeof(a) / sizeof(int)));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}


int main()
{
	Testqsort();
	TestBubbleSort();
	TestInsertSort();
	TestQuickSort();
	TestShellSort();


	return 0;
}