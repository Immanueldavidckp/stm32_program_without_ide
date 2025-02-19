// gpio.h - GPIO Header
#ifndef GPIO_H
#define GPIO_H
#include <stdint.h>

#define GPIOA_BASE      0x40020000
#define RCC_AHB1ENR   *((volatile uint32_t*)0x40023830)
#define GPIOA_MODER   *((volatile uint32_t*)0x40020000)
#define GPIOA_ODR     *((volatile uint32_t*)0x40020014)
#define GPIOA_AFRL      (*(volatile int *)(GPIOA_BASE + 0x20))

void gpio_init(void);
void gpio_toggle(void);

#endif