#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int a;
//	printf("%d\n", sizeof(int));
//}
//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,3,4,5 };
//    short* p = (short*)arr;
//    int i = 0;
//    for (i = 0; i < 4; i++)
//    {
//        *(p + i) = 0;
//    }
//
//    for (i = 0; i < 5; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int a = 0x11223344;
//    char* pc = (char*)&a;
//    *pc = 0;
//    printf("%x\n", a);
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* parr = arr;
//	for (int i = 0;i < 10;i++)
//	{
//		printf("%d\n", *(parr + i));
//	}
//	return 0;
//}
//#include <stdio.h>
//void blankspace(unsigned int n)
//{
//	for (int i = 0;i < n;i++)
//	{
//		printf(" ");
//	}
//}
//void star(int n)
//{
//	for (int i = 0;i < n;i++)
//	{
//		printf("*");
//	}
//}
//int main()
//{
//	int m = 1;
//	for (int i = 0;i < 13;i++)
//	{
//		blankspace(abs(6 - i));
//		if (i < 6)
//		{
//			star(m);
//			m = m + 2;
//		}
//		else
//		{
//			star(m);
//			m = m - 2;
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	for (int i = 0;i < 10;i++)
//	{
//		if (i == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	for (int i = 10;i < 100;i++)
//	{
//		if (i == pow((i / 10), 2) + pow((i % 10), 2))
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	for (int i = 100;i < 1000;i++)
//	{
//		if (i == pow((i / 100), 3) + pow((i / 10) % 10, 3) + pow((i % 10), 3))
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	for (int i = 1000;i < 10000;i++)
//	{
//		if (i == pow((i / 1000), 4) + pow((i / 100) % 10, 4) + pow((i / 10) % 10, 4) + pow((i % 10), 4))
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	for (int i = 10000;i < 100000;i++)
//	{
//		if (i == pow((i / 10000), 5) + pow((i / 1000) % 10, 5) + pow((i / 100) % 10, 5) + pow((i / 10) % 10, 5)+pow((i % 10), 5))
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	return 0;
//}

#include <stdio.h>
int main()
{
	int a;
	scanf("%d", &a);
	int s = a + 11 * a + 111 * a + 1111 * a + 11111 * a;
	printf("%d\n", s);
	return 0;
}