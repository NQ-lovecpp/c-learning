#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	int len = my_strlen("abcdef");
//	printf("%d\n,len");
//
//	return 0;
//}
//#include <stdio.h>
//typedef struct Book
//{
//	char name[20];
//	int price;
//}b3, b4, b5;//全局变量
//
//
//int main()
//{	
//	struct Book b1 = { "鹏哥c语言",66 };
//	struct Book b2 = { .price = 80,.name = "航哥C++" };
//	printf("%s %d\n", b1.name, b2.price);
//
//	return 0;
//}
//#include <stdio.h>
//struct stu
//{
//	int num;
//	char name[10];
//	int age;
//};
//
//void fun(struct stu* p)
//{
//	printf(" % s\n", (*p).name);
//	return;
//}
//
//int main()
//{
//	struct stu students[3] = { {9801,"zhang",20},
//							 {9802,"wang",19},
//					{9803,"zhao",18} };
//	fun(students + 1);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//char* ReverseString(char* letter,int len)
//{
//	char box[10000] = { 0 };
//	int j = 0;
//	for (int i = len-1;i >= 0;i--)
//	{
//		box[j] = letter[i];
//		j++;
//	}
//	for (int i = 0;i < len;i++)
//	{
//		letter[i] = box[i];
//	}
//	return letter;
//}
//int main()
//{
//	char letter[10000] = {0};
//	scanf("%s", letter);
//	int len = strlen(letter);
//	printf("%s", ReverseString(letter,len));
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
	printf("给多少钱？");
	scanf("%d", &money);
	printf("%d", drink(money));
	return 0;
}