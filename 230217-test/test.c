#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//    int a = 0;
//    int b = 0;
//    int arra[100000] = { 0 };
//    int arrb[100000] = { 0 };
//    while (scanf("%d %d", &a, &b) != EOF)
//    {
//        if (1 <= a && a <= 100000 && 1 <= b && b <= 100000)
//        {
//
//            for (int i = 0;i < 100000;i++)
//            {
//                arra[i] *= a;
//            }
//            for (int i = 0;i < 100000;i++)
//            {
//                arrb[i] *= b;
//            }
//            for (int i = 0;i < 100000;i++)
//            {
//                for (int j = 0;j < 100000;j++)
//                {
//                    if (arra[i] == arrb[j])
//                    {
//                        printf("%d", arra[i]);
//                        goto end;
//                    }
//                }
//            }
//        }
//        else
//        {
//            printf("ÊäÈëÓÐÎó");
//        }
//    }
//end:
//    return 0;
//}
#include <stdio.h>
#include <string.h>
char box[100];
int main()
{
    while (scanf("%s", box) != EOF)
    {
        int i = 0;
        int j = 0;
        int len = strlen(box);
        for (i = 0, j = len - 1;i < j;i++, j--)
        {
            char tmp = box[i];
            box[i] = box[j];
            box[j] = tmp;
        }
        for (i = 0, j = 0;i < len;i++)
        {
            if (box[i] == ' ')
            {
                int k;
                for (k = j;k < i;k++, i--)
                {
                    char tmp = box[k];
                    box[k] = box[i - 1];
                    box[i - 1] = tmp;
                }
                j = i + 1;
            }
        }
        int k;
        for (k = j; k < len; k++, len--)
        {
            char temp = box[k];
            box[k] = box[len - 1];
            box[len - 1] = temp;
        }
        printf("%s ", box);
    }
    return 0;
}