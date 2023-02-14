#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
int my_strlen(const char *str)
{
	int count = 0;
	assert(str != NULL);
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	int len = my_strlen("haha");
	printf("%d\n", len);
	return 0;
}