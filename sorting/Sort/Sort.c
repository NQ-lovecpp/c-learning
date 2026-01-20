#include "Sort.h"
#include "Stack.h"
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// 时间复杂度(最坏)：O(N^2) -- 逆序
// 时间复杂度(最好)：O(N) -- 顺序有序
//void InsertSort(int* a, int n)
//{
//	for (int i = 1; i < n; ++i)
//	{
//		// [0, end] 有序，插入tmp依旧有序
//		int end = i - 1;
//		int tmp = a[i];
//
//		while (end >= 0)
//		{
//			if (a[end] < tmp)
//			{
//				a[end + 1] = a[end];
//				--end;
//			}
//			else
//			{
//				break;
//			}
//		}
//
//		a[end + 1] = tmp;
//	}
//}
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


/*for (int j = 0; j < gap; j++)
	{
		for (int i = j; i < n - gap; i += gap)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}

			a[end + gap] = tmp;
		}
	}*/

	// 休息20:28继续
	// O(N^1.3)
void ShellSort(int* a, int n)
{
	// 1、gap > 1 预排序
	// 2、gap == 1 直接插入排序

	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;  // +1可以保证最后一次一定是1
		// gap = gap / 2;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}

			a[end + gap] = tmp;
		}
	}
}

void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; ++j)
	{
		bool exchange = false;
		for (int i = 1; i < n - j; i++)
		{
			if (a[i - 1] > a[i])
			{
				int tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;

				exchange = true;
			}
		}

		if (exchange == false)
		{
			break;
		}
	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int maxi = begin, mini = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}

			if (a[i] < a[mini])
			{
				mini = i;
			}
		}

		Swap(&a[begin], &a[mini]);
		// 如果maxi和begin重叠，修正一下即可
		if (begin == maxi)
		{
			maxi = mini;
		}

		Swap(&a[end], &a[maxi]);

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

//void MergeSortNonR(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//
//	// 1  2  4 ....
//	int gap = 1;
//	while (gap < n)
//	{
//		int j = 0;
//		for (int i = 0; i < n; i += 2 * gap)
//		{
//			// 每组的合并数据
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + 2 * gap - 1;
//
//			printf("[%d,%d][%d,%d]\n", begin1, end1, begin2, end2);
//
//			if (end1 >= n || begin2 >= n)
//			{
//				break;
//			}
//
//			// 修正
//			if (end2 >= n)
//			{
//				end2 = n - 1;
//			}
//
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//				{
//					tmp[j++] = a[begin1++];
//				}
//				else
//				{
//					tmp[j++] = a[begin2++];
//				}
//			}
//
//			while (begin1 <= end1)
//			{
//				tmp[j++] = a[begin1++];
//			}
//
//			while (begin2 <= end2)
//			{
//				tmp[j++] = a[begin2++];
//			}
//
//			// 归并一组，拷贝一组
//			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
//		}
//		printf("\n");
//
//		//memcpy(a, tmp, sizeof(int) * n);
//		gap *= 2;
//	}
//
//	free(tmp);
//}


void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);

	// 1  2  4 ....
	int gap = 1;
	while (gap < n)
	{
		int j = 0;
		for (int i = 0; i < n; i += 2 * gap)
		{
			// 每组的合并数据
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			printf("[%d,%d][%d,%d]\n", begin1, end1, begin2, end2);

			if (end1 >= n || begin2 >= n)
			{
				break;
			}

			// 修正
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

			// 归并一组，拷贝一组
			//memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		printf("\n");

		memcpy(a, tmp, sizeof(int) * n);
		gap *= 2;
	}

	free(tmp);
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