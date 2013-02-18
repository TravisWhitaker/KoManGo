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
	int *screenRowsP;
	int *screenColsP;
	screenRowsP = &screenRows;
	screenColsP = &screenCols;

	const int DIM = 19;

	board gameBoard = initBoard(DIM);

	for(register int i=0;i<(DIM*DIM);i++)
	{
		*(gameBoard.grid+i) = '1';
	}

	initScreen(screenRowsP,screenColsP);

	while(1)
	{
		getmaxyx(stdscr,*screenRowsP,*screenColsP);
		printBoard(gameBoard,screenRows,screenCols);
		char ch = getch();
		if(ch == 'q')
		{
			break;
		}
		clear();
	}

	ggpo();

	return 0;
}
