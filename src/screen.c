#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <wchar.h>

#include <main.h>
#include <screen.h>
#include <board.h>

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
