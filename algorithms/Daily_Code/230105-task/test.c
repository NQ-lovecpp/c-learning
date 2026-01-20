#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//int main()
//{
//    int i = 0;
//    double score = 0.0;
//    double sum = 0.0;
//    for (i = 0; i < 5; i++)
//    {
//        scanf("%lf", &score);
//        sum += score;
//    }
//    printf("%.2lf\n", sum / 5);
//    return 0;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,56,6,7,78,8 };
//	printf("%d\n", arr[5]);
//	int a = (int)3.01;
//	printf("%d\n", a);
//	char ch[10] = "hello bit";
//	printf("%s\n", ch);
//	return 0;
//}
//
//#include <stdio.h>
//
//int main()
//{
//    int arr[10];
//    int i1 = 0;
//    int i2 = 0;
//    int sco;
//    if (i1 < 10)
//    {
//        scanf("%d", &sco);
//        arr[i1] = sco;
//        i1++;
//    }
//    if (i2 < 10)
//    {
//        printf("%d ", arr[i2]);
//        i2++;
//    }
//    return 0;
////}
//#include <stdio.h>
//
//int main()
//{
//    int t, a;
//    scanf("%d\n", &t);//这里t为要输入数据的组数
//    while (t--)
//    {
//        scanf("%d", &a);
//        printf("%d ", a);
//    }
//    return 0;
//}
#include <stdio.h>

int main()
{
	int a;
	while (scanf("%d", &a) != EOF)
	{
		printf("输出:%d\n", a);
	}
	return 0;
}

//输入ctrl+z,结束输入 
