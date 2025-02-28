#include <curses.h>
#include <string>

#ifndef _MENU_H_
#define _MENU_H_

class Menu
{
public:
    Menu(std::string text, char trigger, std::string* items, int num_items)
    {
        this->text = text;
        this->trigger = trigger;
        this->items = items;
        this->num_items = num_items;
    }
    int start_x;
    std::string text;
    char trigger;

    std::string* items;
    int num_items;
    int selected_item;

    void selectNextItem()
    {
        selected_item ++;
        if (selected_item >= num_items)
        {
            selected_item = 0;
        }
    }
    void selectPreItem()
    {
        selected_item -- ;
        if (selected_item < 0)
        {
            selected_item = num_items - 1;
        }

    }
};

class MenuBar
{
public:
    MenuBar(WINDOW *win, Menu *menus, int num_menus)
    {
        this->win = win;
        this->menus = menus;
        this->num_menus = num_menus;
        this->selected_menu = -1;

        int yMax, xMax, yBeg, xBeg;
        getmaxyx(win, yMax, xMax);
        getbegyx(win, yBeg, xBeg);
        menuwin = newwin(yMax - 2, xMax - 2, yBeg + 1, xBeg + 1);
        keypad(menuwin, true); // 允许使用特殊键, 如上下左右, F1~F12
        wrefresh(menuwin);

        int current_pos = 2;
        for (int i = 0; i < num_menus; i ++)
        {
            this->menus[i].start_x = current_pos;
            current_pos += menus[i].text.size() + 1;
        }
    }

    void reset()
    {
        for (int i = 0; i < num_menus; i ++)
        {
            int start_x = menus[i].start_x;
            const char* text = menus[i].text.c_str();
            mvwprintw(win, 0, start_x, text);
        }
        wrefresh(win);
    }

    void draw()
    {
        for (int i = 0; i < num_menus; i ++)
        {
            int start_x = menus[i].start_x;
            const char* text = menus[i].text.c_str();
            if (selected_menu == i)
                wattron(win, A_STANDOUT);
            mvwprintw(win, 0, start_x, text);
            wattroff(win, A_STANDOUT);
        }
        selected_menu = -1;
    }

    void handleTrigger(char trigger)
    {
        for (int i = 0; i < num_menus; i ++)
        {
            if (trigger == menus[i].trigger)
            {
                selected_menu = i;
                // return ; // draw()函数会进行处理.
            }
        }
        // selected_menu = -1;
    }

    WINDOW *menuwin;
    WINDOW *win;
    Menu *menus;
    int num_menus;
    int selected_menu;
};


#endif