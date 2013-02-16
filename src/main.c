#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <wchar.h>

#include <screen.h>

int DIM = 19;

int main()
{
	initScreen();
	wchar_t board[DIM][DIM];
	board = initBoard(DIM);
	wchar_t printableBoard[DIM][(2*DIM)-1];
	printableBoard = printBoard(DIM,board);
	ggpo();
	return 0;
}
