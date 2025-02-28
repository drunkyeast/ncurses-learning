#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <curses.h>
#include "menu.h"

using namespace std;

int main(int argc, char* argv[]) 
{
    initscr();
    noecho();
    curs_set(0);

    if (!has_colors())
    {
        printf("this tty/Terminal is not support color\n");
        return -1;
    }
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *win = newwin(yMax / 2, xMax / 2, yMax / 4, xMax / 4);
    box(win, 0, 0);

    string menu1[] = {"New", "Open", "Save", "Exit"};
    string menu2[] = {"Copy", "Cut", "Paste"};
    string menu3[] = {"Sidebar", "Terminal"};
    const int menus_size = 3;
    Menu menus[3]{
        Menu{"File", 'f', menu1, 4},
        Menu{"Edit", 'e', menu2, 3},
        Menu("Options", 'o', menu3, 2),
    };
    MenuBar menubar = MenuBar(win, menus, menus_size);
    menubar.draw();

    char ch;
    while(ch = wgetch(win))
    {
      menubar.handleTrigger(ch);
      menubar.draw();
    }

    // wrefresh(win);
    wgetch(win);

    endwin();
    return 0;
}