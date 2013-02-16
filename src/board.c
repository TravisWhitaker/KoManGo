<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include <screen.h>

/*
┌─┬─┬─┬─┐   12223
├─●─○─★─┤	4BA06
├─┼─○─┼─┤	45A56
├─●─┼─★─┤	4B506
└─┴─┴─┴─┘	78889
=======
#include <wchar.h>
>>>>>>> Board dickery

/*
┌─┬─┐   TL T TR
├─┼─┤	L  M  R
└─┴─┘   BL B BR
● BLACK
○ WHITE
─ DASH
★ STAR


*/

char *initBoard(int DIM)
{
	char board[DIM][DIM];
	for(r = 0; r < DIM; r++) //Everything is intersections
	{
		for(c = 0; c < DIM; c++)	
			board[i][j] = 0;
	}

	for(c = 0; c < DIM; c++) 
	{
		board[0][c] = 2;		// Top tiles
		board[DIM-1][c] = 8;	//Bottom tiles
	}

	for(r = 0; c < DIM; c++)
	{
		board[r][0] = 4; 	//Left tiles
		board[r][DIM-1] = 6; //Right tiles
	}

	board[0][0] = 1; 		//Top Left corner
	board[0][DIM-1] = 3; 	//Top right corner
	board[DIM-1][0] = 7; 	//Bottom left corner
	board[DIM-1][DIM-1] = 9; //Bottom right corner

	return board;
}

wchar_t *printBoard(char *board)
{
	wchar_t TL = "\u250C";
	wchar_t T = "\u252C";
	wchar_t TR = "\u2510";
	wchar_t L = "\u251C";
	wchar_t M = "\u253C";
	wchar_t R = "\u2524";
	wchar_t BL = "\u2514";
	wchar_t B = "\u2534";
	wchar_t BR = "\u2518";
	wchar_t D = "\u2500";
	wchar_t BLACK = "\u25CF";
	wchar_t WHITE = "\u25CB";
	wchar_t STAR = "\u2605";


<<<<<<< HEAD
board[0][0] = 1 		//Top Left corner
board[0][DIM-1] = 3 	//Top right corner
board[DIM-1][0] = 7 	//Bottom left corner
board[DIM-1][DIM-1] = 9 //Bottom right corner
=======
	wchar_t returnArray[DIM][2*DIM-1];
	for(r = 0; r < DIM; r++)
	{
		for(c = 0; c < 2*DIM-1; c++)
		{
			returnArray[r][c] = DASH; //Initialize the return array with dashes
		}
	}

	for(r = 0; r < DIM; r++)
	{
		for(c = 0; c < DIM; c++)	
		{
			returnArray[r][c*2] = board[r][c]; //Populate the return array with values from board
		}
	}

	return returnArray;
}
>>>>>>> Board dickery
