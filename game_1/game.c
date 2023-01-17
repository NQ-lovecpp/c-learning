#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0;j < col;j++)
		{
			board[i][j] = ' ';
		}
	}
}


void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0;j < col;j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0;j < col;j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋:>\n");
	printf("请输入要下棋的坐标:>");
	scanf("%d %d", &x, &y);
	if ()
	{
		
	}
}

//电脑随机下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑下棋>:\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y])
		{
			board[x]
		}
	}



}

//棋盘是否满了
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int 
}

//判断输赢
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		if (board[i][0] == board[i][0] && board[i][1] == board[i][])
		{
			return board[i][0];
		}
	}
}