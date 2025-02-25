#include <stdlib.h>
// #include <ncurses.h> // 有何区别?
#include <curses.h>

int main(int argc, char* argv[])
{
    initscr();
    if (has_colors() == false) { endwin();  printf("color can't be used."); exit(1); }
    start_color();

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);

    attr_t emphasis = A_REVERSE | COLOR_PAIR(2); // emphasis就是强调, 名词.
    attron(emphasis);
    mvaddch(5, 5, 'a');
    mvaddch(5, 6, 'b');
    mvaddch(5, 7, 'c');
    attroff(emphasis);

    attron(COLOR_PAIR(2));
    mvaddch(7, 5, 'a');
    mvaddch(7, 6, 'b');
    mvaddch(7, 7, 'c');
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(1));
    mvaddch(9, 5, 'a');
    mvaddch(9, 6, 'b');
    mvaddch(9, 7, 'c');
    attroff(COLOR_PAIR(1));

    attron(A_REVERSE | COLOR_PAIR(1));
    mvaddch(11, 5, 'a');
    mvaddch(11, 6, 'b');
    mvaddch(11, 7, 'c');
    attroff(A_REVERSE | COLOR_PAIR(1));

    chtype c = 'a' | A_REVERSE | COLOR_PAIR(1);
    mvaddch(13, 5, c);

    // 这个不加就会出一些bug, 😀
    getch();
    endwin();
    return 0;
}