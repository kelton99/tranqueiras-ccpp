#include <ncurses.h>

int main(void)
{
	char text1[] = "Well, she turned me into a newt!\n";
	char text2[] = "A newt?!\n";
	char text3[] = "I got better";

	initscr();
	addstr(text1);
	addstr(text2);
	addstr(text3);
	refresh();
	getch();

	endwin();
	return 0;
}
