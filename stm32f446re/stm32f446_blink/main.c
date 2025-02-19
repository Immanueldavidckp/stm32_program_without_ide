
#include<stdint.h>


void delay(uint32_t count)
{
  for(uint32_t i = 0 ; i < count ; i++);
}

void led_init_all(void)
{

	uint32_t *pRccAhb1enr = (uint32_t*)0x40023830;
	uint32_t *pGpiodModeReg = (uint32_t*)0x40020000;


	*pRccAhb1enr |= ( 1U << 0);
	//configure pin_5
	*pGpiodModeReg |= ( 1U << (2*5));

}

int main()
{
    led_init_all();
    uint32_t *pGpiodDataReg = (uint32_t*)0x40020014;
    while(1)
    {
	  *pGpiodDataReg |= ( 1U << 5);
    delay(1250U * 1000U );

	  *pGpiodDataReg &= ~( 1U << 5);
    delay(1250U * 1000U );
    }

    
}
