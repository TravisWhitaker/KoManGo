#include <wchar.h>

/*
┌─┬─┐   TL T TR
├─┼─┤	L  M  R
└─┴─┘   BL B BR
● BLACK
○ WHITE
─ DASH
★ STAR
*/

wchar_t TL = '\u250C';
wchar_t T = '\u252C';
wchar_t TR = '\u2510';
wchar_t L = '\u251C';
wchar_t M = '\u253C';
wchar_t R = '\u2524';
wchar_t BL = '\u2514';
wchar_t B = '\u2534';
wchar_t BR = '\u2518';
wchar_t DASH = '\u2500';
wchar_t BLACK = '\u25CF';
wchar_t WHITE = '\u25CB';
wchar_t STAR = '\u2605';

wchar_t *initBoard(int DIM)
{
	wchar_t board[DIM][DIM];
	for(int r = 0; r < DIM; r++) //Everything is intersections
	{
		for(int c = 0; c < DIM; c++)	
			board[r][c] = M;
	}

	for(int c = 0; c < DIM; c++) 
	{
		board[0][c] = T;		// Top tiles
		board[DIM-1][c] = B;	//Bottom tiles
	}

	for(int r = 0; c < DIM; c++)
	{
		board[r][0] = L; 	//Left tiles
		board[r][DIM-1] = R; //Right tiles
	}

	board[0][0] = TL; 		//Top Left corner
	board[0][DIM-1] = TR; 	//Top right corner
	board[DIM-1][0] = BL; 	//Bottom left corner
	board[DIM-1][DIM-1] = BR; //Bottom right corner

	return board;
}

wchar_t *printBoard(int DIM, wchar_t *board)
{
	wchar_t returnArray[DIM][2*DIM-1];
	for(int r = 0; r < DIM; r++)
	{
		for(int c = 0; c < 2*DIM-1; c++)
		{
			returnArray[r][c] = DASH; //Initialize the return array with dashes
		}
	}

	for(int r = 0; r < DIM; r++)
	{
		for(int c = 0; c < DIM; c++)	
		{
			returnArray[r][c*2] = board[r][c]; //Populate the return array with values from board
		}
	}

	return returnArray;
}
