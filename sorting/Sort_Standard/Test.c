#include "Sort.h"
#include "Stack.h"
#include <time.h>


void PrintArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void TestInsertSort()
{
	int UniArr[10] = { 4,7,1,9,3,6,5,8,3,2 };
	printf("InsertSort:\n");
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	InsertSort(UniArr, sizeof(UniArr) / sizeof(int));
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	printf("\n");
}

void TestInsertSort2()
{
	int UniArr[10] = { 4,7,1,9,3,6,5,8,3,2 };
	printf("InsertSort2:\n");
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	InsertSort2(UniArr, sizeof(UniArr) / sizeof(int));
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	printf("\n");
}

void TestShellSort()
{
	int UniArr[10] = { 4,7,1,9,3,6,5,8,3,2 };
	printf("ShellSort:\n");
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	ShellSort(UniArr, sizeof(UniArr) / sizeof(int));
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	printf("\n");
}

void TestBubbleSort()
{
	int UniArr[10] = { 4,7,1,9,3,6,5,8,3,2 };
	printf("BubbleSort:\n");
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	BubbleSort(UniArr, sizeof(UniArr) / sizeof(int));
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	printf("\n");
}

void TestSelectSort()
{
	int UniArr[10] = { 4,7,1,9,3,6,5,8,3,2 };
	printf("SelectSort:\n");
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	SelectSort(UniArr, sizeof(UniArr) / sizeof(int));
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	printf("\n");
}

void TestHeapSort()
{
	int UniArr[10] = { 4,7,1,9,3,6,5,8,3,2 };
	printf("HeapSort:\n");
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	HeapSort(UniArr, sizeof(UniArr) / sizeof(int));
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	printf("\n");
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

// 标准库中的快速排序qsort
void Testqsort()
{
	int UniArr[10] = { 4,7,1,9,3,6,5,8,3,2 };
	printf("qsort:\n");
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	qsort(UniArr, sizeof(UniArr) / sizeof(int), sizeof(int), compar);
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	printf("\n");
}

void TestQuickSort()
{
	int UniArr[10] = { 4,7,1,9,3,6,5,8,3,2 };
	printf("QuickSort:\n");
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	QuickSort(UniArr, 0, (sizeof(UniArr) / sizeof(int)) - 1);
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	printf("\n");
}

void TestQuickSortNonR()
{
	int UniArr[10] = { 4,7,1,9,3,6,5,8,3,2 };
	printf("QuickSortNonR:\n");
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	QuickSortNonR(UniArr, 0, (sizeof(UniArr) / sizeof(int)) - 1);
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	printf("\n");
}

void TestMergeSort()
{
	int UniArr[10] = { 4,7,1,9,3,6,5,8,3,2 };
	printf("MergeSort:\n");
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	MergeSort(UniArr, (sizeof(UniArr) / sizeof(int)));
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	printf("\n");
}

void TestMergeSortNonR()
{
	int UniArr[10] = { 4,7,1,9,3,6,5,8,3,2 };
	printf("MergeSortNonR:\n");
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	MergeSortNonR(UniArr, (sizeof(UniArr) / sizeof(int)));
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	printf("\n");
}

void TestCountSort()
{
	int UniArr[10] = { 4,7,1,9,3,6,5,8,3,2 };
	printf("CountSort:\n");
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
	CountSort(UniArr, (sizeof(UniArr) / sizeof(int)));
	PrintArray(UniArr, sizeof(UniArr) / sizeof(int));
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
	TestInsertSort();
	TestInsertSort2();
	TestShellSort();

	TestBubbleSort();
	TestSelectSort();
	TestHeapSort();
	
	TestQuickSort();
	TestQuickSortNonR();

	TestMergeSort();
	TestMergeSortNonR();

	TestCountSort();

	//TestOP();

	return 0;
}



