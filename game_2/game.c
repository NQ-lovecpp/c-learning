#define _CRT_SECURE_NO_WARNINGS


#include "game.h"

void InitBoard(char board[ROWS][COLS],int rows,int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < rows; i++)
	{
		for (i = 0;i < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("****** 扫雷 ******\n");
	for (j = 0;j <= col; j++)
	{
		printf("%d", j);
	}
	printf("\n");
	for (i = 0;i <= row;i++)
	{
		printf("%d ", i);
		for (j = 1;j <= col;j++)
		{
			printf("%c ", board[i][j]);

		}
		printf("\n");
	}
}


void SetMine(char mine[ROW][COL], int row, int cow)
{
	int count = EASY_COUNT;
	while (count)
	{
		int rand() % row + 1;
		int rand() % col + 1;
		if (mine[x][y] == "0")
		{
			mine[x][y] = '1';
			count--;
		}
	}
}



int GetMineCount(char mine[ROW][COL], int x, int y)
{
	return(mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0');
}

void FineMine(char mine[ROWS][COLS], char[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("请输入要排查的坐标:>");
		scanf("% %d", &x, &y);
		if (x>=1 && x<=row &&y>=)
	}
}