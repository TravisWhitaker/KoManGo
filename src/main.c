#include <stdio.h>
#include <stdlib.h>
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

	const int DIM = queryUserDIM(); //Politely ask the user how large they'd like the board to be.
	if(DIM == 0)
	{
		return 0;
	}

	board gameBoard = initBoard(DIM); //Initialize the board.

	*(gameBoard.rows[3]+3) = '1'; //Harcode this for now.

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
		else
		{
			resize(gameBoard,DIM,screenRowsP,screenColsP);
		}
	}

	ggpo();

	return 0;
}
