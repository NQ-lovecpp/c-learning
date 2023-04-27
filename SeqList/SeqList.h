#pragma once
#include <stdio.h>
#include <stdlib.h>
////静态顺序表
////给小了不够用，给多了浪费
//#define N 10
//typedef int SLDataType;
//
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};

typedef int SLDatatype;
typedef struct SeqList
{
	SLDatatype* a;
	int size;     //存储的有效数据个数
	int capacity;  //容量
}SL;

void SLPrint(SL* ps1);
void SLInit(SL* ps1);
void SLDestroy(SL* ps1);
void SLPushBack(SL* ps1, SLDatatype x);
void SLPushFront(SL* ps1, SLDatatype x);
void SLPopBack(SL* ps1);
void SLPopFront(SL* ps1);






//void SeqListInit(SeqList* psl);
//// 检查空间，如果满了，进行增容
//void CheckCapacity(SeqList* psl);
//// 顺序表尾插
//void SeqListPushBack(SeqList* psl, SLDataType x);
//// 顺序表尾删
//void SeqListPopBack(SeqList* psl);
//// 顺序表头插
//void SeqListPushFront(SeqList* psl, SLDataType x);