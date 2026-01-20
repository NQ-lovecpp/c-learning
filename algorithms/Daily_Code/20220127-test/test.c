#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int flag;
int IsLeapYear(int year)//是闰年返回1，不是返回0
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        flag = 1;
        return 1;
    }
    else
    {
        flag = 0;
        return 0;
    }
}
int main()
{

    int y;
    int m;
    int d;
    int days = 0;
    int lut[12] = { 0,31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
    scanf("%d %d %d", &y, &m, &d);
    if (m >= 3)
    {
        if (IsLeapYear)
        {
            days = lut[m - 1] + d + 1;
        }
    }
    else
    {
        days = lut[m - 1] + d;
    }
    printf("%d\n", days);
    return 0;
}