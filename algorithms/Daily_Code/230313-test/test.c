#define _CRT_SECURE_NO_WARNINGS



//int main()
//{
//	char arr[] = "zpengwei@yeah.net";
//	char buf[30] = { 0 };
//	strcpy(buf, arr);
//	const char* p = ".@";
//	char* str = NULL;
//	for (str = strtok(buf, p);str != NULL;str = strtok(NULL, p))
//	{
//		printf("%s\n", str);
//	}
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	FILE* pf=fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("打开文件失败，原因是：%s\n", strerror(errno));
//		return 1;
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("打开文件失败");
//		return 1;
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
//#include <string.h>
//#include <stdio.h>
//void test1()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[8] = { 0 };
//	memcpy(arr2, arr1, 20);//拷贝5个字节
//}
////memcpy返回的是目标空间的起始地址
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	if (dest < src)
//	{
//		//从前向后
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//	return ret;
//}
////int main()
////{
////	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
////	int arr2[8] = { 0 };
////	my_memmove(arr2, arr1, 20);//拷贝5个字节
////	return 0;
////}
////
////int main()
////{
////	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
////	
////	return 0;
////}
//
//
//#include <ctype.h>
//int main()
//{
//	printf()
//	return 0;
//}

#include <stdio.h>
#include <string.h>
void* my_memcpy(void* dest, const void* src, size_t num)
{
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}

void* my_memmove(void* dest, const void* src, size_t num)
{
	void* ret = dest;
	if (dest < src)
	{
		//从前向后
		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret;
}

int main()
{
	char hehe[20] = "nihaowoshiczw";
	char src[11] = "1234567890";
	my_memmove(src, src+3, 3);
	printf("%s", src);
	return 0;
}
