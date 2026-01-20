#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int* closest_sum(int arr[], int n, int sum) 
//{
//    int min_diff = INT_MAX;  // 最小差值
//    int* res = (int*)malloc(sizeof(int) * 2);  // 存放结果的数组
//    int i = 0, j = n - 1;
//
//    while (i < j) 
//    {
//        int cur_sum = arr[i] + arr[j];  // 当前和
//        int cur_diff = abs(cur_sum - sum);  // 当前差值
//
//        // 如果当前差值比已知的最小差值更小，则更新最小差值和结果数组
//        if (cur_diff < min_diff) 
//        {
//            min_diff = cur_diff;
//            res[0] = arr[i];
//            res[1] = arr[j];
//        }
//
//        // 根据当前和与 sum 的大小关系移动指针
//        if (cur_sum < sum) 
//        {
//            i++;
//        }
//        else 
//        {
//            j--;
//        }
//    }
//
//    return res;
//}
//
//int main() 
//{
//    int arr[] = { -5, -2, 0, 2, 5, 8, 10, 13 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    int sum = 6;
//    int* res = closest_sum(arr, n, sum);
//
//    printf("The closest sum to %d is %d + %d = %d\n", sum, res[0], res[1], res[0] + res[1]);
//
//    free(res);
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int* move(int* arr, int m, int len)
//{
//	return (arr + len - m);
//}
//int main()
//{
//	int n = 0, m = 0;
//	int i = 0, j = 0;
//	printf("输入几个数？");
//	scanf("%d", &n);
//	printf("移动多少位？");
//	scanf("%d", &m);
//	int* arr = (int*)calloc(2 * n, sizeof(int));
//	for (i = 0;i < n;i++)
//	{
//		printf("输入第%d个数：", i);
//		scanf("%d", &arr[i]);
//	}
//	for (j = 0;j < n;i++, j++)
//	{
//		arr[i] = arr[j];
//	}
//	int* start = move(arr, m, n);
//	for (i = 0;i < n;i++)
//	{
//		printf("%d ", *start);
//		start++;
//	}
//	free(arr);
//	arr = NULL;
//	return 0;
//}


#include <stdio.h>
int gcd(int big,int small)
{
	if (big < small)
	{
		int tmp = small;
		small = big;
		big = tmp;
	}
	for (int i = small;i >= 1;i--)
	{
		if (big % i == 0 && small % i == 0)
		{
			return i;
		}
	}
}
int main()
{
	int a = 0, b = 0;
	printf("输入分子和分母:");
	scanf("%d %d", &a, &b);
	int n = gcd(a, b);
	a /= n, b /= n;
	printf("%d\n—\n", a);
	printf("%d", b);

	return 0;
}