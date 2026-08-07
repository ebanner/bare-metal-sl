#include <curses.h>

void write_welcome_message(void) {
    mvaddch(0, 0,  'W');
    mvaddch(0, 1,  'e');
    mvaddch(0, 2,  'l');
    mvaddch(0, 3,  'c');
    mvaddch(0, 4,  'o');
    mvaddch(0, 5,  'm');
    mvaddch(0, 6,  'e');
    mvaddch(0, 7,  ' ');
    mvaddch(0, 8,  't');
    mvaddch(0, 9,  'o');
    mvaddch(0, 10, ' ');
    mvaddch(0, 11, 'E');
    mvaddch(0, 12, 'D');
    mvaddch(0, 13, 'D');
    mvaddch(0, 14, 'I');
    mvaddch(0, 15, 'E');
    mvaddch(0, 16, 'O');
    mvaddch(0, 17, 'S');
    mvaddch(0, 18, '.');
}
