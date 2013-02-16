#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include <screen.h>

int main()
{
	initialize();
	int counter = 0;
	int ch;
	while(counter<10)
	{
		ch = getch();
		if(ch == '\n')
		{
			printw("ENTER\n");
		}
		else
		{
			printw("Ya bimbooo %c\n",ch);
		}
		counter++;
	}
	ggpo();
	return 0;
}
