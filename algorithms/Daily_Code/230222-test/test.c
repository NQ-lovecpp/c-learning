#define _CRT_SECURE_NO_WARNINGS

//int main()
//{
//	char* arr[4];//指针数组
//	int arr[5];
//	int (*p)[5] = &arr;//数组指针
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr);
//	int(*p)[10];
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	return 0;
//}
#include <stdio.h>
void print1()
{

}
int main()
{
	int arr[3][5] = { 1,2,3,4,5,2,3,4,5,6,3,4,5,6,7 };
	printf(arr, 3, 5);
	return 0;
}