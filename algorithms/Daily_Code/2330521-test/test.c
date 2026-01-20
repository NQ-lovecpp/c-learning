#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"

int main()
{
	HP hp;
	HeapInit(&hp);
	int a[] = { 65,100,70,32,50,60 };
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		HeapPush(&hp, a[i]);
	}

	//// 10:42继续
	//while (!HeapEmpty(&hp))
	//{
	//	int top = HeapTop(&hp);
	//	printf("%d\n", top);
	//	HeapPop(&hp);
	//}

	return 0;
}

// 可以这么玩吗？--可以
// 弊端：1、先有一个堆,太麻烦。2、空间复杂度+拷贝数据
//void HeapSort(int* a, int n)
//{
//	HP hp;
//	HeapInit(&hp);
//	// N*logN
//	for (int i = 0; i < n; ++i)
//	{
//		HeapPush(&hp, a[i]);
//	}
//
//	// N*logN
//	int i = 0;
//	while (!HeapEmpty(&hp))
//	{
//		int top = HeapTop(&hp);
//		a[i++] = top;
//		HeapPop(&hp);
//	}
//
//	HeapDestroy(&hp);
//}

// O(N*logN)
//void HeapSort(int* a, int n)
//{
//	// 升序 -- 建大堆
//	// 降序 -- 建小堆
//
//
//	// 建堆--向上调整建堆
//	/*for (int i = 1; i < n; i++)
//	{
//		AdjustUp(a, i);
//	}*/
//
//	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(a, n, i);
//	}
//
//	// N*logN
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//
//		// 再调整，选出次小的数
//		AdjustDown(a, end, 0);
//
//		--end;
//	}
//}
//
//int main()
//{
//	int a[] = { 7,8,3,5,1,9,5,4 };
//	HeapSort(a, sizeof(a) / sizeof(int));
//
//	return 0;
//}