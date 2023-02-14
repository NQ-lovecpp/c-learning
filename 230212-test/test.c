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
//#include <string.h>
//#include <stdio.h>
//#include <assert.h>
//void my_strcpy(char* dest,char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*src != '\0')
//	{
//		*dest++ = *src++;
//	}
//	*dest = *src;
//}
//int main()
//{
//	char arr1[] = "hello world";
//	char arr2[20] = { 0 };
//	my_strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}

//#include <stdio.h>
//int* Relineup(int box[],int len)
//{
//	int odd[100] = { 0 };
//	int even[100] = { 0 };
//	int oddi = 0, eveni = 0;
//	for (int i = 0;i < len;i++)
//	{
//		if (box[i] % 2 == 0)
//		{
//			even[eveni] = box[i];
//			eveni++;
//		}
//		else if (box[i] % 2 == 1)
//		{
//			odd[oddi] = box[i];
//			oddi++;
//		}
//	}
//	for (int i = 0;i < oddi;i++)
//	{
//		box[i] = odd[i];
//	}
//	for (int i = oddi;i < eveni;i++)
//	{
//		box[i] = even[i];
//	}
//	return box;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	Relineup(arr,10);
//	for (int i = 0;i < 10;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

#include <stdio.h>
int my_strlen(const char *arr)
{
	int i = 0;
	while (*arr != '\0')
	{
		i++;
		arr++;
	}
	return i;
}
int main()
{
	char haha[] = "hahahaha";
	printf("%d\n", my_strlen(haha));
	return 0;
}