#ifndef OS_H
#define OS_H

#include <stdint.h>

#define SYSTICK_CTRL  *((volatile uint32_t*)0xE000E010)
#define SYSTICK_LOAD  *((volatile uint32_t*)0xE000E014)
#define SYSTICK_VAL   *((volatile uint32_t*)0xE000E018)
#define NVIC_ISER0     (*(volatile unsigned int *)0xE000E100)

#define MAX_TASKS 5
#define STACK_SIZE 256

typedef struct {
    uint32_t *stack_pointer;
    uint32_t stack[STACK_SIZE];
} Task;

void __set_PSP(uint32_t value);
void __set_CONTROL(uint32_t value);
void __ISB(void);

void os_init();
void os_add_task(void (*task_func)());
void os_start();
void os_yield();

#endif
