#ifndef SCREEN
#define SCREEN

void initScreen(int* screenRowsP, int* screenColsP);
void homeCursor(int DIM, int screenRows, int screenCols);
int moveCursor(int dim, int screenRows, int screenCols, char key);
void ggpo();

#endif
