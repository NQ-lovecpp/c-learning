#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int max(int m2, int m)
{
    if (m2 > m)
        return m2;
    else
        return m;
}
int min(int m, int m2)
{
    if (m > m2)
        return m2;
    else
        return m;
}

int main()
{
    int n = 0;
    int i = 0;
    scanf("%d", &n);
    int arr[10];
    int sco, Maxsco, Minsco;
    if (n == 1)
        printf("0");
    else
    {
        for (i = 0;i <= n - 1;i++)
        {
            scanf("%d", &sco);
            arr[i] = sco;
        }
        Maxsco = max(arr[0], arr[1]);
        Minsco = min(arr[0], arr[1]);
        for (i = 2;i <= n - 1;i++)
        {
            Maxsco = max(Maxsco, arr[i]);
            Minsco = min(Minsco, arr[i]);
        }
        printf("%d", Maxsco - Minsco);
    }
    return 0;
}