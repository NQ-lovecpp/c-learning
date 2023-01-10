#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <windows.h>
//int main()
//{
//	char arr1[] = "welcome to bit!!!!";
//	char arr2[] = "******************";
//	int left = 0;
//	int right=strlen(arr1)=1
//
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0;i < 3;i++)
//	{
//		printf("请输入密码：>");
//		scanf("%s", password);
//		if ()
//	}
//}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu()
{
	printf("*****************************\n");
	printf("*********   1. play  *******\n");
	printf("*********   0. exit  ********\n");
	printf("*****************************\n");
}

void game()
{
	//生成随机数
	int ret = rand() % 100+1;
	int guess = 0;
	while (1)
	{
		printf("请猜数字：");
		scanf("%d", &guess);
		if ((guess < ret))
		{
			printf("猜小了\n");
		}
		else if (guess > ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//随机函数生成器
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}