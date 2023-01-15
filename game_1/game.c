#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col);
{
	int i = 0;
	memset(&board[0][0],' ',row*col*sizeof(board[0][0]))
}

void DisplayBoard(char board[ROW][COL],int row)