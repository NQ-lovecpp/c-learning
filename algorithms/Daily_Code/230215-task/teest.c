#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf("%d %d\n", a + b, c);
//	printf("%d", sizeof(int
//));
//	return 0;
//	
//}
//0000 0000 0000 0000 0000 0001 0010 1100
//1111 1111 1111 1111 1111 1110 1101 0011
//1111 1111 1111 1111 1111 1110 1101 0100

//1111 1111 1111 1111 1111 1111 1101 0100
//0000 0000 0000 0000 0000 0000 0010 1011
//0000 0000 0000 0000 0000 0000 0010 1100


//int main()
//{
//    char a[1000] = { 0 };
//    int i = 0;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d", strlen(a));
//    return 0;
//}
//#include <stdio.h>
//
//int main() {
//    int a, b, c, d, e; // 五名选手的名次
//    for (a = 1; a <= 5; a++) {
//        for (b = 1; b <= 5; b++) {
//            if (a == b) continue; // 选手不能与自己说同样的话
//            for (c = 1; c <= 5; c++) {
//                if (c == a || c == b) continue;
//                for (d = 1; d <= 5; d++) {
//                    if (d == a || d == b || d == c) continue;
//                    e = 15 - a - b - c - d; // 五名选手名次之和为15
//                    // 检查选手的预测和说对的数量
//                    int count = 0;
//                    if (b == 2 && a == 3) count++;
//                    if (b == 2 && e == 4) count++;
//                    if (c == 1 && d == 2) count++;
//                    if (d == 3 && c == 5) count++;
//                    if (e == 4 && a == 1) count++;
//                    if (count == 2) {
//                        printf("A: %d, B: %d, C: %d, D: %d, E: %d\n", a, b, c, d, e);
//                        return 0;
//                    }
//                }
//            }
//        }
//    }
//    printf("无法确定比赛名次\n");
//    return 0;
//}
//#include <stdio.h>
//
//int main() {
//    int rows, coef = 1, space, i, j;
//    printf("请输入要打印的行数：");
//    scanf("%d", &rows);
//    for (i = 0; i < rows; i++) {
//        for (space = 1; space <= rows - i; space++) {
//            printf("  ");
//        }
//        for (j = 0; j <= i; j++) {
//            if (j == 0 || i == 0) {
//                coef = 1;
//            }
//            else {
//                coef = coef * (i - j + 1) / j;
//            }
//            printf("%4d", coef);
//        }
//        printf("\n");
//    }
//    return 0;
//}

#include <stdio.h>
int main() 
{
    int a, b, c, d;
    for (a = 0; a <= 1; a++) 
    {
        for (b = 0; b <= 1; b++) 
        {
            for (c = 0; c <= 1; c++) 
            {
                for (d = 0; d <= 1; d++) 
                {
                    // 3个人说真话，1个人说假话，构成一个if语句进行判断
                    if ((a + b + c + d == 1) && (a + c + d == 3) && (b + c == 1) && (c + d == 1)) 
                    {
                        // 输出凶手的编号
                        if (a == 0) {
                            printf("凶手是A。\n");
                        }
                        else if (b == 0) {
                            printf("凶手是B。\n");
                        }
                        else if (c == 0) {
                            printf("凶手是C。\n");
                        }
                        else if (d == 0) {
                            printf("凶手是D。\n");
                        }
                        return 0; // 结束程序
                    }
                }
            }
        }
    }
    return 0;
}