#include "USART.h"

#define USART2_BASE  0x40004400
#define RCC_BASE     0x40023800
#define GPIOA_BASE   0x40020000

#define RCC_APB1ENR  *((volatile uint32_t*)(RCC_BASE + 0x40))
#define GPIOA_MODER  *((volatile uint32_t*)(GPIOA_BASE + 0x00))
#define GPIOA_AFRL   *((volatile uint32_t*)(GPIOA_BASE + 0x20))
#define USART2_SR    *((volatile uint32_t*)(USART2_BASE + 0x00))
#define USART2_DR    *((volatile uint32_t*)(USART2_BASE + 0x04))
#define USART2_BRR   *((volatile uint32_t*)(USART2_BASE + 0x08))
#define USART2_CR1   *((volatile uint32_t*)(USART2_BASE + 0x0C))

void usart_init() {
    RCC_APB1ENR |= (1 << 17); // Enable USART2 clock
    GPIOA_MODER |= (2 << (2 * 2)) | (2 << (3 * 2)); // Set PA2, PA3 as AF
    GPIOA_AFRL |= (7 << (2 * 4)) | (7 << (3 * 4)); // Set AF7 (USART2)

    USART2_BRR = 0x683; // Baud rate 9600 (assuming 16MHz clock)
    USART2_CR1 = (1 << 3) | (1 << 2) | (1 << 13); // Enable Tx, Rx, USART
}

void usart_send(char *data) {
   // while (!(USART2_SR & (1 << 7))); // Wait for TX buffer empty
    USART2_DR =(uint32_t) data;
}

char usart_receive() {
    while (!(USART2_SR & (1 << 5))); // Wait for RX buffer not empty
    return USART2_DR;
}
