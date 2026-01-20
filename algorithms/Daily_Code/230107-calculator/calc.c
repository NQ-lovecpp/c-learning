#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;
    double delta;
    double x1, x2, ans;
    printf("我是计算器，我可以解形如:ax^2+bx+c=0的二元一次方程\n");
    printf("输入你的方程系数a b c(用空格空开):");
    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF)
    {
        delta = b * b - 4 * a * c;
        if (a == 0)
            printf("不是二元一次方程！\n");
        else
            if (delta == 0)
            {
                ans = (-b) / (2 * a);
                if (ans == 0)
                    printf("x1=x2=0.00\n");
                else
                    printf("x1=x2=%.2lf\n", ans);
            }
            else if (delta > 0)
            {
                x1 = (-b - sqrtf(delta)) / (2 * a);
                x2 = (-b + sqrtf(delta)) / (2 * a);
                printf("x1=%.2lf\nx2=%.2lf\n", x1, x2);
            }
            else if (delta < 0)
            {
                printf("x1=%.2lf-%.2lfi\n", (-b) / (2 * a), sqrtf(4 * a * c - b * b) / (2 * a));
                printf("x2=%.2lf+%.2lfi\n", (-b) / (2 * a), sqrtf(4 * a * c - b * b) / (2 * a));
            }
        printf("输入你的方程系数a b c:");
    }
    return 0;
}