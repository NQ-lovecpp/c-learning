#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int i = 0;
    int arr[12] = { 73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116 , 33 };
    for (i = 0;i <= 11;i++)
    {
        printf("%c", arr[i]);
    }
    return 0;
}