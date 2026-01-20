#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	printf("d\n", 10 / 3);
//	printf("%d\n", 10 % 2);
//
//	return 0;
//	
//}
//#include <stdio.h>
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	i = a++ && ++b && d++;
//	//i = a++||++b||d++;
//	printf("a = %d\n b = %d\n c = %d\nd = %d\n", a, b, c, d);
//	return 0;
//}
////程序输出的结果是什么？
//#include <stdio.h>
//int main()
//{
//	int a, b, c;
//	a = 5;
//	c = ++a;
//	b = ++c, c++, ++a, a++;
//	b += a++ + c;
//	printf("a = %d b = %d c = %d\n:", a, b, c);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a = 1;
//	int b = 2;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("a=%d b=%d\n", a, b);
//}

//#include <stdio.h>
//int main()
//{
//	int a;
//	int point = 1;
//	int i = 0;
//	int count = 0;
//	scanf("%d", &a);
//	for (i = 0;i < 32;i++)
//	{
//		if (a & point)
//		{
//			count++;
//		}
//		point <<= 1;
//	}
//	printf("%d个1", count);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int x;
//	scanf("%d", &x);
//	int y = x;
//	printf("打印偶数位：");
//	for (int i = 0;i < 16;i++)
//	{
//		int a = x & 1;
//		printf("%d", a);
//		x >>= 2;
//	}
//	printf("打印奇数位：");
//	y >>= 1;
//	for (int i = 0;i < 16;i++)
//	{
//		int a = y & 1;
//		printf("%d", a);
//		y >>= 2;
//	}
//}

#include <stdio.h>
int main()
{
	int a, b;
	int box = 0;
	int point = 1;
	int count = 0;
	scanf("%d %d", &a, &b);
	box = a ^ b;
	for (int i = 0;i < 32;i++)
	{
		if (box & point)
		{
			count++;
		}
		point <<= 1;
	}
	printf("%d\n", count);
	return 0;
}