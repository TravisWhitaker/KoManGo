#include <wchar.h>
#include <main.h>

/*
┌─┬─┐   TL T TR
├─┼─┤	L  M  R
└─┴─┘   BL B BR
● BLACK
○ WHITE
─ DASH
★ STAR
*/

wchar_t TL =  0x250C ;
wchar_t T =  0x252C ;
wchar_t TR =  0x2510 ;
wchar_t L =  0x251C ;
wchar_t M =  0x253C ;
wchar_t R =  0x2524 ;
wchar_t BL =  0x2514 ;
wchar_t B =  0x2534 ;
wchar_t BR =  0x2518 ;
wchar_t DASH =  0x2500 ;
wchar_t BLACK =  0x25CF ;
wchar_t WHITE =  0x25CB ;
wchar_t STAR =  0x2605 ;

void initLogicBoard()
{
	for(int r = 1; r < DIM-1; r++) //All the intersections
	{
		for(int c = 1; c < DIM-1; c++)	
			logicBoard[r][c] = M;
	}

	for(int c = 0; c < DIM; c++) 
	{
		logicBoard[0][c] = T;		// Top tiles
		logicBoard[DIM-1][c] = B;	//Bottom tiles
	}

	for(int r = 0; r < DIM; r++)
	{
		logicBoard[r][0] = L; 	//Left tiles
		logicBoard[r][DIM-1] = R; //Right tiles
	}

	logicBoard[0][0] = TL; 		//Top Left corner
	logicBoard[0][DIM-1] = TR; 	//Top right corner
	logicBoard[DIM-1][0] = BL; 	//Bottom left corner
	logicBoard[DIM-1][DIM-1] = BR; //Bottom right corner

	return;
}

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
