#define RCC_BASE        0x40023800
#define GPIOA_BASE      0x40020000
#define SYSTICK_BASE    0xE000E010
#define NVIC_ISER0      (*(volatile unsigned int *)0xE000E100) // NVIC Enable Register

#define RCC_AHB1ENR     (*(volatile unsigned int *)(RCC_BASE + 0x30))
#define GPIOA_MODER     (*(volatile unsigned int *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR       (*(volatile unsigned int *)(GPIOA_BASE + 0x14))

#define SYSTICK_CTRL    (*(volatile unsigned int *)(SYSTICK_BASE + 0x00))
#define SYSTICK_LOAD    (*(volatile unsigned int *)(SYSTICK_BASE + 0x04))
#define SYSTICK_VAL     (*(volatile unsigned int *)(SYSTICK_BASE + 0x08))

#define SYS_TICK_FREQ   16000000  // Assuming 16 MHz system clock

void SysTick_Init(void);
void GPIOA_Init(void);
void SysTick_Handler(void);

volatile int led_state = 0;  // LED toggle state

int main(void) {
    // Initialize GPIOA and SysTick
    GPIOA_Init();
    SysTick_Init();

    while (1) {
        // Main loop does nothing, LED toggling happens in interrupt
    }
}

// Function to initialize GPIOA Pin 5 as output
void GPIOA_Init(void) {
    // Enable GPIOA clock
    RCC_AHB1ENR |= (1 << 0);

    // Set PA5 as output mode
    GPIOA_MODER &= ~(3 << (5 * 2));  // Clear mode bits
    GPIOA_MODER |= (1 << (5 * 2));   // Set as output mode
}

// Function to initialize SysTick Timer
void SysTick_Init(void) {
    // Load the SysTick Reload Register for 500ms delay
    SYSTICK_LOAD = (SYS_TICK_FREQ / 2) - 1;  // 500ms tick

    // Clear current SysTick value
    SYSTICK_VAL = 0;

    // Enable SysTick with system clock and interrupt
    SYSTICK_CTRL = 7;  // Enable SysTick, use system clock, enable interrupt

    // Enable SysTick interrupt in NVIC
    NVIC_ISER0 |= (1 << 15);  // SysTick IRQ is IRQ #15
}

// SysTick Interrupt Handler
void SysTick_Handler(void) {
    if (led_state == 0) {
        GPIOA_ODR |= (1 << 5);  // Turn LED ON
        led_state = 1;
    } else {
        GPIOA_ODR &= ~(1 << 5); // Turn LED OFF
        led_state = 0;
    }
}
