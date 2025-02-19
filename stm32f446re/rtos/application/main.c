#include "gpio.h"
#include "usart.h"

void led_task() {
    while (1) {
        if(GPIOA_ODR == (1 << 5))
        {
        gpio_set();
        }
        else
        {
        gpio_clear();
        }        
      //  os_yield();
    }
}

void usart_task() {
    while (1) {
        usart_send('H');
     //   os_yield();
    }
}

int main() {
    os_init();
    gpio_init();
    usart_init();
    create_task(led_task);
    create_task(usart_task);
    os_start();
    while(1);
}
