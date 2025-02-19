#include "Scheduler.h"
#include "Os.h"

void SysTick_Handler(void) {
    os_yield();
}
