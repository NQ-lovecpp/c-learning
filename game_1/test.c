#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
void menu()
{
	printf("*************************\n");
	printf("*****    1.play    ******\n");
	printf("*****    0.exit    ******\n");
	printf("*************************\n");
}

void game()
{
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);

	while (1)

	{
		int ret = 0;
		//玩家下棋
		PlayerMove();
		//打印棋盘
		DisplayBoard();
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}


		//电脑下棋
		ComuputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
	}

}


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);
	return 0;
}