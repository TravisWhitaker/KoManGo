#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

int screenrows;
int screencols;
//int *screenrowp;
//int *screencolp;

void initialize()
{
	initscr();
	raw();
	noecho();
	keypad(stdscr,TRUE);
	getmaxyx(stdscr,screenrows,screencols);
	return;
}

void ggpo()
{
	endwin();
	printf("Good game, peace out.\n");
	return;
}
