#include <stdio.h>
#include <stdlib.h>
#include <ncursesw/ncurses.h>

#include <main.h>
#include <board.h>
#include <screen.h>

/*
┌─┬─┐   TL T TR
├─┼─┤	L  M  R
└─┴─┘   BL B BR
● BLACK
○ WHITE
─ DASH
★ STAR
*/

char *TL =  "\u250C" ;
char *T =  "\u252C" ;
char *TR =  "\u2510" ;
char *L =  "\u251C" ;
char *M =  "\u253C" ;
char *R =  "\u2524" ;
char *BL =  "\u2514" ;
char *B =  "\u2534" ;
char *BR =  "\u2518" ;
char *DASH =  "\u2500" ;
char *BLACK =  "\u25CF" ;
char *WHITE =  "\u25EF" ;
char *STAR =  "\u2605" ;

board initBoard(int dim)
{
	const int DIM = dim;
	const int size = DIM*DIM;
	board output;
	output.DIM = DIM;
	output.grid = malloc((sizeof(char)*size)); //Allocate the memory for the grid.
	if(output.grid == NULL) //Check to see if the allocation failed.
	{
		printf("Malloc failed, ya bimboooo.\n");
		exit(0);
	}
	for(register int i=0; i<size; i++) //Fill the grid with zeros.
	{
		*(output.grid+i) = '0';
	}
	for(register int i=0; i<DIM; i++) //Initialize our array of row pointers.
	{
		output.rows[i] = (output.grid+(DIM*i));
	}

	return output;
}

void printBoard(board a, int screenRows, int screenCols)
{
	const int DIM = a.DIM;
	const int size = DIM*DIM;
	int TLRow;
	int TLCol;
	if((screenRows < DIM*2) || (screenCols < DIM*2))
	{
		TLRow = 2;
		TLCol = 2;
	}
	else
	{
		TLRow = (screenRows/2)-((DIM)/2);
		TLCol = (screenCols/2)-(((2*DIM)-1)/2);
	}
	volatile register char spot;
	for(register int i = 0; i<DIM; i++)
	{
		for(register int j = 0; j<DIM; j++)
		{
			spot = *(a.rows[i]+j);
			if(spot == '0')
			{
				if(i == 0)
				{
					if(j == 0)
					{
						mvprintw(TLRow,TLCol,"%s",TL);
					}
					else if (j == (DIM-1))
					{
						printw("%s",TR);
					}
					else
					{
						printw("%s",T);
					}
				}
				else if(i == (DIM-1))
				{
					if(j == 0)
					{
						mvprintw(TLRow+(DIM-1),TLCol,"%s",BL);
					}
					else if (j == (DIM-1))
					{
						printw("%s",BR);
					}
					else
					{
						printw("%s",B);
					}
				}
				else
				{
					if(j == 0)
					{
						mvprintw(TLRow+i,TLCol,"%s",L);
					}
					else if(j == (DIM-1))
					{
						printw("%s",R);
					}
					else
					{
						printw("%s",M);
					}
				}
			}
			else if (spot == '1')
			{
				mvprintw(TLRow+i,TLCol+((2*j)),"%s",BLACK);
			}
			else if (spot == '2')
			{
				mvprintw(TLRow+i,TLCol+((2*j)),"%s",WHITE);
			}
			else
			{
				mvprintw(TLRow+i,TLCol+((2*j)),"%c","X");
			}
			if(j < (DIM-1))
			{
				if((*(a.rows[i]+j)!='0') && (*(a.rows[i]+j+1)!='0'))
				{
					printw(" ");
				}
				else
				{
					printw("%s",DASH);
				}
			}
		}
		printw("\n");
	}
	return;
}
