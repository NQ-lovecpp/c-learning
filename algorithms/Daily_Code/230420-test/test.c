#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//void solve1(float a,float b,float c,float delta)
//{
//	printf("x1=%f	x2=%f", (-b + delta) / (2 * a), (-b - delta) / (2 * a));
//}
//void solve2(float a, float b, float c, float delta)
//{
//	printf("x1=%f	x2=%f", (-b) / (2 * a), (-b) / (2 * a));
//}
//void solve3(float a, float b, float c, float delta)
//{
//	printf("没有实数根");
//}
//int main()
//{
//	float a, b, c;
//	printf("请输入二元一次方程的三个系数：");
//	scanf("%f %f %f", &a, &b, &c);
//	float delta = (b * b - 4 * a * c);
//	if (delta > 0)
//	{
//		solve1(a,b,c,delta);
//	}
//	else if (delta == 0)
//	{
//		solve2(a, b, c, delta);
//	}
//	else if (delta < 0)
//	{
//		solve3(a, b, c, delta);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//void bubblesort(char* arr, int arrlen)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0;i < arrlen - 1;i++)
//	{
//		for (j = 0;j < arrlen - 1 - i;j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	char arr[100] = { 0 };
//	scanf("%s", arr);
//	int len = strlen(arr);
//	bubblesort(arr, len);
//	printf("排序后：\n");
//	for (int i = 0;i < len;i++)
//	{
//		printf("%c", arr[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//int max(int a, int b)
//{
//	return a > b ? a : b;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int M = 0;
//	for (int i = 0;i < 10;i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0;i < 9;i++)
//	{
//		M = max(arr[i], arr[i + 1]);
//	}
//	for (int i = 0;i < 10;i++)
//	{
//		if (arr[i] == M)
//			printf("最大数是%d,它是第%d个数", M, i + 1);
//	}
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[100] = { 0 };
//	scanf("%s", arr);
//	int left = 0;
//	int right = strlen(arr)-1;
//	while(left < right)
//	{
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//	printf("%s", arr);
//	return 0;
//}

#include <stdio.h>
void turn(int x)
{
	printf("%x", x);
}
int main()
{
	int x = 0;
	scanf("%d", &x);
	turn(x);
	return 0;
}