#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int dominantIndex(int* nums, int numsSize)
{
    int bigger = nums[0];
    int i;
    int flag = 0;
    int tag = 0;
    for (i = 0;i < numsSize - 1;i++)
    {
        if (bigger <= nums[i + 1])
        {
            bigger = nums[i + 1];
        }
        else
        {
            bigger = nums[i];
        }
    }
    for (i = 0;i < numsSize;i++)
    {
        if (bigger >= 2 * nums[i])
        {
            flag++;
        }
    }
    for (i = 0;i < numsSize;i++)
    {
        if (bigger == nums[i])
        {
            tag = i;
        }
    }
    if (flag == numsSize - 1)
    {
        return tag;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int nums[4] = { 3,6,1,0 };
    int numsSize = 4;
    printf("%d\n", dominantIndex(nums, numsSize));
}