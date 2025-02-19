#include "Os.h"


#define SYS_TICK_FREQ   16000000  // Assuming 16 MHz system clock

Task tasks[MAX_TASKS];
uint8_t task_count = 0;
uint8_t current_task = 0;

void __set_PSP(uint32_t value) {
    __asm volatile ("msr psp, %0" : : "r" (value) : "memory");
}

void __set_CONTROL(uint32_t value) {
    __asm volatile ("msr control, %0" : : "r" (value) : "memory");
}

void __ISB(void) {
    __asm volatile ("isb" ::: "memory");
}


void os_init() {
    task_count = 0;

    // Load the SysTick Reload Register for 500ms delay
    SYSTICK_LOAD = (SYS_TICK_FREQ / 2) - 1;  // 500ms tick

    // Clear current SysTick value
    SYSTICK_VAL = 0;

    // Enable SysTick with system clock and interrupt
    SYSTICK_CTRL = 7;  // Enable SysTick, use system clock, enable interrupt

    // Enable SysTick interrupt in NVIC
    NVIC_ISER0 |= (1 << 15);  // SysTick IRQ is IRQ #15
}

void os_add_task(void (*task_func)()) {
    if (task_count < MAX_TASKS) {
        Task *t = &tasks[task_count];

        // Initialize stack pointer
        t->stack_pointer = &t->stack[STACK_SIZE - 16]; // Allocate space for registers

        // Set up stack frame as if the task was interrupted
        t->stack[STACK_SIZE - 1] = 0x01000000; // xPSR (Thumb mode bit must be set)
        t->stack[STACK_SIZE - 2] = (uint32_t)task_func; // PC (Task entry point)
        t->stack[STACK_SIZE - 3] = 0xFFFFFFFD; // LR (Return to Thread mode using PSP)
        // R12, R3, R2, R1, R0 (empty)
        t->stack[STACK_SIZE - 4] = 0;
        t->stack[STACK_SIZE - 5] = 0;
        t->stack[STACK_SIZE - 6] = 0;
        t->stack[STACK_SIZE - 7] = 0;
        // R11-R4 (empty, manually saved/restored)
        t->stack[STACK_SIZE - 8] = 0;
        t->stack[STACK_SIZE - 9] = 0;
        t->stack[STACK_SIZE - 10] = 0;
        t->stack[STACK_SIZE - 11] = 0;
        t->stack[STACK_SIZE - 12] = 0;
        t->stack[STACK_SIZE - 13] = 0;
        t->stack[STACK_SIZE - 14] = 0;
        t->stack[STACK_SIZE - 15] = 0;

        task_count++;
    }
}


void os_start() {
    current_task = 0;

    // Set PSP to the task stack pointer
    __set_PSP((uint32_t)tasks[current_task].stack_pointer);

    // Switch to unprivileged Thread mode using PSP
    __set_CONTROL(0x02);
    __ISB();

    // Start the first task
    void (*task)() = (void (*)())tasks[current_task].stack[STACK_SIZE - 2];
    task();
}


void os_yield() {
    *(volatile uint32_t*)0xE000ED04 = (1 << 28); // Set PendSV bit
}


// SysTick increments alarm_counter every 1ms

