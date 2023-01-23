#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu()
{
	printf("******************************\n");
	printf("********   1. play   *********\n");
	printf("********   0. exit   *********\n");
	printf("******************************\n");
}

void game()
{
	//mine数组是专门存放布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };
	//show数组是专门存放排查出来的雷的信息的
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine,ROW,COL);
	//排查雷
	FindMine(mine, show, ROW, COL);


}
int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
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