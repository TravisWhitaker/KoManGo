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

	initScreen(screenRowsP,screenColsP);

	printBoard(gameBoard,screenRows,screenCols);
	homeCursor(DIM,screenRows,screenCols);

	while(1)
	{
		getmaxyx(stdscr,*screenRowsP,*screenColsP);
		char ch = getch();
		if(ch == 'q')
		{
			break;
		}
		moveCursor(DIM,screenRows,screenCols,ch);
	}

	ggpo();

	return 0;
}
