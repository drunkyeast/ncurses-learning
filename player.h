#ifndef _PLAYER_H_
#define _PLAYER_H

#include <ncurses.h>

class Player
{
public:
    Player(WINDOW* win, int y, int x, char c);
    void mvup();
    void mvdown();
    void mvleft();
    void mvright();
    int getmv();
    void display();

private:
    int xLoc, yLoc, xMax, yMax;
    char character;
    WINDOW* curwin;
    static char trace;
};

char Player::trace = '.';

Player::Player(WINDOW* win, int y, int x, char c)
{
    curwin = win;
    yLoc = y;
    xLoc = x;
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);
    character = c;
}

void Player::mvup()
{
    mvwaddch(curwin, yLoc, xLoc, trace);
    yLoc --;
    if (yLoc < 1)
        yLoc = 1;
}

void Player::mvdown()
{
    mvwaddch(curwin, yLoc, xLoc, trace);
    yLoc ++;
    if (yLoc > yMax - 2)
        yLoc = yMax - 2;
}

void Player::mvleft()
{
    mvwaddch(curwin, yLoc, xLoc, trace);
    xLoc--;
    if (xLoc < 1)
        xLoc = 1;
}

void Player::mvright()
{
    mvwaddch(curwin, yLoc, xLoc, trace);
    xLoc ++;
    if (xLoc > xMax - 2)
        xLoc = xMax - 2;
}

int Player::getmv()
{
    int choice = wgetch(curwin);
    switch(choice)
    {
    case KEY_UP:
        mvup();
        break;
    case KEY_DOWN:
        mvdown();
        break;
    case KEY_LEFT:
        mvleft();
        break;
    case KEY_RIGHT:
        mvright();
        break;
    default:
        break;
    }
    return choice;
}

void Player::display()
{
    mvwaddch(curwin, yLoc, xLoc, character);

}

#endif
