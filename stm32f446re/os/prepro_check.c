#include <stdint.h>
#include "gpio.h"

uint32_t num=10;
uint32_t valu;

void function(void)
{
    valu=num++;
}