#define _CRT_SECURE_NO_WARNINGS
//#define MAX(a,b)  (a>b)?(a):(b)
//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,45,234,2335,234,63,23,86,435,3523 };
//	int max = 0;
//	for (int i = 0;i < 9;i++)
//	{
//		max = MAX(arr[i], arr[i + 1]);
//	}
//	printf("最大数是：%d", max);
//	return 0;
//}

//#include <stdio.h>
//int isprime(int a,int* box)
//{
//	int count = 0;
//	for (int m = 1;m <= a;m++)
//	{
//		if (a % m == 0)
//		{
//			count++;
//		}
//	}
//	if (count == 2)
//	{
//		//for (int c = a;c < 100;c=c+a)
//		//{
//		//	box[c] = -1;
//		//}
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	int i = 0;
//	int arr[100] = { 0 };
//	for (i = 0;i < 100;i++)
//	{
//		arr[i] = i + 1;
//	}
//	for (i = 0; i < 100;i++)
//	{
//		if (arr[i] != -1)
//		{
//			if (!isprime(arr[i],arr))
//			{
//				arr[i] = -1;
//			}
//		}
//	}
//	printf("0~100的素数有：");
//	for (i = 0;i < 100;i++)
//	{
//		if (arr[i] != -1)
//		{
//			printf("%d ", arr[i]);
//		}
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int left = 0;
//	int right = (sizeof(arr) / sizeof(arr[0])) - 1;
//	while (left < right)
//	{
//		int tmp = arr[right];
//		arr[right] = arr[left];
//		arr[left] = tmp;
//		left++;
//		right--;
//	}
//	for (int i = 0;i < 10;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[10][10] = { 0 };
//	int i = 0, j = 0;
//	for (i = 0;i < 10;i++)
//	{
//		printf("请输入第%d行：", i + 1);
//		for (j = 0;j < 10;j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	int summain = 0, sumcount = 0, sum = 0;
//	for (i = 0;i < 10;i++)
//	{
//		summain += arr[i][i];
//	}
//	for (i = 0, j = 9;i < 10 && j >= 0;i++, j--)
//	{
//		sumcount += arr[i][j];
//	}
//	sum = sumcount + summain;
//	printf("\n主对角线元素和=%d\n", summain);
//	printf("副对角线元素和=%d\n", sumcount);
//	printf("总和=%d\n", sum);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//    char big[100] = { 0 };
//    char del[100] = { 0 };
//    int i = 0;
//    char a;
//    while ((a = getchar()) != '\0')
//    {
//        big[i] = a;
//        i++;
//    }
//    while ((a = getchar()) != '\0')
//    {
//        del[i] = a;
//        i++;
//    }
//    int lenb = strlen(big);
//    int lend = strlen(del);
//    for (i = 0;i < lenb;i++)
//    {
//        int count = 0;
//        for (int m = 0;m < lend;m++)
//        {
//            if (big[i] == del[m])
//            {
//                count++;
//            }
//        }
//        if (count == 0)
//        {
//            printf("%c", big[i]);
//        }
//    }
//    return 0;
//}

#include <stdio.h>
int main()
{
	printf("%d", printf("%d", printf("%d", 43)));
	return 0;
}