// gpio.c - GPIO Driver
#include "gpio.h"



void gpio_init(void) {
    RCC_AHB1ENR |= (1 << 0); // Enable GPIOA clock
    GPIOA_MODER &= ~(3 << (5 * 2));  // Clear mode bits
    GPIOA_MODER |= (1 << (5 * 2));

    GPIOA_MODER &= ~((3U << 4) | (3U << 6));
    GPIOA_MODER |= ((2U << 4) | (2U << 6));

    
    GPIOA_AFRL &= ~((15U << 8) | (15U << 12));
    GPIOA_AFRL |= ((7U << 8) | (7U << 12));
}

void gpio_toggle(void) {
    int led =1;
    if (led % 2)
    {
        GPIOA_ODR |= (1U<<5);
    }
    else
    {
        {
            GPIOA_ODR &=~(1U<<5);
        }
    }
    led =led+1;
}