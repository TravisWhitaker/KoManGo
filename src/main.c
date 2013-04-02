#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include <locale.h>

#include <screen.h>
#include <board.h>
#include <main.h>

int main(int argc,char *argv[])
{

	setlocale(LC_ALL,""); //This makes Unicode work.

	int screenRows; //Globally store the number of rows and cols of the screen.
	int screenCols;
	int *screenRowsP;
	int *screenColsP;
	screenRowsP = &screenRows;
	screenColsP = &screenCols; //Make pointers to these so other functions can update them.

	int DIM = 19;
	if(argc > 1)
	{
		int DIMinput = atoi(argv[1]);
		if(DIMinput > 0 && DIMinput <= 19)
		{
			DIM = DIMinput;
		}
	}

	board gameBoard = initBoard(DIM); //Initialize the board.

	*(gameBoard.rows[3]+3) = '1'; //Harcode this for now.
	*(gameBoard.rows[3]+4) = '2';

	initScreen(screenRowsP,screenColsP);

	printBoard(gameBoard,screenRows,screenCols);
	homeCursor(DIM,screenRows,screenCols);

	char ch;

	while(1)
	{
		ch = getch();
		if(ch == 27)
		{
			break;
		}
		else if(moveCursor(DIM,screenRows,screenCols,ch) == 1);
		else if(clearBoard(gameBoard,ch) == 1);
		else if(ch == -102)
		{
			resize(gameBoard,DIM,screenRowsP,screenColsP);
			continue;
		}
		redraw(gameBoard,screenRows,screenCols);
	}

	ggpo();

	return 0;
}
