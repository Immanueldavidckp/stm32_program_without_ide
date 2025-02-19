#include "usart.h"


void UART2_Init(void) {
    RCC_APB1ENR |= (1U << 17); // Enable UART2 clock

    UART2_BRR = 16000000 / 9600; // Set baud rate to 9600 (assuming 16 MHz clock)

    UART2_CR3 |= (1U << 6); // Enable DMA for UART reception
    
    // UART2_CR1 |= (1U << 5) | (1U << 7);	

    UART2_CR1 |= (1U << 3) | (1U << 2); // Enable UART transmitter and receiver
    UART2_CR1 |= (1U << 13);            // Enable UART
}

void UART_SendString(char *string) {
    while (*string) {
        UART_SendChar(*string++);
    }
}
char UART_ReceiveChar(void) {
    while (!(UART2_SR & UART2_SR_RXE)); // Wait until RX buffer is not empty
    return (char)UART2_DR;
}
void UART_SendChar(char c) {
    while (!(UART2_SR & UART2_SR_TXE)); // Wait until TX buffer is empty
    UART2_DR = c;
}