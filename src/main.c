#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <wchar.h>

#include <screen.h>
#include <board.h>

int main()
{
	int screenRows;
	int screenCols;

	int DIM = 19;
	wchar_t logicBoard[DIM][DIM];
	wchar_t printableBoard[DIM][(2*DIM)-1];

	initScreen();
	initLogicBoard(DIM);
	updatePrintBoard();
	ggpo();
	return 0;
}
