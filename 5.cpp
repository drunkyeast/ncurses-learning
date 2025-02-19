#include <ncurses.h>
#include <string>

int main(int argc, char* argv[])
{
    initscr();
    noecho();
    cbreak();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW * inputwin = newwin(3, xMax - 12, yMax - 5, 5);
    box(inputwin, 0, 0);
    refresh();
    wrefresh(inputwin);

    keypad(inputwin, true);
    int c = wgetch(inputwin);
    if (c == KEY_UP)
    {
        mvwprintw(inputwin, 1, 1, "You pressed up!");
        wrefresh(inputwin);
    }
    else
    {
        mvwprintw(inputwin, 1, 1, "You pressed %c", c);
        wrefresh(inputwin);
    }

    getch();
    endwin();
    return 0;
}