#include "Resource.h"

volatile int resource_locked = 0;

void lock_resource() {
    while (__atomic_test_and_set(&resource_locked, __ATOMIC_ACQUIRE));
}

void unlock_resource() {
    __atomic_clear(&resource_locked, __ATOMIC_RELEASE);
}
