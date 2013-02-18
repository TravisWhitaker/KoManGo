#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include <locale.h>

#include <screen.h>
#include <board.h>
#include <main.h>


int main()
{

	setlocale(LC_ALL,""); //This makes Unicode work.

	int screenRows; //Globally store the number of rows and cols of the screen.
	int screenCols;
	int *screenRowsP;
	int *screenColsP;
	screenRowsP = &screenRows;
	screenColsP = &screenCols; //Make pointers to these so other functions can update them.

	const int DIM = 19;

	board gameBoard = initBoard(DIM);

	*(gameBoard.rows[3]+3) = '1';

	initScreen(screenRowsP,screenColsP);

	printBoard(gameBoard,screenRows,screenCols);
	homeCursor(DIM,screenRows,screenCols);

	int boardX;
	int boardY;
	int oldX;
	int oldY;

	logicalCursor(DIM,screenRows,screenCols,&boardX,&boardY);

	while(1)
	{
		getmaxyx(stdscr,*screenRowsP,*screenColsP);
		char ch = getch();
		if(ch == 27)
		{
			break;
		}
		if(ch == 'r')
		{
			getyx(stdscr,oldY,oldX);
			clear();
			printBoard(gameBoard,screenRows,screenCols);
			move(oldY,oldX);
		}
		moveCursor(DIM,screenRows,screenCols,ch);
		logicalCursor(DIM,screenRows,screenCols,&boardY,&boardX);
		getyx(stdscr,oldY,oldX);
		move(0,0);
		printw("Lobic board row: %i\n",boardY);
		printw("Lobic board col: %i\n",boardX);
		move(oldY,oldX);
		printBoard(gameBoard,screenRows,screenCols);
	}

	ggpo();

	return 0;
}
