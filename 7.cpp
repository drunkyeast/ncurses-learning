#include <ncurses.h>
// 前一节讲的是refresh和wrefresh的问题, 没什么好说的, 它会比较智能, 一个符号改变不会全部overwrite
// 这一节讲的是input mode, getch是阻塞还是延迟多久.
int main(int argc, char* argv[])
{
    initscr();
    // cbreak();
    // halfdelay(5); // 5对应0.5秒. 让while()中的getch延迟0.5秒. 且不是阻塞等待
    // nodelay(stdscr, true); // 让getch()不阻塞.
    timeout(500); // -1表示无限长. 0就相当于nodelay. 500表示0.5秒.

    int c;
    while((c = getch()) != 'x')
    {
        printw("%d\n", c);
    }

    endwin();
    return 0;
}