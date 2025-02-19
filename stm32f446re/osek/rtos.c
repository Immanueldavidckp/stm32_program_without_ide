// rtos.c - RTOS Scheduler
#include "rtos.h"
#include <stdint.h>

#define MAX_TASKS 5

typedef struct {
    void (*task_func)(void);
    uint32_t *stack_pointer;
} Task;

Task task_list[MAX_TASKS];
uint8_t task_count = 0;
uint8_t current_task = 0;

void os_add_task(void (*task_func)(void), uint32_t *stack) {
    if (task_count < MAX_TASKS) {
        task_list[task_count].task_func = task_func;
        task_list[task_count].stack_pointer = stack;
        task_count++;
    }
}

void os_yield(void) {
    SCB_ICSR |= (1 << 28); // Trigger PendSV for context switch
}

void PendSV_Handler(void) {
    __asm volatile (
        "MRS R0, PSP\n"
        "STMDB R0!, {R4-R11}\n"
        "STR R0, %[stack_ptr]\n"
        "LDR R0, %[new_stack]\n"
        "LDMIA R0!, {R4-R11}\n"
        "MSR PSP, R0\n"
        "BX LR\n"
        : [stack_ptr] "=m" (task_list[current_task].stack_pointer)
        : [new_stack] "m" (task_list[(current_task = (current_task + 1) % task_count)].stack_pointer)
    );
}

void os_start(void) {
    current_task = 0;
    __set_PSP((uint32_t)task_list[current_task].stack_pointer);
    __asm volatile ("BX LR");
}









