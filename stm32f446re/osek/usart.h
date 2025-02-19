// usart.h - USART Header
#ifndef USART_H
#define USART_H

void usart_init(void);
void usart_send(char data);
void usart_send_string(char *str);

#endif