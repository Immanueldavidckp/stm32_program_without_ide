#include "GPIO.h"




void gpio_init() {
    RCC_AHB1ENR |= (1 << 0); // Enable GPIOA clock
    GPIOA_MODER |= (1 << (5 * 2)); // Set PA5 as output
}

void gpio_set() {
    GPIOA_ODR |= (1 << 5); // Set PA5 high
}

void gpio_clear() {
    GPIOA_ODR &= ~(1 << 5); // Set PA5 low
}
