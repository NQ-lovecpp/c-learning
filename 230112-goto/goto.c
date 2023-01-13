#define _CRT_SECURE_NO_WARNINGS
//int main()
//{
//	flag:
//	printf("hehe\n");
//	printf("haha\n");
//	printf("heihei\n");
//	goto flag;
//	return 0;
//}
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
	char arr[20] = { 0 };
	system("shutdown -s -t 60");
again:
	printf("请注意，你的电脑将在一分钟内关机，如果输入：我是猪。就取消关机\n");
	scanf("%s", arr);
	if (strcmp(arr, "我是猪") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}//不要玩的收不了场，最后只能给同学重装系统
