// boot.c — C code in the initial 512 mb boot sector

extern void isr_handler(void);

#define IDT_BASE   0x10000u
#define CODE_SEL   0x0008      // your 32-bit code segment selector
#define INT_GATE   0x8E        // P=1, DPL=0, 32-bit interrupt gate

typedef unsigned char  u8;   // 1 byte
typedef unsigned short u16;  // 2 bytes
typedef unsigned int   u32;  // 4 bytes

struct __attribute__((packed)) idt_entry {
    u16 off_low;     // Bits 0–15 of the ISR handler address (offset low)
    u16 sel;         // Code segment selector in the GDT (which segment contains the handler)
    u8  zero;        // Must be 0 — reserved by Intel for alignment
    u8  type_attr;   // Type and attributes (P=1, DPL, gate type — usually 0x8E for interrupt gate)
    u16 off_high;    // Bits 16–31 of the ISR handler address (offset high)
};

void write_idt(void) {
    u32 addr;

    struct idt_entry *p = (struct idt_entry*)IDT_BASE;
    for (unsigned int i = 0; i < 256; ++i) {
        addr = (u32)isr_handler;

        p[i] = (struct idt_entry){
            .off_low   = (u16)(addr & 0xFFFF),
            .sel       = CODE_SEL,
            .zero      = 0,
            .type_attr = INT_GATE,
            .off_high  = (u16)(addr >> 16),
        };
    }
}

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
