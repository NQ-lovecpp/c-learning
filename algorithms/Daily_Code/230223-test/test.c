#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//    char str1[] = "hello bit.";
//    char str2[] = "hello bit.";
//    char* str3 = "hello bit.";
//    char* str4 = "hello bit.";
//    if (str1 == str2)
//        printf("str1 and str2 are same\n");
//    else
//        printf("str1 and str2 are not same\n");
//
//    if (str3 == str4)
//        printf("str3 and str4 are same\n");
//    else
//        printf("str3 and str4 are not same\n");
//
//    return 0;
//}
//#define num 100
//#include <stdio.h>
//void leftreverse(char letter[],int add,int len)
//{
//	int box[num] = { 0 };
//	int start = 0;
//	int j = 0;
//	char new[10] = { 0 };
//	for (int i = 0;i < num;)
//	{
//		for (j = 0;j < 4;j++)
//		{
//			box[i] = j;
//			i++;
//		}
//	}
//	start += add;
//	for (int m = 0;m < len; m++)
//	{
//		new[m] = letter[box[start]];
//		start++;
//	}
//	printf("%s", new);
//
//}
//int main()
//{
//	char a[4] = "ABCD";
//	leftreverse(a, 2, 4);
//	return 0;
//}
//#define row 10
//#define col 10
//#include <stdio.h>
//int main()
//{
//	//int row = 0;//hang
//	//int col = 0;//lie
//	//printf("输入行和列：");
//	//scanf("%d %d", &row, &col);
//	int square[row][col] = { 0 };
//	int j = 0;
//	int start = 0;
//	int find = 0;
//	int flag = 0;
//	for (int i = 0;i < 10;i++)
//	{
//		for (j = 0;j < 10;j++)
//		{
//			square[i][j] = start + i + j;
//		}
//	}
//	printf("打印矩阵：\n");
//	for (int m = 0;m < 10;m++)
//	{
//		for (int n = 0;n < 10;n++)
//		{
//			printf("%d	", square[m][n]);
//		}
//		printf("\n\n");
//	}
//	printf("输入你想找的数字：");
//	scanf("%d", &find);
//	for (int m = 0;m < 10;m++)
//	{
//		for (int n = 0;n < 10;n++)
//		{
//			if (square[m][n] == find)
//				flag++;
//		}
//	}
//	if (flag != 0)
//	{
//		printf("找到了%d个", flag);
//	}
//	else
//	{
//		printf("没找到");
//	}
//	return 0;
//}
//int reverse(char letter[], int len)
//{
//	int box[num] = { 0 };
//	int start = 0;
//	int j = 0;
//	char new[10] = { 0 };
//	for (int i = 0;i < 8;)
//	{
//		for (j = 0;j < 4;j++)
//		{
//			box[i] = j;
//			i++;
//		}
//	}
//	for (int m = 0;m < len; m++)
//	{
//		new[m] = letter[box[start]];
//		start++;
//	}
//	printf("%s", new);
//
//}

//#include <stdio.h>
//int reverse1(char s1[],char s2[],int len)
//{
//	int box[1000] = { 0 };
//	for (int i = 0;i < len * 2;)
//	{
//		for (int j = 0;j < len;j++)
//		{
//			box[i] = j;
//			i++;
//		}
//	}
//	int point = len % 8;
//	int flag = 0;
//	for (int m = 0;m < len; m++)
//	{
//		if (s1[m] == s2[box[point]])
//		{
//			flag++;
//		}
//		point++;
//	}
//	if (flag == len)
//	{
//		return 1;
//	}
//	return 0;
//}

#include <stdio.h>
#include <string.h>

int reverse1(char* s1, char* s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i, j;

    if (len1 != len2)
        return 0;
    // 如果s2是s1旋转后的字符串，则s2必定是s1+s1的子字符串
    char s1s1[1000] = { 0 };
    strcpy(s1s1, s1);
    strcat(s1s1, s1);

    for (i = 0; i < len1; i++) 
    {
        for (j = 0; j < len1; j++) 
        {
            if (s2[i] != s1s1[j + i])
                break;
        }
        if (j == len1)
            return 1;
    }
    return 0;
}
int main()
{
    char s1[] = "AABCD";
    char s2[] = "BCDAA";
    printf("%d\n", reverse1(s1, s2)); 

    char s3[] = "abcd";
    char s4[] = "ACBD";
    printf("%d\n", is_rotation(s3, s4));

    return 0;
}
