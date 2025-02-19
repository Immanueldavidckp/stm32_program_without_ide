#ifndef ALARMS_H
#define ALARMS_H

#include <stdint.h>

void start_alarm(uint32_t delay_ms);
uint8_t check_alarm();

#endif
