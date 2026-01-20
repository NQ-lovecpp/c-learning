#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void AdjustUp(HPDataType* a, int child);
void AdjustDown(int* a, int n, int parent);

void Swap(HPDataType* p1, HPDataType* p2);

void HeapInit(HP* php);
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php);
HPDataType HeapTop(HP* php);//É¾³ý¶Ñ¶¥ÔªËØ
bool HeapEmpty(HP* php);
int HeapSize(HP* php);

