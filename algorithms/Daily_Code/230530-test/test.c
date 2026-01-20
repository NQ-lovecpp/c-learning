#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[20] = { 0 };
//	int j = 0;
//	for (i = 2000;i >1;i--)
//	{
//		if (i % 1 == 0 &&
//			i % 2 == 1 &&
//			i % 3 == 0 &&
//			i % 4 == 1 &&
//			i % 5 == 4 &&
//			i % 6 == 3 &&
//			i % 7 == 0 &&
//			i % 8 == 5 &&
//			i % 9 == 0)
//		{
//			arr[j++] = i;
//		}
//	}
//	for (int m = 0;m < j;m++)
//	{
//		printf("%d ", arr[m]);
//	}
//	return 0;
//}


//#include <stdio.h>
//
//int main() {
//    int n = 2022; // 小鸡总数
//    int eliminated = 0; // 淘汰的小鸡数量
//
//    // 从每轮开始时的第一个小鸡开始报数
//    int current_chicken = 1;
//
//    while (eliminated < n - 1) {
//        // 计算当前小鸡的报数
//        int count = 1;
//
//        // 报数直到报到平方数
//        while (count * count <= n - eliminated) {
//            if (current_chicken > n) {
//                current_chicken = 1; // 如果超过小鸡总数，则从第一个小鸡重新开始报数
//            }
//            if (count * count == n - eliminated) {
//                break; // 如果报数等于平方数，跳出内层循环
//            }
//            count++;
//            current_chicken++;
//        }
//
//        eliminated++; // 淘汰一个小鸡
//        current_chicken++; // 下一个小鸡开始报数
//    }
//
//    printf("幸运小鸡在第一轮报的数是：%d\n", current_chicken);
//
//    return 0;
//}

int main()
{
	int a[3][4] = { 0 };
	(a);
	a[0][0];
	a[0] + 1;
	*(a[0] + 1);
	(a + 1);
	*(a + 1);
	&a[0] + 1;
	(*(&a[0] + 1));
	*a;
	(a[3]);
	return 0;
}
