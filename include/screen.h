#ifndef SCREEN
#define SCREEN

void initScreen(int* screenRowsP, int* screenColsP);
void homeCursor(int DIM, int screenRows, int screenCols);
void moveCursor(int dim, int screenRows, int screenCols, char key);
void ggpo();

#endif
