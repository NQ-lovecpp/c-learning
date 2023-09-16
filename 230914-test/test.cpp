//#include <iostream>
//#include <utility>
//using namespace std;
//
//void PrintArr(int* arr, int size)
//{
//	for (int i = 0;i < size;i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
//void SelectSort(int* arr, int size)
//{
//	int begin = 0, end = size - 1;
//	while (begin < end)
//	{
//		int maxi = begin, mini = begin;
//		for (int i = begin; i <= end; i++)
//		{
//			if (arr[i] > arr[maxi])
//			{
//				maxi = i;
//			}
//
//			if (arr[i] < arr[mini])
//			{
//				mini = i;
//			}
//		}
//
//		swap(arr[begin], arr[mini]);
//		// 如果maxi和begin重叠，修正一下即可
//		if (begin == maxi)
//		{
//			maxi = mini;
//		}
//
//		swap(arr[end], arr[maxi]);
//
//		++begin;
//		--end;
//	}
//}
//
//int main()
//{
//	int arr[10] = { 4,9,1,2,3,7,0,5,8,6 };
//	int size = sizeof(arr) / sizeof(int);
//	PrintArr(arr, size);
//	SelectSort(arr, size);
//	PrintArr(arr, size);
//	return 0;
//}

#include<iostream>
using namespace std;
void array_(int a[], int n);
int main()
{
	int n, i;
	cin >> n;
	int* a = new int[n];
	for (i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	array_(a, n);
	for (i = 0;i < n;i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}

void array_(int a[], int n)
{
	int i = 0, j = 0;
	for (i = 0;i < n;i++)
	{
		for (j = i + 1;j < n;j++)
		{
			if (a[j] < a[i])
			{
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}