#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int missingNumber(int* nums, int numsSize)
{
    int x = 0;
    for (int i = 0;i < numsSize;++i)
    {
        x ^= nums[i];
    }
    for (int i = 0;i < numsSize + 1;++i)
    {
        x ^= i;
    }
    return x;
}

int main()
{
    int arr[9] = { 9,6,4,2,3,5,7,0,1 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", missingNumber(arr, sz));
    return 0;
}