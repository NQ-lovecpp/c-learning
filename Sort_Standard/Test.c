#include "Sort.h"
#include "Stack.h"
#include <time.h>

void PrintArray(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void TestInsertSort()
{
	printf("InsertSort:\n");
	int a[] = { 4,7,1,9,3,6,5,8,3,2,0 };
	PrintArray(a, sizeof(a) / sizeof(int));
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestInsertSort2()
{
	printf("InsertSort2:\n");
	int a[] = { 4,7,1,9,3,6,5,8,3,2,0 };
	PrintArray(a, sizeof(a) / sizeof(int));
	InsertSort2(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
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
	printf("SelectSort:\n");
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
	qsort(a, sizeof(a) / sizeof(int), sizeof(int), compar);
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

void TestQuickSort()
{
	printf("QuickSort:\n");
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };
	PrintArray(a, sizeof(a) / sizeof(int));
	//QuickSort(a, 0, (sizeof(a) / sizeof(int)) - 1);
	QuickSortNonR(a, 0, (sizeof(a) / sizeof(int)) - 1);
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
	BubbleSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	SelectSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort(a5,0, N);
	int end5 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("BubbleSort:%d\n", end3 - begin3);
	printf("SelcetSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}

int main()
{
	//TestInsertSort();
	//TestInsertSort2();
	//TestShellSort();

	TestBubbleSort();
	TestSelectSort();

	//TestQuickSort();
	//TestCountSort();

	//TestOP();

	return 0;
}