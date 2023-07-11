#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//#include <time.h>
//typedef int HPDataType;
//typedef struct Heap
//{
//	HPDataType* a;
//	int size;
//	int capacity;
//}HP;
//
//void AdjustUp(HPDataType* a, int child);
//void AdjustDown(int* a, int n, int parent);
//
//void Swap(HPDataType* p1, HPDataType* p2);
//
//void HeapInit(HP* php);
//void HeapDestroy(HP* php);
//void HeapPush(HP* php, HPDataType x);
//void HeapPop(HP* php);
//HPDataType HeapTop(HP* php);//删除堆顶元素
//bool HeapEmpty(HP* php);
//int HeapSize(HP* php);
//
//void HeapInit(HP* php)
//{
//	assert(php);
//	php->a = NULL;
//	php->size = 0;
//	php->capacity = 4;
//	php->a = (HPDataType*)malloc(php->capacity * sizeof(HPDataType));
//}
//
//void HeapDestroy(HP* php)
//{
//	assert(php);
//
//	free(php->a);
//	php->a = NULL;
//	php->capacity = php->capacity = 0;
//}
//
//
//
//
//// logN
//void HeapPush(HP* php, HPDataType x)
//{
//	assert(php);
//
//	if (php->size == php->capacity)
//	{
//		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
//		HPDataType* tmp = (HPDataType*)realloc(php->a, newCapacity * sizeof(HPDataType));
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			return;
//		}
//
//		php->a = tmp;
//		php->capacity = newCapacity;
//	}
//
//	php->a[php->size] = x;
//	php->size++;
//
//	AdjustUp(php->a, php->size - 1);
//}
//
//// logN
//void HeapPop(HP* php)//删除的是堆顶元素
//{
//	assert(php);
//	assert(!HeapEmpty(php));
//
//	Swap(&php->a[0], &php->a[php->size - 1]);
//	php->size--;
//
//	AdjustDown(php->a, php->size, 0);
//}
//
//HPDataType HeapTop(HP* php)
//{
//	assert(php);
//	assert(!HeapEmpty(php));
//
//	return php->a[0];
//}
//
////
//bool HeapEmpty(HP* php)
//{
//	assert(php);
//
//	return php->size == 0;
//}
//
//int HeapSize(HP* php)
//{
//	assert(php);
//
//	return php->size;
//}
//
//void Swap(HPDataType* p1, HPDataType* p2)
//{
//	HPDataType tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//void AdjustUp(HPDataType* a, int child)
//{
//	int parent = (child - 1) / 2;
//	//while (parent >= 0)
//	while (child > 0)
//	{
//		if (a[child] < a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//void AdjustDown(int* a, int n, int parent)//可以建小堆，因为小的放上面了
//{
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		if (child + 1 < n
//			&& a[child + 1] < a[child])
//		{
//			++child;
//		}
//
//		if (a[child] < a[parent])
//		{
//			Swap(&a[parent], &a[child]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}

#include <stdio.h>

void Swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void AdjustUp(int* a, int child)
{
    int parent = (child - 1) / 2;
    while (child > 0)
    {
        if (a[child] > a[parent])
        {
            Swap(&a[child], &a[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }
        else
        {
            break;
        }
    }
}

void AdjustDown(int* a, int n, int parent)
{
    int child = parent * 2 + 1;
    while (child < n)
    {
        if (child + 1 < n && a[child + 1] > a[child])
        {
            ++child;
        }

        if (a[child] > a[parent])
        {
            Swap(&a[parent], &a[child]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

void HeapSortAsc(int* a, int n)
{
    // 构建最大堆
    for (int i = (n - 2) / 2; i >= 0; --i)
    {
        AdjustDown(a, n, i);
    }

    // 逐步取出最大值，放置在数组末尾
    for (int i = n - 1; i > 0; --i)
    {
        Swap(&a[0], &a[i]);
        AdjustDown(a, i, 0);
}

void HeapSortDesc(int* a, int n)
{
    // 构建最小堆
    for (int i = (n - 2) / 2; i >= 0; --i)
    {
        AdjustUp(a, i);
    }

    // 逐步取出最小值，放置在数组末尾
    for (int i = n - 1; i > 0; --i)
    {
        Swap(&a[0], &a[i]);
        AdjustUp(a, i);
    }
}

int main()
{
    int arr[10] = { 65,49,76,32,85,42,72,50,99,20 };

    // 升序排序
    HeapSortAsc(arr, 10);
    printf("升序排序结果：");
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 降序排序
    HeapSortDesc(arr, 10);
    printf("降序排序结果：");
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
