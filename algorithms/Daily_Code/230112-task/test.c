#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//void formula(int a)
//{
//	int i, m;
//	for (i = 1; i <= a; i++)
//	{
//		for (m = 1;m <= a; m++)
//		{
//			printf("%d*%d=%d	", i, m, i * m);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int h = 0;
//	printf("几阶乘法口诀表？");
//	scanf("%d", &h);
//	formula(h);
//}

//int main()
//{
//	int a = 10;
//	int i, m;
//	for (i = 1; i <= a; i++)
//	{
//		for (m = 1;m <= a; m++)
//		{
//			printf("%d*%d=%d	", i, m, i * m);
//		}
//		printf("\n");
//	}
//}

#include <stdio.h>
int change(int* a, int* b)
{
	int box;
	box = *b;
	*b = *a;
	*a = box;
}


int main()
{
	int m = 10;
	int n = 20;
	printf("交换前:%d %d\n", m, n);
	change(&m, &n);
	printf("交换后:%d %d", m, n);
}