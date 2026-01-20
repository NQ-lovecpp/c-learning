#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//void exchange(char* arr1,char* arr2,int n)
//{
//	char arrb[100];
//	int i = 0;
//	for (i = 0; i < n - 1; i++)
//	{
//		arrb[i] = *(arr1+i);
//		*(arr1+i) = *(arr2+i);
//		*(arr2+i) = arrb[i];
//	}
//}
//int main()
//{
//	int n = 0;
//	char arr1[] = "hello";
//	char arr2[] = "nihao";
//	n = strlen(arr1);
//	printf("交换前：%s  %s\n", arr1, arr2);
//	char* a1 = &arr1;
//	char* a2 = &arr2;
//	exchange(a1, a2, n);
//	printf("交换后：%s  %s", arr1, arr2);
//}

#include <stdio.h>
void init(int* arr,int size)
{
	int i;
	for (i = 0;i < size;i++)
	{
		*(arr + i) = 0;
	}
}

void print(int* arr,int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", *(arr+i));
	}
	printf("\n");
}
void reverse(int* arr,int size)
{
	int box;
	int left = 0;
	int right = size - 1;
	while (right - left != -1 && right - left != 0)
	{
		box = *(arr + left);
		*(arr + left) = *(arr + right);
		*(arr + right) = box;
		left++;
		right--;
	}
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int* a = &arr;

	printf("原数组：");
	print(a, size);
	init(a, size);
	printf("复位后：");
	print(a, size);
	
	int new[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* b = &new;
	reverse(b, size);
	printf("逆置后：");
	print(b, size);

	return 0;
}