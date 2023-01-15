#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
void menu()
{
	printf("*************************");
	printf("*****    1.play    ******");
	printf("*****    0.exit    ******");
	printf("*************************");
}

void game()
{
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);


}


int main()
{
	int input = 0;
	do
	{
		menu();
		printf("ÇëÑ¡Ôñ£º>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
		case 0:
			printf("ÍË³öÓÎÏ·\n");


		}

	}while()
}