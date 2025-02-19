#include <ncurses.h>

int main(int argc, char* argv[])
{
    // initializes the screen
    // sets up memory and clear the screen
    initscr(); 

    int x = 10, y = 20;
    move(x, y);

    printw("Hello World!");

    
    refresh(); // refreshes the screen to match whats in memory

    int c = getch();
    clear();

    move(0, 0);
    printw("%d", c); 
    // mvprintw(0, 0, "%d", c);

    refresh(); // 刷新屏幕，将缓冲区内容显示到屏幕上

    

    getch();

    endwin();
    // deallocates memory and ends ncurses

    return 0;
}