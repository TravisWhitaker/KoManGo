#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncursesw/ncurses.h>
#include <wchar.h>

#include <main.h>
#include <screen.h>
#include <board.h>

void initScreen(int* screenRowsP, int* screenColsP)
{
	initscr();
	raw();
	noecho();
	keypad(stdscr,TRUE);
	getmaxyx(stdscr,*screenRowsP,*screenColsP);
	return;
}

void ggpo()
{
	endwin();
	printf("Good game, peace out.\n");
	return;
}
