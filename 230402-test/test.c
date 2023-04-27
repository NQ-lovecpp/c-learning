#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int arr[10] = {75,54,45,34,76,21,53,41,96,44 };
//	升序
//	int i = 0;
//	int j = 9;
//	for (j = 9;j > 0;j--)
//	{
//		for (i = 0;i < j;i++)
//		{
//			if (arr[i] > arr[i + 1])
//			{
//				int tmp = arr[i + 1];
//				arr[i + 1] = arr[i];
//				arr[i] = tmp;
//			}
//		}
//	}
//	for (int m = 0;m < 10;m++)
//	{
//		printf("%d ", arr[m]);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//int main()
//{
//	int i = 0;
//	char arr[100] = { 0 };
//	printf("输入密码：");
//	scanf("%s", &arr);
//	int len = strlen(arr);
//	for (i = 0;i < len;i++)
//	{
//		if (isalpha(arr[i]) == 0)
//		{
//			continue;
//		}
//		else
//		{
//			if (isupper(arr[i]))
//			{
//				int num = (int)arr[i] - 'A' + 1;
//				arr[i] = 'A' + 26 - num;
//			}
//			else if (islower(arr[i]))
//			{
//				int num = (int)arr[i] - 'a' + 1;
//				arr[i] = 'a' + 26 - num;
//			}
//		}
//	}
//	printf("  原文是：%s",arr);
//	return 0;
//}

#include <stdio.h>
#include <string.h>

void exchange(char* arr1, char* arr2)
{
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	int len = len1 > len2 ? len1 : len2;
	for (int i = 0;i < len;i++,arr1++,arr2++)
	{
		char tmp = *arr2;
		*arr2 = *arr1;
		*arr1 = tmp;
	}
}
int main()
{
	char name[50][50] = { 0 };
	int num = 0;

	//输入
	printf("输入学生人数：");
	scanf("%d", &num);
	for (int i = 0;i < num;i++)
	{
		printf("输入第%d学生姓名：", i + 1);
		scanf("%s", name[i]);
	}

	//排序
	//升序排列（a~z）
	int i = 0;
	int j = 0;
	for (j = num-1;j > 0;j--)
	{
		for (i = 0;i < j;i++)
		{
			if (strcmp(name[i],name[i+1])>0)
			{
				exchange(name[i], name[i + 1]);
			}
		}
	}

	//打印排序后的名单
	printf("\n排序后的学生名单：\n");
	for (int m = 0;m < num;m++)
	{
		printf("%d. %s\n", m + 1, name[m]);
	}

	//找人
	printf("\n你要找谁？");
	char box[50] = { 0 };
	scanf("%s", box);
	for (int m = 0;m < num;m++)
	{
		if (strcmp(box, name[m]) == 0)
		{
			printf("找到了，他是排序后的第%d人", m + 1);
		}
	}
	return 0;
}