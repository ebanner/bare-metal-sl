void write_char(void) {
    /* mvaddch(0, 0, 'A'); */

    volatile unsigned short *vga = (volatile unsigned short *)0xB8000;
    
    vga[0] = 0x0F00 | 'E'; /* 0x0F00 is white on black */

    vga[80] = 0x0F00 | 'D'; /* 0x0F00 is white on black */

    // volatile unsigned char *vga = (volatile unsigned char *)0xB8000;

    // vga[0] = 'A';   /* character */
    // vga[1] = 0x0F;  /* white on black */

    // vga[160] = 'E';   /* character */
    // vga[161] = 0x0F;   /* character */
}
