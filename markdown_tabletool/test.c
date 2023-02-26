#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int rows, cols;

    // 获取用户输入的行数和列数
    printf("请输入表格的行数和列数（用空格分隔）：\n");
    scanf("%d %d", &rows, &cols);

    // 输出表头
    printf("|");
    for (int i = 1; i <= cols; i++) {
        printf(" 列%d |", i);
    }
    printf("\n");

    // 输出表头分隔线
    printf("|");
    for (int i = 1; i <= cols; i++) {
        printf(" --- |");
    }
    printf("\n");

    // 输出表格内容
    for (int i = 1; i <= rows; i++) {
        printf("|");
        for (int j = 1; j <= cols; j++) {
            printf(" 行%d列%d |", i, j);
        }
        printf("\n");
    }

    return 0;
}
