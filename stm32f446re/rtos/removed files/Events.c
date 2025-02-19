#include "Events.h"
#include "Os.h"

volatile uint8_t event_flags = 0;

void wait_for_event(uint8_t event_id) {
    while (!(event_flags & (1 << event_id))) {
        os_yield(); // Yield CPU while waiting for event
    }
    event_flags &= ~(1 << event_id); // Clear event after it's processed
}

void set_event(uint8_t event_id) {
    event_flags |= (1 << event_id);
}
