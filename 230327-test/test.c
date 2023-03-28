#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//union Un
//{
//	short s[7];
//	int n;
//};
//int main()
//{
//	printf("%d\n", (int)sizeof(union Un));
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//int main()
//{
//	char arr[1000] = { 0 };
//	gets(arr);
//	int len = strlen(arr);
//	int alpha = 0, num = 0, blank = 0, others = 0;
//	for (int i = 0;i < len;i++)
//	{
//		if (isalpha(arr[i]))
//			alpha++;
//		else if (isdigit(arr[i]))
//			num++;
//		else if (arr[i] == ' ')
//			blank++;
//		else
//			others++;
//	}
//	printf("字符个数：%d	数字个数：%d	空格个数：%d	其他字符：%d", alpha, num, blank, others);
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int ch = 0, num = 0, i = 0, j = 0, n = 0;
//	printf("请输入一段字符：");
//	char a;
//	while ((a = getchar()) != '\n')
//	{
//		if (isdigit(a))
//			num++;
//		else if (a <= 'z' && a >= 'a')
//			ch++;
//		else if (a <= 'Z' && a >= 'A')
//			ch++;
//		else if (a = ' ')
//			j++;
//		else
//			n++;
//	}
//	printf("字母个数：%d\n", ch);
//	printf("数字个数：%d\n", num);
//	printf("空格个数：%d\n", j);
//	printf("其他字符个数：%d\n", n);
//	return 0;
//}


//#include <stdio.h>
//
//int once(int* arr, int num, int len) {
//    int count = 0;
//    for (int m = 0; m < len; m++) {
//        if (arr[m] == num) {
//            count++;
//        }
//    }
//    if (count == 1)
//        return 1;
//    else
//        return 0;
//}
//
//int main() 
//{
//    int arr[1000] = { 0 };
//    int i = 0, j = 0;
//    int num;
////
////    // 使用scanf的返回值检查是否成功读取整数
////    while (scanf("%d", &num) == 1) 
////    {
////        printf("请输入一个整数:");
////        arr[i] = num;
////        i++; // 递增i
////    }
////
////    for (j = 0; j < i; j++) {
////        if (once(arr, arr[j], i))
////            printf("%d ", arr[j]);
////    }
////    return 0;
////}
//
//#include <stdio.h>
//
//int once(int* arr, int num, int len) 
//{
//    int count = 0;
//    for (int m = 0; m < len; m++) 
//    {
//        if (arr[m] == num) 
//        {
//            count++;
//        }
//    }
//    if (count == 1)
//        return 1;
//    else
//        return 0;
//}
//
//int main() 
//{
//    int arr[1000] = { 0 };
//    int n, i, j;
//    int num;
//
//    printf("输入数组长度：");
//    scanf("%d", &n);
//
//    printf("输入数组元素：");
//    for (i = 0; i < n; i++) 
//    {
//        scanf("%d", &arr[i]);
//    }
//
//    for (j = 0; j < n; j++) 
//    {
//        if (once(arr, arr[j], n))
////            printf("%d ", arr[j]);
////    }
////    return 0;
////}
//
//
//#define N 60
//#define PAI 3.1415926
//#include <stdio.h>
//#include <math.h>
//double fac(int num)
//{
//	double s = 1;
//	for (int i = 1;i <= num;i++)
//	{
//		s *= i;
//	}
//	return s;
//}
//int main()
//{
//	double sum = 1;
//	int i = 1;
//	double x = 0;
//	scanf("%lf", &x);
//	x = x * (PAI / 180);
//	for (i = 1;i <= N;i++)
//	{
//		sum += (pow(-1, i) * (pow(x, 2 * (i + 1) - 2) / fac(2 * (i + 1) - 2)));
//	}
//	printf("cos(x)=%f", sum);
//	return 0;
//}


//#include <stdio.h>
//int main() 
//{
//    int num, digit1, digit2, digit3;
//
//    for (num = 100; num <= 999; num++) 
//    {
//        digit1 = num / 100; // 获取百位数字
//        digit2 = (num / 10) % 10; // 获取十位数字
//        digit3 = num % 10; // 获取个位数字
//
//        if (num == digit1 * digit1 * digit1 + digit2 * digit2 * digit2 + digit3 * digit3 * digit3) 
//        {
//            printf("%d  ", num);
//        }
//    }
//
//    return 0;
//}
//


#include <stdio.h>
int isprime(int num)
{
	int count = 0;
	for (int m = 1;m <= num;m++)
	{
		if (num % m == 0)
		{
			count++;
		}
	}
	if (count == 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	for (int i = 100;i < 201;i++)
	{
		if (isprime(i))
		{
			printf("%d	", i);
		}
	}
	return 0;
}