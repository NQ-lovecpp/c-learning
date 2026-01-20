#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int func(int x)
//{
//	int count = 0;
//	while (x)
//	{
//		count++;
//		x = x & (x - 1);//ÓëÔËËã
//	}
//	return count;
//}
//int main()
//{
//	printf("%d\n", func(-1));
//}
int main()
{
	int count = 0;
	int x = -1;
	while (x)
	{
		count++;
		x = x >> 1;
	}
	printf("%d", count);
	return 0;
}
