#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncursesw/ncurses.h>

#include <main.h>
#include <screen.h>
#include <board.h>

void initScreen(int* screenRowsP, int* screenColsP)
{
	initscr();
	raw();
	noecho();
	keypad(stdscr,TRUE);
	getmaxyx(stdscr,*screenRowsP,*screenColsP);
	return;
}

void homeCursor(int DIM, int screenRows, int screenCols)
{
	move((screenRows/2)-(DIM/2),(screenCols/2)-(((2*DIM)-1)/2));
	refresh();
	return;
}

int moveCursor(int dim, int screenRows, int screenCols, char key)
{
	const int DIM = dim;
	int currentRow,currentCol;
	getyx(stdscr,currentRow,currentCol);
	if((key == 'w') || (key == 3))
	{
		if(currentRow > (screenRows/2)-(DIM/2))
		{
			move(currentRow-1,currentCol);
			refresh();
			return 1;
		}
	}
	else if((key == 'a') || (key == 4))
	{
		if(currentCol > (screenCols/2)-(((2*DIM)-1)/2))
		{
			move(currentRow,currentCol-2);
			refresh();
			return 1;
		}
	}
	else if((key == 's') || (key == 2))
	{
		if(currentRow < (screenRows/2)-(DIM/2)+DIM)
		{
			move(currentRow+1,currentCol);
			refresh();
			return 1;
		}
	}
	else if((key == 'd') || (key == 5))
	{
		if(currentCol < (screenCols/2)-(((2+DIM)-1)/2)+DIM)
		{
			move(currentRow,currentCol+2);
			refresh();
			return 1;
		}
	}
	return 0;
}

void ggpo()
{
	endwin();
	printf("Good game, peace out.\n");
	return;
}
