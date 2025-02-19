#ifndef RTOS_H
#define RTOS_H

#include <stdint.h>

#define SYSTICK_BASE    0xE000E010
#define NVIC_ISER0      (*(volatile unsigned int *)0xE000E100) // NVIC Enable Register

#define SYSTICK_CTRL    (*(volatile unsigned int *)(SYSTICK_BASE + 0x00))
#define SYSTICK_LOAD    (*(volatile unsigned int *)(SYSTICK_BASE + 0x04))
#define SYSTICK_VAL     (*(volatile unsigned int *)(SYSTICK_BASE + 0x08))

#define SYS_TICK_FREQ   16000000  // Assuming 16 MHz system clock
#define MAX_SIZE 100

// Define TaskFunction as a pointer to a function that takes no arguments and returns void
typedef void (*TaskFunction)();

// Define the TaskStack structure
typedef struct {
    TaskFunction tasks[MAX_SIZE]; // Array to store function pointers
    int top; // Index of the top of the stack
} TaskStack;

// Function prototypes
void SysTick_Init(void);
void SysTick_Handler(void);
void initializeStack(TaskStack *s);
int isFull(TaskStack *s);
int isEmpty(TaskStack *s);
void push(TaskStack *s, TaskFunction task);
void popAndExecute(TaskStack *s);

#endif