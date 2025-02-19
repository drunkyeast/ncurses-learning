#include <ncurses.h>

int main(int argc, char* argv[])
{
    initscr();

    cbreak(); // ctrl+c结束. 默认cbreak, 可以不用写.
    // raw(); // 原始模式, 终端不会对输入的ctrl+c和ctrl+z转化为信号
    noecho();

    int height = 10, width = 20;
    int start_y = 5, start_x = 10; // 这挺搞的, 不合常规.

    WINDOW * win = newwin(height, width, start_y, start_x);
    refresh();
    
    // box(win, 0, 0); // 0表示默认的横竖线.
    // box(win, 'a', 0); // wborder控制更全面.
    wborder(win, 'a', 'b', 'c', 'd', '1', '2', '3', '4');
    mvwprintw(win, 1, 1, "this is my box");
    wrefresh(win);
    
    int c = getch();

    getch();
    getch();

    endwin();
    return 0;
}