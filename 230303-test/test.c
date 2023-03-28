#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	//二维数组
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));//48 - a这个二维数组名单独放在sizeof内部
//	printf("%d\n", sizeof(a[0][0]));//4 - 第一个元素放在sizeof内部
//	printf("%d\n", sizeof(a[0]));//16 - a[0]是第一行的数组名
//	printf("%d\n", sizeof(a[0] + 1));//4 - 第一行数组名不是单独放在sizeof内部，a[0]表示首元素地址，加一就是第一行第二个元素的地址
//	printf("%d\n", sizeof(*(a[0] + 1)));//4 - 第一行第二个元素
//	printf("%d\n", sizeof(a + 1));//4 - a没有单独放在sizeof内部，所以是二维数组的首元素地址，二维数组首元素是第一行的一维数组，+1跳过一行
//	printf("%d\n", sizeof(*(a + 1)));//16 - 二维数组第二行的数组，有四个元素
//	printf("%d\n", sizeof(&a[0] + 1));//4 - 第一行地址+1就是第二行地址
//	printf("%d\n", sizeof(*(&a[0] + 1)));//16 - 第二行
//	printf("%d\n", sizeof(*a));//16
//	printf("%d\n", sizeof(a[3]));//16
//
//
//	//字符数组
//	//char arr[] = { 'a','b','c','d','e','f' };
//	//printf("%d\n", sizeof(char));
//	//printf("%d\n", sizeof(arr));
//	//printf("%d\n", sizeof(arr + 0));
//	//printf("%d\n", sizeof(*arr));
//	//printf("%d\n", sizeof(arr[1]));
//	//printf("%d\n", sizeof(&arr));
//	//printf("%d\n", sizeof(&arr + 1));
//	//printf("%d\n", sizeof(&arr[0] + 1));
//
//	//int a[] = { 1,2,3,4 };
//	//printf("%d\n", sizeof(int));
//	//printf("%d\n", sizeof(a));
//	//printf("%d\n", sizeof(a + 0));
//	//printf("%d\n", sizeof(*a));
//	//printf("%d\n", sizeof(a + 1));
//	//printf("%d\n", sizeof(a[1]));
//	//printf("%d\n", sizeof(&a));
//	//printf("%d\n", sizeof(*&a));
//	//printf("%d\n", sizeof(&a + 1));
//	//printf("%d\n", sizeof(&a[0]));
//	//printf("%d\n", sizeof(&a[0] + 1));
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int H, F;
//	int chick = 0;
//	scanf("%d %d", &H, &F);
//	for (chick = 1;chick <= H;chick++)
//	{
//		if (chick * 2 + (H - chick) * 4 == F)
//		{
//			break;
//		}
//	}
//	if ((H - chick) == -1)
//	{
//		printf("无解");
//	}
//	else
//	{
//		printf("鸡有%d只，兔有%d只", chick, (H - chick));
//	}
//	return 0;
//}

#include <stdio.h>
int main()
{
	int max;
	int cmp[3] = { 0 };
	for (int i = 0;i < 3;i++)
	{
		scanf("")
	}
	for (int i = 0;i < 3;i++)
	{
		if ()
	}
	return 0;
}