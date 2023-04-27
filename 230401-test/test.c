#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//
//char* my_strncat(char* dest, const char* sorce, size_t num)
//{
//	char* ret = dest;
//	int i = strlen(dest);
//	int j = 0;
//	for (j = 0;j < num;i++, j++)
//	{
//		*(dest + i) = *(sorce + j);
//	}
//	*(dest+i)= '\0';
//	return ret;
//}
//
//char* my_strncpy(char* dest, char* sorce, size_t num)
//{
//	char* ret = dest;
//	int i = 0;
//	int j = 0;
//	for (j = 0;j < num;i++, j++)
//	{
//		*(dest + i) = *(sorce + j);
//	}
//	*(dest + strlen(dest)) = '\0';
//	return ret;
//}
//int main()
//{
//	char dest[20] = "123456";
//	char arr[20] = "7890";
//	my_strncpy(dest, arr, 2);
//	printf("%s", dest);
//	return 0;
//}


#include <stdio.h>
#include <ctype.h>

int atoi(const char* str) 
{
    int result = 0;
    int sign = 1;

    // Ìø¹ý¿Õ°××Ö·û
    while (isspace(*str)) 
    {
        str++;
    }

    // ÅÐ¶ÏÕý¸ººÅ
    if (*str == '+' || *str == '-') 
    {
        if (*str == '-') 
        {
            sign = -1;
        }
        str++;
    }

    while (isdigit(*str)) 
    {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}

int main()
{
    char arr[20] = "-333425";
    printf("%s %d", arr, atoi(arr));
    return 0;
}