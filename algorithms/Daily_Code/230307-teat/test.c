#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//    int x = 1, y;
//    y = (x > 3 ? ++x : (x > 3 ? ++x : (x = x + 10)));
//    printf("%d", y);
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//	int* p;
//	p = a[0];
//	printf("%d", p[0]);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	return 0;
//}

//#include <stdio.h>
//#define line 50
//void blankspace(int n)
//{
//	for (int i = 0;i < n;i++)
//	{
//		printf(" ");
//	}
//}
//void star(int n)
//{
//	for (int i = 0;i < n;i++)
//	{
//		printf("*");
//	}
//}
//int main()
//{
//	int m = 1;
//	for (int i = 0;i < ((line*2)+1);i++)
//	{
//		blankspace(abs(line- i));
//		if (i < line)
//		{
//			star(m);
//			m = m + 2;
//		}
//		else
//		{
//			star(m);
//			m = m - 2;
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include <assert.h>
//#include <stdio.h>
//void reverse_str(char* str)
//{
//	assert(str);
//	int len = strlen(str);
//	char* left = str;
//	char* right = str + len - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*right = *right;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[10001];
//	gets(arr);
//	reverse_str(arr);
//	printf("%s\n", arr);
//	return 0;
//}

#include <stdio.h>


int drink(int money)
{
	int bottles = 0;
	int count = 0;
	while (money != 0)
	{
		if (bottles == 2)
		{
			count++;
			bottles = 0;
			bottles++;
		}
		else
		{
			money--;
			bottles++;
			count++;
		}
	}
	return count;
}


int main()
{
	int money;
	printf("¸ø¶àÉÙÇ®£¿");
	scanf("%d", &money);
	printf("%d", drink(money));
	return 0;
}