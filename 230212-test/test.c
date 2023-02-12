#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int sum = 0;//保存最终结果
//	int n = 0;
//	int ret = 1;//保存n的阶乘
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			ret *= j;
//		}
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}
#include <string.h>
#include <stdio.h>
#include <assert.h>
void my_strcpy(char* dest,char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = *src;
}
int main()
{
	char arr1[] = "hello world";
	char arr2[20] = { 0 };
	my_strcpy(arr2, arr1);
	printf("%s\n", arr2);
	return 0;
}