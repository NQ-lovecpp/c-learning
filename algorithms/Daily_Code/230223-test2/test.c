#define _CRT_SECURE_NO_WARNINGS
//int main()
//{
//	int i = 6, j, k;
//	j = (i++) + (i++) + (i++);
//	k = (++i) + (++i) + (++i);
//	return 0;
//}
#include <stdio.h>
int main()
{
	int a = 0;
	a = 3 * 5, a=a * 4, a + 5;
	int b = 0;
	a = 0;
	b = (a = 3 * 5, a * 4, a + 5);
	printf("%d  %d", a,b);
	return 0;
}