#define _CRT_SECURE_NO_WARNINGS


//#include <stdio.h>
//int main()
//{
//	int count = 0;
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 0;i < n;i++)
//	{
//		for (count = 0;count < i;count++)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	char a = 0;
//	int count = 1;
//	for (char a = 'A';a <= 'Z';a++,count++)
//	{
//		printf("%d ", a);
//		if (count >= 5)
//		{
//			printf("\n");
//			count=0;
//		}
//	}
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
//void blank(int n)
//{
//	for (int i = 0;i < n;i++)
//	{
//		printf(" ");
//	}
//}
//int main()
//{
//	int i = 0, max = 0;
//	scanf("%d", &max);
//	int j = max;
//	for (i = 1;i <= max;i++,j--)
//	{
//		blank((j - 1) * 2 + (j - 2));
//		for (int k = 0;k < i;k++)
//		{
//			printf("%d     ", i);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//#include <stdio.h>
//enum ENUM_A
//{
//	X1,
//	Y1,
//	Z1 = 255,
//	A1,
//	B1,
//};
//int main()
//{
//	enum ENUM_A enumA = Y1;
//	enum ENUM_A enumB = B1;
//	printf("%d %d\n", enumA, enumB);
//	return 0;
//}

#include <stdio.h>

int main()
{
    unsigned char puc[4];
    struct tagPIM
    {
        unsigned char ucPim1;
        unsigned char ucData0 : 1;
        unsigned char ucData1 : 2;
        unsigned char ucData2 : 3;
    }*pstPimData;
    pstPimData = (struct tagPIM*)puc;
    memset(puc, 0, 4);
    pstPimData->ucPim1 = 2;
    pstPimData->ucData0 = 3;
    pstPimData->ucData1 = 4;
    pstPimData->ucData2 = 5;
    printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
    return 0;
}