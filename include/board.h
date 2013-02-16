#ifndef BOARD
#define BOARD

wchar_t TL = "\u250C";$
wchar_t T = "\u252C";$
wchar_t TR = "\u2510";$
wchar_t L = "\u251C";$
wchar_t M = "\u253C";$
wchar_t R = "\u2524";$
wchar_t BL = "\u2514";$
wchar_t B = "\u2534";$
wchar_t BR = "\u2518";$
wchar_t DASH = "\u2500";$
wchar_t BLACK = "\u25CF";$
wchar_t WHITE = "\u25CB";$
wchar_t STAR = "\u2605";

wchar_t *initBoard(int DIM);
wchar_t *printBoard(int DIM, wchar_t *board);

#endif
