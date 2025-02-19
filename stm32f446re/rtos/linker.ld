/* Define memory layout */
MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
    SRAM  (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

/* Define the entry point */
ENTRY(Reset_Handler)

/* Define sections */
SECTIONS
{
    /* Vector Table (Interrupts) */
    .isr_vector :
    {
        . = ALIGN(256);   /* Ensure proper alignment for the vector table */
        KEEP(*(.isr_vector))  /* Keep the vector table in the final ELF */
    } > FLASH

    /* Code section */
    .text : 
    {
        *(.text)
        *(.rodata) /* Read-only data */
        _etext = .;  /* Define _etext at end of .text */
    } > FLASH

    /* Initialized data section */
    .data : 
    {
        _sdata = .; /* Start of .data section */
        *(.data)
        _edata = .; /* End of .data section */
    } > SRAM AT> FLASH

    /* Uninitialized data section (BSS) */
    .bss :
    {
        _sbss = .; /* Start of .bss section */
        *(.bss)
        *(COMMON)
        _ebss = .; /* End of .bss section */
    } > SRAM

    /* Stack memory */
    .stack (NOLOAD):
    {
        . = ALIGN(8);
        _stack_top = . + 1024; /* Define stack size (adjust as needed) */
    } > SRAM

    /* Define the stack top symbol */
    _stack_top = ORIGIN(SRAM) + LENGTH(SRAM);
}