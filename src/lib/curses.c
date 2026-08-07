int mvaddch(int y, int x, const char ch) {
  volatile unsigned short *vga = (volatile unsigned short *)0xB8000;

  int offset = 80*y + x;
  vga[offset] = 0x0F00 | ch; /* 0x0F00 is white on black */
}