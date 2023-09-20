#include <ncurses.h>

int main(void)
{
	char text[] = "Dr. Strangelove or: How I Learned to Stop Worrying and Love the Bomb";
	char *t;

	initscr();
	t = text;

	while(*t){
		addch(*t);
		t++;
		refresh();
		napms(75);
	}
	getch();
	endwin();
	return 0;
}
