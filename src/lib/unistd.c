#include "unistd.h"

int usleep(useconds_t usec) {
    unsigned short divisor = (unsigned short)((1193182ULL * usec) / 1000000); // crude, only works for coarse values
    
    /*
     * Set the PIC to count down
     *
    */
    outb(0x43, 0xB6);  // channel 2, lobyte/hibyte, mode 3 (square wave)
    outb(0x42, divisor & 0xFF);         // low byte -> channel 2 data port
    outb(0x42, (divisor >> 8) & 0xFF);  // high byte -> channel 2 data port

    /*
     * Spin until PIT output pin goes high (channel 0 status)
     *
     */
    while (1) {
        unsigned char status = inb(0x61);
        if (status & 0x20)
            break;
    }
}
