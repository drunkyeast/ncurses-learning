#include <ncurses.h>

int main(int argc, char* argv[])
{
    initscr();
    if (!has_colors())
    {
        printw("Terminal does not support color");
        getch();
        return -1;
    }
    start_color();
    /*
    COLOR_PAIR(n)
    COLOR_BLACK     0
    COLOR_RED       1
    COLOR_GREEN     2
    COLOR_YELLOW    3
    COLOR_BLUE      4
    COLOR_MAGENTA   5
    COLOR_CYAN      6
    COLOR_WHITE     7
    */

    init_pair(1, COLOR_YELLOW, COLOR_GREEN);
    init_pair(2, COLOR_GREEN, COLOR_MAGENTA);

    attron(A_REVERSE);
    printw("Hello World!");
    attroff(A_REVERSE); 
    // 还有A_INVIS不可见, A_BOLD 等等参数. 或则用COLOR_PAIR();

    move(2, 0);
    attron(COLOR_PAIR(1));
    printw("Hello World!");
    attroff(COLOR_PAIR(1)); 

    move(4, 0);
    attron(COLOR_PAIR(2));
    printw("Hello World!");
    attroff(COLOR_PAIR(2)); 

    if (can_change_color())
    {
        move(6, 0);
        // attron(COLOR_PAIR(2));
        printw("can change color, but meaningless!");
        // attroff(COLOR_PAIR(2));
    }

    getch();

    endwin();
    return 0;
}