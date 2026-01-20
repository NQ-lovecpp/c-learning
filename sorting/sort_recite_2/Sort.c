#include "Sort.h"
#include "Stack.h"


void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void InsertSort(int* arr, int size)
{

}

void InsertSort2(int* arr, int size)
{

}

void ShellSort(int* arr, int size)
{

}

void BubbleSort(int* arr, int size)
{

}

void SelectSort(int* arr, int size)
{

}

void AdjustDown(int* arr, int size, int parent)
{

}

//排升序 建大堆
void HeapSort(int* arr, int size)
{

}

//Hoare
int PartSort(int* arr, int left, int right)
{

}

//挖坑法
int PartSort2(int* arr, int left, int right)
{

}

//前后指针法
int PartSort3(int* arr, int left, int right)
{

}

void QuickSort(int* arr, int begin, int end)
{

}

void QuickSortNonR(int* arr, int begin, int end)
{

}

//归并排序_递归法
//升序
void _MergeSort(int* arr, int begin, int end, int* tmp)
{
	if (begin == end)
	{
		return;
	}

	int mid = (begin + end) / 2;
	_MergeSort(arr, begin, mid, tmp);
	_MergeSort(arr, mid + 1, end, tmp);

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[i++] = arr[begin1++];
		}
		else
		{
			tmp[i++] = arr[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = arr[begin1++];
	}
	
	while (begin2 <= end2)
	{
		tmp[i++] = arr[begin2++];
	}

	memcpy(arr + begin, tmp + begin, (end - begin +1) * sizeof(int));
}

void MergeSort(int* arr, int size)
{
	int* tmp = (int*)malloc(size * sizeof(int));
	_MergeSort(arr, 0, size - 1, tmp);
	free(tmp);
	tmp = NULL;
}


void MergeSortNonR(int* arr, int size)
{

}


void CountSort(int* a, int n)
{

}