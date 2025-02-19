/* GPIO Driver - GPIO.h */
#ifndef GPIO_H
#define GPIO_H


#include <stdint.h>

#define GPIOA_BASE 0x40020000
#define RCC_BASE   0x40023800

#define RCC_AHB1ENR  *((volatile uint32_t*)(RCC_BASE + 0x30))
#define GPIOA_MODER  *((volatile uint32_t*)(GPIOA_BASE + 0x00))
#define GPIOA_ODR    *((volatile uint32_t*)(GPIOA_BASE + 0x14))


void gpio_init();
void gpio_set();
void gpio_clear();

#endif





