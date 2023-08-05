#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

void InsertSort(int* arr, int size);           //插入排序
void InsertSort2(int* arr, int size);          //二分法插入排序
void ShellSort(int* arr, int size);			   //希尔排序

void BubbleSort(int* a, int n);				   //冒泡排序
void SelectSort(int* a, int n);				   //选择排序

void HeapSort(int* a, int n);                  //堆排序

void QuickSort(int* a, int begin, int end);	   //快速排序递归法
void QuickSortNonR(int* a, int begin,int end); //快速排序非递归法

void MergeSort(int* a, int n);                 //归并排序递归法
void MergeSortNonR(int* arr, int size);		   //归并排序非递归法

void CountSort(int* a, int n);                 //计数排序

