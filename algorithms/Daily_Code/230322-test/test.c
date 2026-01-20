#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
//int main()
//{
//
//	int* p = (int*)malloc(20);
//	if (p == NULL)
//	{
//		printf("%s", strerror(errno));
//
//		return 1;
//	}
//	//使用
//
//	int i = 0;
//	for (i = 0;i < 5;i++)
//	{
//		p[i] = i + 1;
//	}
//	for (i = 0;i < 5;i++)
//	{
//		printf("%d", p[i]);
//	}
//	//释放
//	free(p);
//	p = NULL;
//	return 0;
//}


//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		printf("calloc %s\n", strerror(errno));
//		return 1;
//	}
//	int i = 0;
//	for (i = 0;i < 10;i++)
//	{
//		printf("")
//	}
////	return 0;
////}
//
//int main()
//{
//	int* p = (int*)malloc(20);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	int i = 0;
//	for (i = 0;i < 5;i++)
//	{
//		p[i] = i + 1;
//	}
//	int* ptr=(int*)realloc(p,40);
//	if (ptr != NULL)
//	{
//		p = ptr;
//	}
//	for (i = 5;i < 10;i++)
//	{
//		p[i] = i + 1;
//	}
//	for (i = 0;i < 10;i++)
//	{
//		printf("%d ", p[i]);
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//
//	printf("%p\n", arr);
//	printf("%p\n", arr+1);
//	int* p1 = arr;
//	printf("%p\n", p1);
//	int(*p1)[10] = &arr;
//	printf("%p\n", p1);
//	printf("-----------------");
//	printf("%p\n", &arr);
//	printf("%p\n", (&arr)+1);
//	printf("%p\n", &arr[0]);
//	printf("%p\n", (&arr[0]) + 1);
//
//	//printf("%p", arr);
//	//printf("%p", arr);
//	//printf("%p", arr);
//
//
//	return 0;
//}


#include <stdio.h>
int main()
{
	int arr[10][10] = { 0 };
	printf("%p\n", arr);//单独出现的数组名表示数组首元素的地址
	printf("%p\n", arr+1);//数组名+1 跳过一个元素，因为二维数组的首元素是一个一维数组，所以它指向第二个一维数

	printf("%p\n", &arr);//取地址+数组名表示取出整个数组的地址
	printf("%p\n", (&arr)+1);//对整个数组的地址+1 表示跳过整个数组 指向数组后面的空间

	printf("%p\n", &arr[0]);//表示取出二维数组中第一个一维数组的地址
	printf("%p\n", (&arr[0]) + 1);//跳过一个一维数组，指向第二个一维数组

	printf("%p\n", &arr[0][0]);//取出二维数组第一个int类型数据的地址
	printf("%p\n", (&arr[0][0]) + 1);//跳过一个int 指向第二个int元素
	return 0;
}