#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	int i = 0;
//	for (i = 0;i < 26;i++)
//	{
//		fputc('a' + i, pf);
//	}
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//读文件
//	//int i = 0;
//	//for (i = 0;i < 26;i++)
//	//{
//	//	fputc('a' + i, pf);
//	//}
//	int ch = fgetc(pf);
//	printf("%c ", ch);
//	ch = fgetc(pf);
//	printf("%c ", ch);
//	ch = fgetc(pf);
//	printf("%c ", ch);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//struct S
//{
//	int n;
//	float f;
//	char arr[20];
//};
//int main()
//{
//	struct S s = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fscanf(pf, "%d %f %s", s.n, s.f, s.arr);
//	//fputs("hello bit\n", pf);
//	//fputs("hello bit\n", pf);
//	printf("%d %f %s", &(s.n), &(s.f), s.arr);
//	
//	pf = NULL;
//	return 0;
//}



struct S
{
	int n;
	float f;
	char arr[20];
};
int main()
{
	struct S s = { 200, 3.5f, "wangwu" };
	char arr[200] = { 0 };
	sprintf(arr, "%d %f %s\n", s.n, s.f, s.arr);
	printf("%\n", arr);

	return 0;
}