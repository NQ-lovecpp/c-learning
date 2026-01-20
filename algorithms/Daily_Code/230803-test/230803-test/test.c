#include <stdio.h>

int main()
{
	int(*p)[8] = NULL;
	int value = 1024;
	char condition = *((char*)(&value));
	if (condition) value += 1; condition = *((char*)(&value));
	if (condition) value += 1; condition = *((char*)(&value));
	printf("%d %d", value, condition);
	return 0;
}
