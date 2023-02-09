#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//struct S
//{
//	int num;
//	char c;
//
//};
//int main()
//{
//	struct S s = { 100,'b' };
//	printf("%d\n", s.num);
//
//	return 0;
//}
//#include <stdio.h>
//int i;
//int main()
//{
//    i--;
//    printf("%d %d\n", i,sizeof(i));//C语言中整数自动转换原则，当表达
//    //式中存在有符号和无符号类型时，所有类型自动转换成无符号类型。
//    if (i > sizeof(i))
//    {
//        printf(">\n");
//    }
//    else
//    {
//        printf("<\n");
//    }
//    return 0;
//}

#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int narr[100] = { 0 };
    int marr[100] = { 0 };
    int mp = 0, np = 0;
    for (int i = 0;i < n;i++)
    {
        scanf("%d", &narr[i]);
    }
    for (int i = 0;i < m;i++)
    {
        scanf("%d", &marr[i]);
    }
    for (int i = 0;i < m + n;i++)
    {
        if (narr[np] < marr[mp])
        {
            printf("%d", narr[np]);
            np++;
        }
        else
        {
            printf("%d", marr[mp]);
            mp++;
        }
        if (i < n + m - 1)
        {
            printf(" ");
        }
    }
    return 0;
}