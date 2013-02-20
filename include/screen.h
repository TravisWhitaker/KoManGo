#ifndef SCREEN
#define SCREEN

#include <board.h>

void initScreen(int* screenRowsP, int* screenColsP);
void homeCursor(int DIM, int screenRows, int screenCols);
int moveCursor(int dim, int screenRows, int screenCols, char key);
void resize(board gameBoard, int dim, int* screenRows, int* screenCols);
int queryUserDIM();
void ggpo();

#endif
