#include <iostream>
#include <utility>
using namespace std;

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
void _QuickSort(int* arr, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int keyi = PartSort(arr, begin, end);

	_QuickSort(arr, begin, keyi - 1);
	_QuickSort(arr, keyi + 1, end);
}

// 二分查找
void BinarySearch(int* arr, int size, int to_find)
{
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < to_find)
		{
			left = mid + 1;
		}
		else if (arr[mid] > to_find)
		{
			right = mid - 1;
		}
		else
		{
			cout << "找到了,下标为：" << mid << endl;
			return;
		}
	}

	cout << "没有找到" << endl;
}

int PartSort_Hoare(int* arr, int left, int right)
{
	int keyi = left;
	while (left < right)
	{
		// 右边找小
		while (left < right && arr[right] >= arr[keyi])
		{
			right--;
		}

		// 左边找大
		while (left < right && arr[left] <= arr[keyi])
		{
			left++;
		}

		std::swap(arr[left], arr[right]);
	}

	std::swap(arr[left], arr[keyi]);
	return left;
}

void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int mid = PartSort_Hoare(arr, left, right);
	QuickSort(arr, left, mid - 1);
	QuickSort(arr, mid + 1, right);
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), 234);

	int arr2[15] = { 34,53,1234,65,3765,734,3,636,2345,743,4756,2,567,456,235 };

	//srand(time(0));
	//for (auto& e : arr2)
	//{
	//	e = rand();
	//}

	for (auto& e : arr2)
	{
		cout << e << " ";
	}
	cout << endl;

	QuickSort(arr2, 0, (sizeof(arr2) / sizeof(arr2[0]))-1);

	for (auto& e : arr2)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}
