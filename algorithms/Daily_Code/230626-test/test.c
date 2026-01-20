#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char name1 = 'w';
	char name2[] = "wang";
	char* pname3 = "wang";
	char* pname4[] = { "wang" };
	printf("%c\n%p\n%p\n%p", name1, name2, pname3, pname4);
	return 0;
}