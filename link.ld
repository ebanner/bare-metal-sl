OUTPUT_FORMAT("elf32-i386")
ENTRY(_start)

SECTIONS {
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
}
