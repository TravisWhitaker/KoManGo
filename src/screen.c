#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include <main.h>
#include <screen.h>
#include <board.h>

void initScreen(int* screenRowsP, int* screenColsP)
{
	initscr();
	raw();
	noecho();
	keypad(stdscr,TRUE);
/*
	start_color();
	if(init_color(COLOR_YELLOW,1000,650,560) == ERR)
	{
		printw("NOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
	}
	init_pair(1,COLOR_BLACK,COLOR_YELLOW);
	init_pair(2,COLOR_WHITE,COLOR_YELLOW);
	attron(COLOR_PAIR(1));
*/
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
	if((key == 'w') || (key == 3) || (key == 56))
	{
		if(currentRow > (screenRows/2)-(DIM/2))
		{
			move(currentRow-1,currentCol);
			refresh();
		}
		return 1;
	}
	else if((key == 'a') || (key == 4) || (key == 52))
	{
		if(currentCol > (screenCols/2)-(((2*DIM)-1)/2))
		{
			move(currentRow,currentCol-2);
			refresh();
		}
		return 1;
	}
	else if((key == 's') || (key == 2) || (key == 50))
	{
		if(currentRow < (screenRows/2)-(DIM/2)+DIM-1)
		{
			move(currentRow+1,currentCol);
			refresh();
		}
		return 1;
	}
	else if((key == 'd') || (key == 5) || (key == 54))
	{
		if(currentCol < (screenCols/2)-DIM+((DIM*2)-1))
		{
			move(currentRow,currentCol+2);
			refresh();
		}
		return 1;
	}
	else if((key == 'q') || (key == 55))
	{
		if((currentCol > (screenCols/2)-((2*DIM)-1)/2) 
			&& (currentRow > (screenRows/2)-(DIM/2)))		
		{		
			move(currentRow-1,currentCol-2);
		}
		else
		{
			if(currentCol > (screenCols/2)-((2*DIM)-1)/2)
			{
				move(currentRow,currentCol-2);
			}
			else if (currentRow > (screenRows/2)-(DIM/2))
			{
				move(currentRow-1,currentCol);
			}
		}
		refresh();
		return 1;
	}
	else if((key == 'e') || (key == 57))
	{
		if ((currentRow > (screenRows/2)-(DIM/2))
			&& (currentCol < (screenCols/2)-DIM+((DIM*2)-1)))
		{
			move(currentRow-1,currentCol+2);
		}
		else
		{
			if(currentCol < (screenCols/2)-DIM+((DIM*2)-1))
			{	
			move(currentRow,currentCol+2);
			}
			if(currentRow > (screenRows/2)-(DIM/2))
			{
			move(currentRow-1,currentCol);
			}
		}
		refresh();
		return 1;
	}	
	else if((key == 'z') || (key == 49))
	{
		if((currentCol > (screenCols/2)-(((2*DIM)-1)/2))
			&& (currentRow < (screenRows/2)-(DIM/2)+DIM-1))
		{
			move(currentRow+1,currentCol-2);
		}
		else
		{
			if(currentCol > (screenCols/2)-(((2*DIM)-1)/2))
			{
				move(currentRow,currentCol-2);
			}
			if(currentRow < (screenRows/2)-(DIM/2)+DIM-1)
			{
				move(currentRow+1,currentCol);
			}
		}
		refresh();
		return 1;
	}
	else if((key == 'c') || (key == 51))
	{
		if((currentRow < (screenRows/2)-(DIM/2)+DIM-1)
			&& (currentCol < (screenCols/2)-DIM+((DIM*2)-1)))
		{
			move(currentRow+1,currentCol+2);
		}
		else
		{
			if(currentRow < (screenRows/2)-(DIM/2)+DIM-1)
			{
				move(currentRow+1,currentCol);
			}	
			if(currentCol < (screenCols/2)-DIM+((DIM*2)-1))
			{
				move(currentRow,currentCol+2);
			}
		}
		refresh();
		return 1;
	}	
	return 0;
}

void resize(board gameBoard, int DIM, int* screenRows, int* screenCols)
{
	int newScreenRows,newScreenCols,boardRow,boardCol,newCursorRow,newCursorCol;
	getmaxyx(stdscr,newScreenRows,newScreenCols);
	clear();
	refresh();
	printBoard(gameBoard,newScreenRows,newScreenCols);
	move((newScreenRows/2)-((DIM)/2),(newScreenCols/2)-(((2*DIM)-1)/2));
	*screenRows = newScreenRows;
	*screenCols = newScreenCols;
	return;
}

void redraw(board gameBoard,int screenRows,int screenCols)
{
	int DIM,cursorRow,cursorCol;
	DIM = gameBoard.DIM;
	getyx(stdscr,cursorRow,cursorCol);
	clear();
	printBoard(gameBoard,screenRows,screenCols);
	move(cursorRow,cursorCol);
	refresh();
	return;
}

int queryUserDIM()
{
	char userSays[3];
	printf("Dear Sir or Madame,\nPardon the interruption, but how large would you like one side of the board to be?\n");
	fgets(userSays,3,stdin);
	int DIM  = atoi(userSays);
	if(DIM > 50)
	{
		printf("I'm terribly sorry, but I'm afraid I just can't make the board that large. If you'll please excuse me we must part company now...\n");
		return 0;
	}
	else if (DIM == 0)
	{
		return 19;
	}
	else if(DIM < 3)
	{
		printf("I'm terribly sorry, but I'm afraid I just can't make the board that small. If you'll please excuse me we must part company now...\n");
		return 0;
	}
	return DIM;
}


void ggpo()
{
	endwin();
	printf("Good game, peace out.\n");
	return;
}
