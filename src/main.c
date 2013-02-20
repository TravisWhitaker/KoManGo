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

	// *(gameBoard.rows[3]+3) = '1';

	initScreen(screenRowsP,screenColsP);

	printBoard(gameBoard,screenRows,screenCols);
	homeCursor(DIM,screenRows,screenCols);

	int boardX;
	int boardY;
	int oldX;
	int oldY;
	unsigned long int hash;

	logicalCursor(DIM,screenRows,screenCols,&boardX,&boardY);
	int turn = 1;
	while(1)
	{
		getmaxyx(stdscr,*screenRowsP,*screenColsP);
		char ch = getch();
		if(ch == 'o')
		{
			clearBoard(gameBoard);

		}
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
		if(ch == 'p')
		{
			if(turn == 1)
			{
				*(gameBoard.rows[boardY]+boardX) = '1';
				turn = 2;
			}
			else
			{
				*(gameBoard.rows[boardY]+boardX) = '2';	
				turn = 1;
			}

		}

		printBoard(gameBoard,screenRows,screenCols);
		getyx(stdscr,oldY,oldX);
		move(2,0);
		hash = hashbrowns(gameBoard);
		// printw("Hash: %i",hash);
		// printw("                ");
		move(oldY,oldX);
	}

	ggpo();

	return 0;
}
