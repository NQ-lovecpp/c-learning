#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//#include <string.h>
////int main()
////{
////	char arr[] = "abc\0def";
////	int len = strlen(arr);
////	printf("%d\n", len);
////	return 0;
////}
//
//#include <assert.h>
//#include <stdio.h>
//int my_strlen(const char* str)
//{
//	int count = 0;
//	assert(str);
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//	//if (*str != '\0')
//	//	return 1 + my_strlen(str + 1);
//	//else
//	//	return 0;
//}
//int main()
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//char* my_strcpy(char* dest,const char* src)
//{
//	char* ret = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//char* my_strcat(char* dest, char* src)
//{
//	char* ret = dest;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int my_strcmp(const char* str1, const char* str2)
//{
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//}
//int main()
//{
//	char arr1[] = "hello";
//	char arr2[] = "world";
//	printf("%s\n", arr1);
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	char arrm[] = "abcdefg";
//	char arrn[] = "abcdadda";
//	printf("%d\n", my_strcmp(arrn, arrm));
//}
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[5] = "xxxx";
//	strncpy(arr2, arr1, 3);
//	printf("%s\n", arr2);
//	return 0;
//}

//#include <stdio.h>
//char* my_strcpy(char* dest,const char* src)
//{
//	char* ret = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "hello";
//	char arr2[20] = { 0 };
//	my_strcpy(arr2, arr1);
//	printf("%s", arr2);
//	return 0;
//}

//#include <stdio.h>
//int my_strcmp(const char* str1, const char* str2)
//{
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//}
//int main()
//{
//	char arrm[] = "abcdefg";
//	char arrn[] = "abcdadda";
//	printf("%d\n", my_strcmp(arrn, arrm));
//}
//#include <stdio.h>
//#include <string.h>
//char* my_strcat(char* dest, char* src)
//{
//	char* ret = dest;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while ((*dest++ = *src++))
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arrs[6] = "hello";
//	char arrd[20] = "world ";
//	strcat(arrd,arrd);
//	printf("%s\n", arrd);
//	return 0;
//}

#include <stdio.h>
#include <string.h>

char* my_strstr(const char* str1,const char* str2)
{
	char* s1 = NULL;
	char* s2 = NULL;
	char* cp = str1;

	while (*cp)
	{
		s1 = cp;
		s2 = str2;
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return cp;
		}
		cp++;
	}
	return NULL;

}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "bcd";
	char* p= my_strstr(arr1, arr2);
	if (p == NULL)
	{
		printf("ÕÒ²»µ½\n");
	}
	else
	{
		printf("%s\n", p);
	}
	return 0;
}