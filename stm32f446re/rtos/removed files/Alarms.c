#include "Alarms.h"
#include "Os.h"

volatile uint32_t alarm_counter = 0;
volatile uint32_t alarm_target = 0;

void start_alarm(uint32_t delay_ms) {
    alarm_target = alarm_counter + delay_ms;
}

uint8_t check_alarm() {
    return (alarm_counter >= alarm_target);
}

// SysTick increments alarm_counter every 1ms
extern void SysTick_Handler() {
    alarm_counter++;
    os_yield();
}














