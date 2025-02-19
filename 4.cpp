#include <ncurses.h>

int main(int argc, char* argv[])
{
    initscr();
    noecho();
    cbreak();

    int y, x, yBeg, xBeg, yMax, xMax;
    getyx(stdscr, y, x);
    getbegyx(stdscr, yBeg, xBeg);
    getmaxyx(stdscr, yMax, xMax);
    printw("%d %d %d %d %d %d", y, x, yBeg, xBeg, yMax, xMax);

    
    WINDOW * win = newwin(10, 20, 5, 10); // height,width,star_y, star_x
    refresh();
    box(win, 0, 0);
    getyx(win, y, x); // 获得当前光标相对于整个stdscr的位置???
    // 注意: 这里我搞得有些混乱, 但没有时间没有必要去仔细探索, 知道又这几个函数好了.
    getbegyx(win, yBeg, xBeg); // 获得win相对于整个stdscr的起始位置???
    getmaxyx(win, yMax, xMax);
    mvwprintw(stdscr, yBeg, xBeg, "%d %d %d %d %d %d", y, x, yBeg, xBeg, yMax, xMax);
    wrefresh(win);
    



    getch();
    endwin();
    return 0;
}