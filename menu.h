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
            drawMenu(menus[i], selected_menu == i);
        }
        selected_menu = -1;
    }

    void drawMenu(Menu menu, bool is_selected)
    {
        int start_x = menu.start_x;
        const char* text = menu.text.c_str();
        if (is_selected)
            wattron(win, A_STANDOUT);
        mvwprintw(win, 0, start_x, text);
        wattroff(win, A_STANDOUT);
        wrefresh(win);

        int ch;
        drawMenuItems(menu);
        wrefresh(menuwin);
        while(is_selected && (ch = wgetch(menuwin)))
        {
            switch(ch)
            {
            case KEY_UP:
                menu.selectPreItem();
                break;
            case KEY_DOWN:
                menu.selectNextItem();
                break;
            default:
                is_selected = false; // 如果不按上下键, 那就关闭子菜单的显示.
                break;
            }
            drawMenuItems(menu);
        }
        werase(menuwin);
        wrefresh(menuwin);
        // wrefresh(win); // ??
        reset();
    }

    void drawMenuItems(Menu menu)
    {
        int yMax, xMax;
        getmaxyx(menuwin, yMax, xMax);
        for (int i = 0; i < menu.num_items; i ++)
        {
            mvwprintw(menuwin, i, 0, menu.items[i].c_str());
            if (menu.selected_item == i)
            {
                mvwchgat(menuwin, i, 0, xMax, A_NORMAL, 1, NULL);// move change atrribute 倒数第二个1是我之前设置的init_pair?
            }
            else
            {
                mvwchgat(menuwin, i, 0, xMax, A_STANDOUT, 0, NULL); // A_STANDOUT A_NORMAL 可以试试.
            }
        }
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