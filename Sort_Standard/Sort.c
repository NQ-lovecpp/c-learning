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

void InsertSort2(int* arr, int size)
{
	int i = 0;
	for (i = 1; i < size; i++)
	{
		int left = 0;
		int right = i - 1;

		//查找插入位置
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (arr[i] > arr[mid])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}

		//后移数据并插入
		int temp = arr[i];
		for (right = i; right > left; right--)
		{
			arr[right] = arr[right - 1];
		}
		arr[left] = temp;
	}
}

//void ShellSort(int* arr, int size)
//{
//	// 1、gap > 1 预排序
//	// 2、gap == 1 直接插入排序
//
//	int gap = size;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;  //调整希尔增量
//		// gap = gap / 2;
//		for (int i = 0; i < size - gap; ++i)
//		{
//			int end = i;
//			int tmp = arr[end + gap];
//			while (end >= 0)
//			{
//				if (arr[end] > tmp)
//				{
//					arr[end + gap] = arr[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//
//			arr[end + gap] = tmp;
//		}
//	}
//}

void ShellSort(int* arr, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;  //调整希尔增量
		for (int i = 0; i < size; i++)
		{
			int end = i;
			int tmp = arr[end];
			while (end >= 0)
			{
				if (arr[end-gap] > tmp)
				{
					arr[end] = arr[end-gap];
					end -= gap;
				}
				else
				{
					break;
				}
			}

			arr[end] = tmp;
		}
	}
}

void BubbleSort(int* arr, int size)
{
	for (int j = 0; j < size; ++j)
	{
		bool exchange = false;
		for (int i = 1; i < size - j; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				int tmp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = tmp;

				exchange = true;
			}
		}

		if (exchange == false)
		{
			break;
		}
	}
}

void SelectSort(int* arr, int size)
{
	int begin = 0, end = size - 1;
	while (begin < end)
	{
		int maxi = begin, mini = begin;
		for (int i = begin; i <= end; i++)
		{
			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}

			if (arr[i] < arr[mini])
			{
				mini = i;
			}
		}

		Swap(&arr[begin], &arr[mini]);
		// 如果maxi和begin重叠，修正一下即可
		if (begin == maxi)
		{
			maxi = mini;
		}

		Swap(&arr[end], &arr[maxi]);

		++begin;
		--end;
	}
}

void AdjustDown(int* a, int n,int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//find small child
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
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
void HeapSort(int* a, int n)
{
	//建堆
	//向下调整建堆
	for (int i = (n - 1 - 1) / 2;i >= 0;i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
	}
}

//Hoare
int PartSort(int* a, int left, int right)
{
	int keyi = left;
	while (left < right)
	{
		// 右边找小
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		// 左边找大
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}

		Swap(&a[left], &a[right]);
	}
	
	Swap(&a[keyi], &a[left]);
	return left;
}

//挖坑法
int PartSort2(int* a, int left, int right)
{
	int key = a[left];
	int hole = left;

	while (left < right)
	{
		// 右边找小
		while (left < right && a[right] >= key)
		{
			--right;
		}

		a[hole] = a[right];
		hole = right;
		// 左边找大
		while (left < right && a[left] <= key)
		{
			++left;
		}

		a[hole] = a[left];
		hole = left;
	}

	a[hole] = key;
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

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int keyi = PartSort3(a, begin, end);

	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
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

		int keyi = PartSort3(a, left, right);

		if (keyi + 1 < right)
		{
			STPush(&st, right);
			STPush(&st, keyi+1);
		}

		if (left < keyi - 1)
		{
			STPush(&st, keyi - 1);
			STPush(&st, left);
		}
	}
}

//归并排序_递归法
void _MergeSort(int* a, int begin,int end,int* tmp)
{
	if (begin == end)
	{
		return;
	}

	//小区间优化
	if (end - begin + 1 < 10)
	{
		InsertSort(a+begin, end - begin + 1);
		return;
	}
	int mid = (begin + end)/2;
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid+1, end, tmp);

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1<=end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	memcpy((a+begin), tmp+begin,sizeof(int)*(end-begin+1));
}

void MergeSort(int* a, int n)
{
	int* tmp = malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1,tmp);
	free(tmp);
}


void MergeSortNonR(int* arr, int size)
{
	//申请空间
	int* temp = (int*)malloc(size * sizeof(int));
	if (temp == NULL)
	{
		perror("malloc fail!\n");
		return;
	}

	//归并排序
	int gap = 1;
	while (gap < size)
	{
		//单趟排序
		int i = 0;
		for (i = 0; i < size; i += 2 * gap)	//一次跨2*gap格，两个数组
		{
			int begin1 = i, end1 = i + gap - 1;			//第一个数组下标区间
			int begin2 = i + gap, end2 = i + 2 * gap - 1;	//第二个数组下标区间，别忘记加上i

			//数组边界处理
			if (end1 >= size)	//第一个数组越界
			{
				break;
			}
			if (begin2 >= size)	//第二个数组全部越界
			{
				break;
			}
			if (end2 >= size)	//第二个数组部分越界
			{
				end2 = size - 1;
			}

			//排序合并
			int j = i;	//合并后数组的下标
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (arr[begin1] <= arr[begin2])
				{
					temp[j] = arr[begin1];
					begin1++;
				}
				else
				{
					temp[j] = arr[begin2];
					begin2++;
				}
				j++;
			}

			while (begin1 <= end1)
			{
				temp[j] = arr[begin1];
				begin1++;
				j++;
			}

			while (begin2 <= end2)
			{
				temp[j] = arr[begin2];
				begin2++;
				j++;
			}

			//拷贝temp数组到原数组（排哪个区间就拷贝哪个区间，end2是闭区间哦）
			for (j = i; j <= end2; j++)
			{
				arr[j] = temp[j];
			}
		}
		gap *= 2;
	}

	free(temp);
	temp = NULL;
}


void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];
	for (int i = 0;i < n;i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}

	}
	int range = max - min + 1;
	int* countA = (int*)malloc(sizeof(int) * range);
	memset(countA, 0, sizeof(int) * range);

	for (int i = 0;i < n;i++)
	{
		countA[a[i] - min]++;
	}

	//排序
	int k = 0;
	for (int j = 0;j < range;j++)
	{
		while (countA[j]--)
		{
			a[k++] = j + min;
		}
	}

}