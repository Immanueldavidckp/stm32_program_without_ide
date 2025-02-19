#include <stdint.h>
#include "rtos.h"
#include "gpio.h"
#include "usart.h"

// Declare taskStack globally
TaskStack taskStack;

// LED Blink Task
void led_blink(void) {
    GPIOA_ODR ^= (1U << 5); // Toggle PA5 (LED pin)
}

// USART Send Task
void usart_send(void) {
    UART_SendString("STM32 UART Test\r\n");
}

int main() {
    // Initialize GPIO and USART
    gpio_init();
    UART2_Init();

    // Initialize the stack
    initializeStack(&taskStack);

    // Store tasks in the stack
    push(&taskStack, led_blink);
    push(&taskStack, usart_send);

    // Initialize SysTick Timer
    SysTick_Init();

    // Main loop
    while (1) {
        // Restore and execute tasks from the stack
        while (!isEmpty(&taskStack)) {
            popAndExecute(&taskStack);
        }
    }

    return 0;
}