#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <wchar.h>

#include <screen.h>
#include <board.h>
#include <main.h>

int main()
{
	int screenRows;
	int screenCols;

	const int DIM = 19;

	board gameBoard = initBoard(DIM);
	printBoard(gameBoard);

	return 0;
}
