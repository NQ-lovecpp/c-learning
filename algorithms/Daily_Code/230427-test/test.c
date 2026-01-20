#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char arr[20] = "haha";
	printf("%s\n", arr);
	char* p = "nihao";
	arr[0] = *p;
	printf("%s", arr);
	return 0;
}