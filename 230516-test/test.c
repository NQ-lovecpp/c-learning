#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//#define N 4		//矩阵的阶数
//
//int LeadingDiagonal(int(*arr)[N])
//{
//	int sum = 0;
//	for (int i = 0;i < N;i++)
//	{
//		sum += (*arr)[i];
//		arr++;
//	}
//	return sum;
//}
//int main()
//{
//	int a[4][4]={ 1, 2, 3, 4,
//				  5, 6, 7, 8,
//				  9,10,11,12,
//				 13,14,15,16 };
//	printf("主对角线元素和 = %d", LeadingDiagonal(a));
//	return 0;
//}

//#include <stdio.h>
//#define COL 3		//行数=一维数组元素个数
//#define ROW 3		//列数
//
//void sum(int(*arr)[ROW], int* b)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0;i < COL;i++,arr++)
//	{
//		int sum = 0;
//		for (j = 0;j < ROW;j++)
//		{
//			sum += (*arr)[j];
//		}
//		b[i] = sum;
//	}
//}
//int main()
//{
//	int arr[COL][ROW] = { 1,2,3,4,5,6,7,8,9 };
//	int b[COL] = { 0 };
//	sum(arr, b);
//	for (int i = 0;i < COL;i++)
//	{
//		printf("%d ", b[i]);
//	}
//	return 0;
//}


//#include <stdio.h>
//float avg(int(*arr)[10])
//{
//	float sum = 0;
//	int len = sizeof(*arr) / sizeof(**arr);
//	for (int i = 0;i < len;i++)
//	{
//		sum += (*arr)[i];
//	}
//	return (sum / len);
//}
//int main()
//{
//	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("平均值 = %f", avg(&a));
//	return 0;
//}

#include <stdio.h>
int main()
{
	int src[3][3] = { 10,20,30,       //10 40 70
					  40,50,60,	      //20 50 80
					  70,80,90 };     //30 60 90
	int dest[3][3] = { 0 };
	int i, j;
	for (i = 0;i < 3;++i)
	{
		for (j = 0;j < 3;++j)
		{
			dest[i][j] = src[j][i];
		}
	}
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 3;j++)
		{
			printf("%d ", dest[i][j]);
		}
		printf("\n");
	}
	return 0;
}
