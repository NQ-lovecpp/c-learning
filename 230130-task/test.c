#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	/*char c;
//	int v0 = 0, v1 = 0, v2 = 0;
//		do
//		{
//			switch (c = getchar())
//			{
//			case'a':case'A':
//			case'e':case'E':
//			case'i':case'I':
//			case'o':case'O':
//			case'u':case'U':v1 += 1;
//			default:v0 += 1;v2 += 1;
//			}
//		} while (c != '\n');
//		printf("v0=%d,v1=%d,v2=%d\n", v0, v1, v2);*/
//	char pwd[100] = { 0 };
//		return 0;
//}
#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    int i, l;
    while (scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            char pwd[101] = { 0 };
            scanf("%s", &pwd);
            //判断长度是否大于8
            if (strlen(pwd) < 8)
            {
                printf("NO\n");
                continue;
            }
            //密码不能以数字开头
            if (pwd[0] >= '0' && pwd[0] <= '9')
            {
                printf("NO\n");
                continue;
            }
            //下面计算密码中大写字母，小写字母和数字是否出现，出现的用1表示没出现的用0表示
            int small = 0, big = 0, num = 0, others = 0;
            for (l = 0; pwd[l] != '\0'; l++)
            {
                if (pwd[l] >= 'a' && pwd[l] <= 'z')
                {
                    small++;
                }
                else if (pwd[l] >= 'A' && pwd[l] <= 'Z')
                {
                    big++;
                }
                else if (pwd[l] >= '0' && pwd[l] <= '9')
                {
                    num++;
                }
                else
                {
                    others++;
                }
            }
            if (others != 0)
            {
                printf("NO\n");
                continue;
            }
            if ((small > 0) + (big > 0) + (num > 0) < 2)
            {
                printf("NO\n");
                continue;
            }
            printf("YES\n");
        }
    }
    return 0;
}