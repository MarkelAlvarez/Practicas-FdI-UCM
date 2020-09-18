SECTIONS {
. = 0x0C000000;
.data : {
*(.data)
*(.rodata) }
.bss : {
*(.bss)
*(COMMON) }
.text : {
  *(.text)
}
PROVIDE(end = .);
    PROVIDE(_stack = 0x0C7FF000 );
}