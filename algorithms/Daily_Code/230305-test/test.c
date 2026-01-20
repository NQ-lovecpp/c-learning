#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int count_bit(unsigned int num)
{
	int count = 0;
	while (num)
	{
		if (num % 2 == 1)
		{
			count++;
		}
		num /= 2;
	}
	return count;
}


int count_bit2(int num)
{
	int count = 0;
	int i = 0;
	for (i = 0;i < 32;i++)
	{
		if (((num >> i) & 1) == 1)
		{
			count++;
		}
	}
	return count;
}


int main()
{
	int num = 0;
	scanf("%d", &num);
	int ret = count_bit2(num);
	printf("%d", ret);
	return 0;
}