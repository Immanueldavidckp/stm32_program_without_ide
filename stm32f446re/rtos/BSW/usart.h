/* USART Driver - USART.h */
#ifndef USART_H
#define USART_H

#include <stdint.h>

void usart_init();
void usart_send(char *data);
char usart_receive();

#endif