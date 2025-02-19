#include <stdint.h>

/* Linker symbols */
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _etext;
extern uint32_t _stack_top;

/*main function prototype*/

int main(void);

/* Function prototypes */
void Reset_Handler(void) __attribute__((used));

void Default_Handler(void);

/* Weak alias for unused interrupts */
void NMI_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)      __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)      __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)       __attribute__((weak, alias("Default_Handler")));

/* Vector Table */
__attribute__((section(".isr_vector")))
void (*const vector_table[])(void) = {
    (void (*)(void)) &_stack_top,  /* Stack Pointer */
    Reset_Handler,                 /* Reset Handler */
    NMI_Handler,                   /* NMI Handler */
    HardFault_Handler,             /* Hard Fault Handler */
    MemManage_Handler,             /* MemManage Handler */
    BusFault_Handler,               /* BusFault Handler */
    UsageFault_Handler,             /* UsageFault Handler */
    0, 0, 0, 0,                     /* Reserved */
    SVC_Handler,                    /* SVC Handler */
    DebugMon_Handler,                /* DebugMon Handler */
    0,                               /* Reserved */
    PendSV_Handler,                  /* PendSV Handler */
    SysTick_Handler                   /* SysTick Handler */
};

/* Default Handler */
void Default_Handler(void) {
    while (1);
}

/* Reset Handler */
void Reset_Handler(void) {
    uint32_t size;
    uint8_t *src, *dst;

    /* Copy .data from Flash to SRAM */
    size = (uint32_t)&_edata - (uint32_t)&_sdata;
    src = (uint8_t*)&_etext;
    dst = (uint8_t*)&_sdata;
    while (size--) {
        *dst++ = *src++;
    }

    /* Zero initialize .bss section */
    size = (uint32_t)&_ebss - (uint32_t)&_sbss;
    dst = (uint8_t*)&_sbss;
    while (size--) {
        *dst++ = 0;
    }

    /* Call main */
    main();

    /* Infinite loop if main() returns */
    while (1);
}
