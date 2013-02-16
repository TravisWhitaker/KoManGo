#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <wchar.h>

int screenRows;
int screenCols;

void initScreen()
{
	initscr();
	raw();
	noecho();
	keypad(stdscr,TRUE);
	getmaxyx(stdscr,screenRows,screenCols);
	return;
}

void ggpo()
{
	endwin();
	printf("Good game, peace out.\n");
	return;
}
