#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	char a;
//	printf("输入被转化的小写字母:");
//	scanf("%c", &a);
//	a -= 32;
//	printf("%c", a);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int x;
//	printf("请输入一个四位数的整数：");
//	scanf("%d", &x);
//	printf("%d", (x % 10) + ((x / 10) % 10) + (x / 1000) + ((x / 100) % 10));
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	printf("今天是第%d周的星期%d", a / 7, a % 7);
//	return 0;
//
//}

//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	float a, b, c;
//	float p = 0;
//	float S, C;
//	printf("请输入三角形的三边长：");
//	scanf("%f %f %f", &a, &b, &c);
//	p = (a + b + c) / 2;
//	S = sqrt((p - a) * (p - b) * (p - c) * p);
//	C = a + b + c;
//	printf("周长为：%f，面积为：%f", C, S);
//	return 0;
//}


////鸡兔同笼
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
//	printf("鸡有%d只，兔有%d只", chick, (H - chick));
//	return 0;
//}

//#include <stdlib.h>
//#include <string.h>
//#include <stdio.h>
//
////qsort函数的使用者提供这个函数
//int cmp_int(const void* p1, const void* p2)
//{
//	return *(int*)p1 - *(int*)p2;
//}
//
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//test1()
//{
//	int arr[] = { 3,1,5,2,4,9,8,6,5,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//使用qsort来排序整型数组，这里就要提供一个比较函数，这个比较函数能够比较2个整数的大小
//	//qsort 默认是排成升序的
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	print_arr(arr, sz);
//}
//
////测试qsort 排序结构体数据
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
////按照年龄来比较
//int cmp_stu_by_age(const void* p1, const void* p2)
//{
//	return ((struct Stu*)p1)->age - ((struct Stu*)p2)->age;
//}
//
//int cmp_stu_by_name(const void* p1, const void* p2)
//{
//	return strcmp(((struct Stu*)p1)->name, ((struct Stu*)p2)->name);
//}
//
//void test2()
//{
//	struct Stu s[] = { {"zhangsan", 30}, {"lisi", 25}, {"wangwu", 50} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	//测试按照年龄来排序
//	//qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
//	//测试按照名字来排序
//	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
//}
//
//void Swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//
////假设排序为升序
////希望这个bubble_sort函数可以排序任意类型的数据
//void bubble_sort(void* base, size_t num, size_t width,
//	int (*cmp)(const void* p1, const void* p2))
//{
//	//要确定趟数
//	size_t i = 0;
//	for (i = 0; i < num - 1; i++)
//	{
//		int flag = 1;//假设已经有序了
//		//一趟冒泡排序的过程
//		size_t j = 0;
//		for (j = 0; j < num - 1 - i; j++)
//		{
//			//两个相邻的元素比较
//			//arr[j] arr[j+1]
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				//交换
//				flag = 0;
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}
//
//void test3()
//{
//	int arr[] = { 3,1,5,2,4,9,8,6,5,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	print_arr(arr, sz);
//}
//
//void test4()
//{
//	struct Stu s[] = { {"zhangsan", 30}, {"lisi", 25}, {"wangwu", 50} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	//测试按照年龄来排序
//	//bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
//	//测试按照名字来排序
//	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
//}
//int main()
//{
//	//test1();
//	//test2();
//	//test3();
//	test4();
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	//char* p = &a;//int*
//	void* p = &a;//void* - 无具体类型的指针，所以它可以接收任何类型的地址
//	//*p;//err,void*的指针不能解引用操作符
//	//p++;//err
//	*(int*)p;
//	return 0;
//}


#include <stdio.h>
int main()
{
	int a = 10;
	printf("%o", a);
	return 0;


}