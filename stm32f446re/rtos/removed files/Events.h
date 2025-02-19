#ifndef EVENTS_H
#define EVENTS_H

#include <stdint.h> // Ensure uint8_t is defined

void wait_for_event(uint8_t event_id);
void set_event(uint8_t event_id);

#endif
