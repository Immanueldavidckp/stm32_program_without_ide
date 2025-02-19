// rtos.h - RTOS Header
#ifndef RTOS_H
#define RTOS_H

void os_add_task(void (*task_func)(void), uint32_t *stack);
void os_start(void);
void os_yield(void);

#endif