#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//long long Fib(size_t N)
//{
//	if (N < 3)
//		return 1;
//	return Fib(N - 1) + Fib(N - 2);
//}
//int main()
//{
//	printf("%lld", Fib(3));
//	return 0;
//}

//#include <stdio.h>
//void Func1()
//{
//	int a = 0;
//	printf("%p\n", &a);
//}
//void Func2()
//{
//	int a = 0;
//	printf("%p\n", &a);
//}
//int main()
//{
//	Func1();
//	Func2();
//	return 0;
//}

#include <stdlib.h>
int** fun(int n) 
{
    int** s = (int**)malloc(n * sizeof(int*));
    while (n--)
        s[n] = (int*)malloc(n * sizeof(int));
    return s;
}