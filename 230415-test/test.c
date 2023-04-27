#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int min = (m > n ? n : m);
    int i = 0;
    int* dest = (int*)malloc((n + m) * sizeof(int));
    for (i = 0;i < 2 * min;)
    {
        if (nums1[m] <= nums2[n])
        {
            dest[i] = nums1[m];
            m++;
            i++;
        }
        else
        {
            dest[i] = nums1[n];
            n++;
            i++;
        }
    }
    if (m > n)
    {
        for (;i < nums1Size + nums2Size;i++)
        {
            dest[i] = nums1[m++];
        }
    }
    else if (n > m)
    {
        for (;i < nums1Size + nums2Size;i++)
        {
            dest[i] = nums2[n++];
        }
    }
}

int main()
{
    for 
    return 0;
}