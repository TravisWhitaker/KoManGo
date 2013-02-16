/*
┌─┬─┬─┬─┐   12223
├─●─○─★─┤	4BA06
├─┼─○─┼─┤	45A56
├─●─┼─★─┤	4B506
└─┴─┴─┴─┘	78889
*/



int DIM = 19;

char board[DIM][DIM];

for(r = 0, r < DIM, r++) //Everything is intersections
{
	for(c = 0, c < DIM, c++)	
		board[i][j] = 0
}

for(c = 0, c < DIM, c++) 
{
	board[0][c] = 2		// Top tiles
	board[DIM-1][c] = 8	//Bottom tiles
}

for(r = 0, c < DIM, c++)
{
	board[r][0] = 4 	//Left tiles
	board[r][DIM-1] = 6 //Right tiles
}

board[0][0] = 1 		//Top Left corner
board[0][DIM-1] = 3 	//Top right corner
board[DIM-1][0] = 7 	//Bottom left corner
board[DIM-1][DIM-1] = 9 //Bottom right corner