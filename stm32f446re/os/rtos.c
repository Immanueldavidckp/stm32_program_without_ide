#include "rtos.h"
#include "gpio.h"
#include <stdio.h>
#include "usart.h"

// Initialize the stack
void initializeStack(TaskStack *s) {
    s->top = -1; // Initialize the stack as empty
}

// Check if the stack is full
int isFull(TaskStack *s) {
    return s->top == MAX_SIZE - 1;
}

// Check if the stack is empty
int isEmpty(TaskStack *s) {
    return s->top == -1;
}

// Push a task onto the stack
void push(TaskStack *s, TaskFunction task) {
    if (isFull(s)) {
        // Replace puts with an alternative logging method
        UART_SendString("Stack is full, cannot push task.\n");
        return;
    }
    s->tasks[++(s->top)] = task;
    UART_SendString("Task pushed to stack.\n");
}

void popAndExecute(TaskStack *s) {
    if (isEmpty(s)) {
        UART_SendString("Stack is empty, cannot pop task.\n");
        return;
    }
    TaskFunction task = s->tasks[(s->top)--];
    task();
}


// Initialize SysTick Timer
void SysTick_Init(void) {
    // Load the SysTick Reload Register for 500ms delay
    SYSTICK_LOAD = (SYS_TICK_FREQ / 2) - 1;  // 500ms tick

    // Clear current SysTick value
    SYSTICK_VAL = 0;

    // Enable SysTick with system clock and interrupt
    SYSTICK_CTRL = 7;  // Enable SysTick, use system clock, enable interrupt

    // Enable SysTick interrupt in NVIC
    NVIC_ISER0 |= (1 << 15);  // SysTick IRQ is IRQ #15
}

// SysTick Interrupt Handler
void SysTick_Handler(void) {
    // Add task scheduling logic here if needed
}