#ifndef BOARD
#define BOARD

typedef struct
{
	int DIM;
	char *grid;
	char *rows[19];
} board;

char* TL;
char* T;
char* TR;
char* L;
char* M;
char* R;
char* BL;
char* B;
char* BR;
char* DASH;
char* BLACK;
char* WHITE;
char* STAR;

board initBoard();
void printBoard();

#endif
