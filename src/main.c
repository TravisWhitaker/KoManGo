#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncursesw/ncurses.h>
#include <locale.h>

#include <screen.h>
#include <board.h>
#include <main.h>

int main()
{

	setlocale(LC_ALL,"");

	int screenRows;
	int screenCols;

	const int DIM = 19;

	board gameBoard = initBoard(DIM);

	*(gameBoard.grid) = '1';
	*(gameBoard.grid+1) = '2';
	*(gameBoard.grid+2) = '1';
	*(gameBoard.grid+19) = '2';
	*(gameBoard.grid+20) = '1';
	*(gameBoard.grid+21) = '2';
	*(gameBoard.rows[2]) = '1';
	*(gameBoard.rows[2]+1) = '2';
	*(gameBoard.rows[2]+2) = '1';

	initScreen();

	printBoard(gameBoard);

	getch();
	ggpo();

	return 0;
}
