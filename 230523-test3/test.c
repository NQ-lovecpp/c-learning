#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* fun(char* str)
{
	char* left = str;
	char* right = str;
	int flag = 1;
	while (*right)
	{
		right++;
	}
	right--;
	while (left < right)
	{
		if (*left != *right)
		{
			flag = 0;
			break;
		}
		left++, right--;
	}
	if (flag == 1)
	{
		char* ret = (char*)calloc(10, sizeof(char));
		strcpy(ret, "Yes!");
		return ret;
	}
	else
	{
		char* ret = (char*)calloc(10, sizeof(char));
		strcpy(ret, "No!");
		return ret;
	}

}
int main()
{
	char a[20] = "abcdefggfedcba";
	char* ret = fun(a);
	printf("是不是回文？\n%s", ret);
	free(ret);
	ret = NULL;
	return 0;
}