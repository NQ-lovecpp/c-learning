#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	float max;
//	float arr[2] = { 0 };
//	scanf("%f %f %f", &max, &arr[0], &arr[1]);
//	for (int i = 0;i < 2;i++)
//	{
//		if (max <= arr[i])
//		{
//			max = arr[i];
//		}
//	}
//	printf("Max:%f", max);
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int y;
//	scanf("%d", &y);
//	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
//	{
//		printf("是闰年");
//	}
//	else
//	{
//		printf("不是闰年");
//	}
//	return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//	int a;
//	int arr[3] = { 0 };
//	scanf("%d", &a);
//	if (a / 100 != 0)
//	{
//		printf("三位数\n");
//	}
//	else if (a / 10!=0)
//	{
//		printf("两位数\n");
//	}
//	else
//	{
//		printf("一位数\n");
//	}
//	arr[2] = a / 100;
//	arr[1] = (a / 10) % 10;
//	arr[0] = a % 10;
//	printf("正序：");
//	for (int i = 2;i >= 0;i--)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n逆序：");
//	for (int i = 0;i < 3;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	switch (a / 10)
//	{
//	case 10:
//	case 9:
//		printf("优");
//		break;
//	case 8:
//		printf("良");
//		break;
//	case 7:
//		printf("中");
//		break;
//	case 6:
//		printf("差");
//		break;
//	default:
//		printf("不及格");
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arrs[3] = { 0 };
//	for (int i = 0;i < 3;i++)
//	{
//		scanf("%d", &arrs[i]);
//	}
//	for (int m = 0;m < 2;m++)
//	{
//		for (int i = 0;i < 2;i++)
//		{
//			if (arrs[i] < arrs[i + 1])
//			{
//				int tmp;
//				tmp = arrs[i];
//				arrs[i] = arrs[i + 1];
//				arrs[i + 1] = tmp;
//			}
//		}
//	}
//	for (int i = 0;i < 3;i++)
//	{
//		printf("%d ", arrs[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	float a, b;
//	char fun;
//	while (scanf("%f %c %f", &a, &fun, &b)!=EOF)
//	{
//		switch (fun)
//		{
//		case '+':
//			printf("结果是：%f\n", a + b);
//			break;
//		case '-':
//			printf("结果是：%f\n", a - b);
//			break;
//		case '*':
//			printf("结果是：%f\n", a * b);
//			break;
//		case '/':
//			printf("结果是：%f\n", a / b);
//			break;
//		default:
//			printf("输入有误，重新输入：");
//		}
//	}
//	return 0;
//}

