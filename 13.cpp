#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define ctrl(x) (x & 0x1F)
// ASCII码表中，A-Z的字符对应的数值是0x41到0x5A（大写），而小写a-z是0x61到0x7A。当用户按下Ctrl键加上一个字母时，传统的处理方式是将该字母的ASCII码减去0x40，例如Ctrl+A对应的是1，Ctrl+B是2
// 大写字母 A 的 ASCII 码是 0x41，二进制为 01000001, 与 0x1F（二进制 00011111）后，结果为 00000001（即 0x01）
// 小写字母 a 的 ASCII 码是 0x61，二进制为 01100001，与 0x1F 运算后也得到 0x01。
// ctrl+A的ASCII码是'A'-0x40 = 0x01, ctrl+a与ctrl+shift+a都是一样的. 但是'a'或'A', 与0x1F的&运算都是0x1即ctrl+a

// ncurses似乎无法检测ctrl+shift+a, 都会被识别成ctrl+A键, shift+a是A这个可以识别.
int main(int argc, char* argv[])
{
    initscr();
    noecho();
    char ch;
    while(ch = getch())
    {
        move(0, 0);
        clrtoeol(); // 这两行是: 移动到0,0 然后清空这一行

        mvprintw(1, 0, "KEY NAME : %s - 0x%02x\n", keyname(ch), ch);
        if (ch == ctrl('a')) // 0x1F是屏蔽前3位, 保留后5位.
        {
            mvprintw(0, 0, "Detected ctrl + a");
        }
        refresh();

    }


    endwin();
    return 0;
}