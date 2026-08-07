#include "curses.h"

int mvaddch(int y, int x, const char ch) {
  volatile unsigned short *vga = (volatile unsigned short *)0xB8000;

  int offset = 80*y + x;
  vga[offset] = 0x0F00 | ch; /* 0x0F00 is white on black */
}

void initscr() {
  for (int y = 0; y < LINES; y++)
      for (int x = 0; x < COLS; x++)
         mvaddch(y, x, ' ');
}