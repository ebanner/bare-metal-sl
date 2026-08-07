OUTPUT_FORMAT("elf32-i386")
ENTRY(_start)

SECTIONS {
  /* Boot sector */

  . = 0x7C00;

  .text : {
    src/boot*(.text*)
  }
  .rodata : {
    src/boot*(.rodata*)
  }
  .data : {
    src/boot*(.data*)
  }
  .bss : {
    src/boot*(.bss*) src/boot*(COMMON)
  }

  /* Pad to 510 bytes and add boot signature */
  . = 0x7C00 + 510;
  
  .bootsig : {
    SHORT(0xAA55)
  }

  /* init.c */
  
  .text : {
    src/init*(.text*)
  }
  .rodata : {
    src/init*(.rodata*)
  }
  .data : {
    src/init*(.data*)
  }
  .bss : {
    src/init*(.bss*) src/init*(COMMON)
  }

  /* lib */

  .text : {
    src/lib*(.text*)
  }
  .rodata : {
    src/lib*(.rodata*)
  }
  .data : {
    src/lib*(.data*)
  }
  .bss : {
    src/lib*(.bss*) src/lib*(COMMON)
  }

}
