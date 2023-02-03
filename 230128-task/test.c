#define _CRT_SECURE_NO_WARNINGS
//int b;
//const int* a = &b;
////int const* a = &b;
////int* const a = &b;
//
//
//int main()
//{
//	return 0;
//}
//#include <stdio.h>
//int HowMany(float box[], int n)
//{
//    int i;
//    int flag = 0;
//    for (i = 0;i < n;i++)
//    {
//        if (box[i] < 0)
//        {
//            flag++;
//        }
//    }
//    return flag;
//}
//
//int avg(float box[], int n)
//{
//    int add = 0;
//    int i;
//    int flag=0;
//    float average;
//    for (i = 0;i < n;i++)
//    {
//        if (box[i] > 0)
//        {
//            add += box[i];
//            flag++;
//        }
//    }
//    return average = add / flag;
//}
//
//int main()
//{
//    int n;
//    float box[20];
//    int i;
//    scanf("%d", &n);
//    for (i = 0;i < n;i++)
//    {
//        scanf("%d\n", box[i]);
//    }
//    printf("%d %.1f", HowMany(box, n), avg(box, n));
//    return 0;
//}
#include <stdio.h>
int HowMany(float box[], int n)
{
    int i;
    int flag = 0;
    for (i = 0;i < n;i++)
    {
        if (box[i] < 0)
        {
            flag++;
        }
    }
    return flag;
}

float avg(float box[], int n)
{
    int add = 0;
    int i;
    int flag = 0;
    float average;
    for (i = 0;i < n;i++)
    {
        if (box[i] > 0)
        {
            add += box[i];
            flag++;
        }
    }
    if (flag == 0)
    {
        return 0.0;
    }
    else
    {
        return average = add / flag;
    }
}

int main()
{
    int n;
    float box[20];
    int i;
    scanf("%d", &n);
    for (i = 0;i < n;i++)
    {
        scanf("%d\n", &box[i]);
    }
    printf("%d %.1f", HowMany(box, n), avg(box, n));
    return 0;
}