#ifndef UART_H_
#define UART_H_

#include <stdint.h>

#define UART2_BASE      0x40004400
#define RCC_BASE        0x40023800

#define RCC_APB1ENR     (*(volatile int *)(RCC_BASE + 0x40))

#define UART2_CR1       (*(volatile int *)(UART2_BASE + 0x0C))
#define UART2_BRR       (*(volatile int *)(UART2_BASE + 0x08))
#define UART2_DR        (*(volatile int *)(UART2_BASE + 0x04))
#define UART2_SR        (*(volatile int *)(UART2_BASE + 0x00))
#define UART2_CR3       (*(volatile int *)(UART2_BASE + 0x14))


#define UART2_SR_TXE  (1<<7)
#define UART2_SR_RXE  (1<<5)

void UART2_Init(void) ;
void UART_SendString(char *string);
char UART_ReceiveChar(void) ;
void UART_SendChar(char c);
	



#endif