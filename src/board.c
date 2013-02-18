#include <stdio.h>
#include <stdlib.h>

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
char *WHITE =  "\u25CB" ;
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

void printBoard(board a)
{
	const int DIM = a.DIM;
	const int size = DIM*DIM;
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
						printf("%s",TL);
					}
					else if (j == (DIM-1))
					{
						printf("%s",TR);
					}
					else
					{
						printf("%s",T);
					}
				}
				else if(i == (DIM-1))
				{
					if(j == 0)
					{
						printf("%s",BL);
					}
					else if (j == (DIM-1))
					{
						printf("%s",BR);
					}
					else
					{
						printf("%s",B);
					}
				}
				else
				{
					if(j == 0)
					{
						printf("%s",L);
					}
					else if(j == (DIM-1))
					{
						printf("%s",R);
					}
					else
					{
						printf("%s",M);
					}
				}
			}
			else if (spot == '1')
			{
				printf("%s",BLACK);
			}
			else if (spot == '2')
			{
				printf("%s",WHITE);
			}
			else
			{
				printf("%c","X");
			}
			if(j < (DIM-1))
			{
				printf("%s",DASH);
			}
		}
		printf("\n");
	}
	return;
}

/*
void updatePrintBoard()
{
	for(int r = 0; r < DIM; r++)
	{
		for(int c = 0; c < 2*DIM-1; c++)
		{
			printableBoard[r][c] = DASH; //Initialize the return array with dashes
		}
	}

	for(int r = 0; r < DIM; r++)
	{
		for(int c = 0; c < DIM; c++)	
		{
			printableBoard[r][c*2] = logicBoard[r][c]; //Populate the return array with values from board
		}
	}

	return;
}
*/

/*
void printBoard()
{
	for(int r = 0;r < DIM;r++)
	{
		printf("%s\n",printableBoard[r])
	}
}
*/
