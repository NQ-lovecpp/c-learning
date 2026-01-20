#define I 3
#define J 3
#include <stdio.h>
int sumline(int* arr1, int* arr2, int len)
{
	int sum = 0;
	for (int i = 0;i < len;i++)
	{
		sum += (*arr1) * (*arr2);
		arr1++;
		arr2++;
	}
	return sum;
}
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
			dest[i][j] = sumline(src[i], src[j], 3);
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


//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int n = 0;
//	int n1 = 0;
//	int i = 0, j = 0;
//	int m = 0;
//	printf("Ҫ���뼸�����֣�");
//	scanf("%d", &n);
//	n1 = n;
//	int* arr = calloc(4, n);
//	int* dest = calloc(8, n);
//	printf("��������:");
//	for (int h = 0;h < n;h++)
//	{
//		scanf("%d", &arr[h]);
//	}
//	for (i = 0;i < n;i++)
//	{
//		dest[i] = arr[i];
//	}
//	for (j = 0;j < n;j++,i++)
//	{
//		dest[i] = arr[j];
//	}
//	printf("�ƶ���λ��");
//	scanf("%d", &m);
//	n1 = n1 - m;
//	printf("�ƶ�������ݣ�");
//	for (i = 0;i < n;i++)
//	{
//		printf("%d ", dest[n1]);
//		n1++;
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	switch (a)
//	{
//	case 0:
//		printf("zero");
//		break;
//	case 1:
//		printf("one");
//		break;
//	case 2:
//		printf("two");
//		break;
//	case 3:
//		printf("three");
//		break;
//	case 4:
//		printf("fout");
//		break;
//	case 5:
//		printf("five");
//		break;
//	case 6:
//		printf("six");
//		break;
//	case 7:
//		printf("seven");
//		break;
//	case 8:
//		printf("eight");
//		break;
//	case 9:
//		printf("nine");
//		break;
//	default:
//		break;
//	}
//	return 0;
//}

//
//#include <stdio.h>
//int IsLeapYear(int Y)
//{
//	if ((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int y = 0;
//	int m = 0;
//	int d = 0;
//	int sum = 0;
//	int monthLeap[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int monthNorm[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	printf("������ �� �գ�");
//	scanf("%d %d %d", &y, &m, &d);
//	if (IsLeapYear(y))
//	{
//		for (int i = 0;i < m - 1;i++)
//		{
//			sum += monthLeap[i];
//		}
//		sum += d;
//	}
//	else
//	{
//		for (int i = 0;i < m - 1;i++)
//		{
//			sum += monthNorm[i];
//		}
//		sum += d;
//	}
//	printf("�����ǣ�%d", sum);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int A[3][3];
//	int C[3][3];
//	int B[3][3];
//	int i, j;
//	for (i = 0;i < 3;i++)
//	{
//		for (j = 0;j < 3;j++)
//		{
//			cin >> A[i][j];
//		}
//	}
//	for (i = 0;i < 3;i++)
//	{
//		for (j = 0;j < 3;j++)
//		{
//			C[j][i] = A[i][j];
//		}
//	}
//	for (i = 0;i < 3;i++)
//	{
//		for (j = 0;j < 3;j++)
//		{
//			B[j][i] = A[i][j] + C[i][j];
//		}
//	}
//	for (i = 0;i < 3;i++)
//	{
//		for (j = 0;j < 3;j++)
//		{
//			cout << B[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}