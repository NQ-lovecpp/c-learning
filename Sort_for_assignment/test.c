// test.c

#include "Sort.h"
#include <time.h>

void TestSortTime()
{
	int array_size[6] = { 100, 1000, 5000, 10000, 50000, 100000 }; // 规模
	for (int _i = 0; _i < 6; _i++)
	{
		int N = array_size[_i];
		printf("当前数据规模：%d\n", N);

		int* a1 = (int*)malloc(sizeof(int) * N);
		int* a2 = (int*)malloc(sizeof(int) * N);
		int* a3 = (int*)malloc(sizeof(int) * N);
		int* a4 = (int*)malloc(sizeof(int) * N);

		// 造随机数
		srand(time(0));
		for (int i = 0; i < N; ++i)
		{
			a1[i] = rand();
			a2[i] = a1[i];
			a3[i] = a1[i];
			a4[i] = a1[i];
		}

		int begin1 = clock();
		InsertSort(a1, N);
		int end1 = clock();

		int begin2 = clock();
		MergeSort(a2, N);
		int end2 = clock();

		int begin3 = clock();
		QuickSort(a3, 0, N - 1);
		int end3 = clock();

		int begin4 = clock();
		HeapSort(a4, N);
		int end4 = clock();

		printf("InsertSort:	%d\n", end1 - begin1);
		printf("MergeSort:	%d\n", end2 - begin2);
		printf("QuickSort:	%d\n", end3 - begin3);
		printf("HeapSort:	%d\n", end4 - begin4);

		free(a1);
		free(a2);
		free(a3);
		free(a4);

		printf("----------------------\n");
	}
}

int main()
{
	TestSortTime();
	return 0;
}



