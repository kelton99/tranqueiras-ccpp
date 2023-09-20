#include <ncurses.h>

int main(void)
{
	initscr();

	attron(A_BLINK);
	addstr("Flash a-ah\n");
	attroff(A_BLINK);

	attron(A_BOLD);
	addstr("Savior of the Universe\n");
	attron(A_BLINK);
	addstr("Flash a-ah\n");
	attroff(A_BLINK);
	addstr("He'll save every one of us\n");
	attron(A_BLINK);
	addstr("Flash a-ah\n");
	addstr("He is a miracle");

	refresh();
	getch();
	endwin();
	return 0;
}
