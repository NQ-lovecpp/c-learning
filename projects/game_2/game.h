#pragma once

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EAEY_COUNT 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//≥ı ºªØ∆Â≈Ã
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//¥Ú”°∆Â≈Ã
void DisplayBoard(char board[ROWS][COLS], int rows, int cols);

//≤º÷√¿◊
void SetMine(char mine[ROW][COL], int rows, int cols);

//≈≈≤È¿◊
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);