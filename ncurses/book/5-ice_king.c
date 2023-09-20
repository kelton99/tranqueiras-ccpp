#include <ncurses.h>

int main(void)
{
	int ice_king = 1047;
	int ss = 65;

	initscr();
	printw("Ice King is %d years old\n", ice_king);
	printw("He has collected %d years\n", ice_king - ss);
	printw("of Social Security.");
	refresh();
	getch();

	endwin();
	return 0;

}
