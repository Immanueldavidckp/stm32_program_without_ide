/* Define memory regions */
MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
    SRAM (rwx)   : ORIGIN = 0x20000000, LENGTH = 128K
}

/* Define entry point */
ENTRY(Reset_Handler)

/* Define sections */
SECTIONS
{
    .isr_vector : 
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector)) /* Keep the vector table */
        . = ALIGN(4);
    } >FLASH

    .text : 
    {
        . = ALIGN(4);
        *(.text)           /* Code */
        *(.text*)          /* Other code */
        *(.rodata)         /* Read-only data */
        *(.rodata*)        /* Other read-only data */
        . = ALIGN(4);
    } >FLASH

    .data : 
    {
        . = ALIGN(4);
        _sidata = LOADADDR(.data);
        _sdata = .;
        *(.data)
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    } >RAM AT> FLASH

    .bss (NOLOAD) : 
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss)
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    } >RAM

    /* Stack setup */
    .stack (NOLOAD) : 
    {
        . = ALIGN(8);
        _estack = ORIGIN(RAM) + LENGTH(RAM);
    } >RAM

    _stack_top = ORIGIN(SRAM) + LENGTH(SRAM);
}
