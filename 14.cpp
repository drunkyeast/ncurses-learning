#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ncurses.h>

using namespace std;

int main(int argc, char* argv[]) 
{
    initscr();
    noecho();
    curs_set(0);
    

    endwin();
    return 0;
}