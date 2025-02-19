#include "rtos.h"
#include "gpio.h"
#include "usart.h"

#define STACK_SIZE 128
uint32_t led_stack[STACK_SIZE];
uint32_t usart_stack[STACK_SIZE];

void led_task(void) {
    while (1) {
        gpio_toggle();
        for (volatile int i = 0; i < 100000; i++);
        os_yield();
    }
}

void usart_task(void) {
    while (1) {
        usart_send_string("RTOS Running\n");
        for (volatile int i = 0; i < 100000; i++);
        os_yield();
    }
}

int main(void) {
    gpio_init();
    usart_init();
    os_add_task(led_task, &led_stack[STACK_SIZE - 1]);
    os_add_task(usart_task, &usart_stack[STACK_SIZE - 1]);
    os_start();
    while (1);
}
