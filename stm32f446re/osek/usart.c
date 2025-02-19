// usart.c - USART Driver
#include "usart.h"

#define RCC_APB1ENR   *((volatile uint32_t*)0x40023840)
#define GPIOA_AFRL    *((volatile uint32_t*)0x40020020)
#define USART2_SR     *((volatile uint32_t*)0x40004400)
#define USART2_DR     *((volatile uint32_t*)0x40004404)
#define USART2_BRR    *((volatile uint32_t*)0x40004408)
#define USART2_CR1    *((volatile uint32_t*)0x4000440C)

void usart_init(void) {
    RCC_APB1ENR |= (1 << 17); // Enable USART2 clock
    GPIOA_AFRL |= (7 << (2 * 4)); // PA2 as USART2 TX
    USART2_BRR = 0x683; // Baud rate 9600
    USART2_CR1 = (1 << 13) | (1 << 3) | (1 << 2); // Enable USART, TX, RX
}

void usart_send(char data) {
    while (!(USART2_SR & (1 << 7)));
    USART2_DR = data;
}

void usart_send_string(char *str) {
    while (*str) {
        usart_send(*str++);
    }
}