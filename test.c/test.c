#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
////int dominantIndex(int* nums, int numsSize)
////{
////    int bigger = nums[0];
////    int i;
////    int flag = 0;
////    int tag = 0;
////    for (i = 0;i < numsSize - 1;i++)
////    {
////        if (bigger <= nums[i + 1])
////        {
////            bigger = nums[i + 1];
////        }
////        else
////        {
////            bigger = nums[i];
////        }
////    }
////    for (i = 0;i < numsSize;i++)
////    {
////        if (bigger >= 2 * nums[i])
////        {
////            flag++;
////        }
////    }
////    for (i = 0;i < numsSize;i++)
////    {
////        if (bigger == nums[i])
////        {
////            tag = i;
////        }
////    }
////    if (flag == numsSize - 1)
////    {
////        return tag;
////    }
////    else
////    {
////        return -1;
////    }
////}
////int main()
////{
////    int nums[4] = { 3,6,1,0 };
////    int numsSize = 4;
////    printf("%d\n", dominantIndex(nums, numsSize));
////}
//int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
//{
//    int box[101] = {'\0'};
//    int i = 0;
//    int j = 0;
//    int h = 0;
//    int count = 0;
//    int flag = 0;
//    for (i = 0;i < nums1Size;i++)
//    {
//        for (j = 0;j < nums2Size;j++)
//        {
//            if (nums1[i] == nums2[j])
//            {
//                for (h = 0;h < 101;h++)
//                {
//-                   if (nums1[i] == box[h])
//                    {
//                        flag++;
//                    }
//                }
//                if (flag == 0)
//                {
//                    box[count] = nums1[i];
//                    count++;
//                }
//            }
//        }
//    }
//    return box;
//}
//int main()
//{
//    int nums1[4] = { 1,2,2,1 };
//    int nums2[2] = { 2,2 };
//    int a = 4;`
//    int b = 2;
//    intersection(nums1, a, nums2, b, b);
//    return 0;
//}

int fun(int x)
{
	return (x == 1) ? 1 : (x + fun(x - 1));
}
int main()
{
	printf("%d\n", fun(10));
}