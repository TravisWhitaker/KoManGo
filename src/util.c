#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

void initialize()
{
	initscr();
	raw();
	noecho();
	keypad(stdscr,TRUE);
	return;
}

void goodgamepeaceout()
{
	endwin();
	printf("Good game peace out.\n");
	return;
}
