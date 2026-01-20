// sort.c

#include "Sort.h"
#include "Stack.h"

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// 插入排序
void InsertSort(int* arr, int size)
{
	//从i=1开始遍历是因为默认了首元素组成的单元素序列是已有序的
	for (int i = 1; i < size; ++i)
	{
		int end = i;      //end找最终待排数据落位的数组下标
		int temp = arr[end];	//记录待排数值

		while (end > 0)
		{
			if (arr[end - 1] > temp)	//若前一个数大于待排数值，则后移一位
			{
				arr[end] = arr[end - 1];
				end--;
			}
			else
			{
				break;
			}
		}

		arr[end] = temp;	//将数据放入应该插入的位置
	}
}



void AdjustDown(int* arr, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		//find bigger child
		if (child + 1 < size && arr[child + 1] > arr[child])
		{
			child++;
		}

		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//排升序 建大堆
void HeapSort(int* arr, int size)
{
	//建堆
	//向下调整建堆
	for (int i = (size - 1 - 1) / 2;i >= 0;i--)
	{
		AdjustDown(arr, size, i);
	}
	int end = size - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
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

//快速排序_递归
void QuickSort(int* arr, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int keyi = PartSort(arr, begin, end);

	QuickSort(arr, begin, keyi - 1);
	QuickSort(arr, keyi + 1, end);
}


//归并排序_递归法
void _MergeSort(int* arr, int begin,int end,int* tmp)
{
	if (begin == end)
	{
		return;
	}

	//小区间优化
	if (end - begin + 1 < 10)
	{
		InsertSort(arr + begin, end - begin + 1);
		return;
	}
	int mid = (begin + end)/2;
	_MergeSort(arr, begin, mid, tmp);
	_MergeSort(arr, mid+1, end, tmp);

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
	memcpy((arr + begin), tmp + begin, sizeof(int) * (end - begin + 1));
}

void MergeSort(int* arr, int size)
{
	int* tmp = malloc(sizeof(int) * size);
	_MergeSort(arr, 0, size - 1,tmp);
	free(tmp);
}

