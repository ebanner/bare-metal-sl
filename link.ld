OUTPUT_FORMAT("elf32-i386")
ENTRY(_start)

SECTIONS {
  . = 0x7C00;

  .text : {
    src/boot_sector*(.text*)
  }

  .rodata : {
    src/boot_sector*(.rodata*)
  }

  .data : {
    src/boot_sector*(.data*)
  }

  .bss : {
    src/boot_sector*(.bss*) src/boot_sector*(COMMON)
  }

  /* Pad to 510 bytes and add boot signature */
  . = 0x7C00 + 510;
  
  .bootsig : {
    SHORT(0xAA55)
  }
}
