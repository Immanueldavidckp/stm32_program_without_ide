#include "stm32f446.h"

// Global variables
const char message_led_on[] = "hello_uart2_LED:__ON \n\r";
const char message_led_off[] = "hello_uart2_LED:_OFF \n\r";

// Function prototypes
void WWDG_Disable(void);
void SystemReset(void);
void SystemClock_Config(void);
void GPIO_Init(void);
void UART2_Init(void);
void DMA1_Init(void);
void UART2_DMA_Transmit(const char *data);
void Delay_ms(uint32_t ms);

// Reset flag in SRAM
#define RESET_FLAG_ADDR 0x2001FFFC
#define RESET_FLAG      (*(volatile uint32_t *)RESET_FLAG_ADDR)

int main(void) {
    // Check reset flag to perform a system reset if needed
    if (RESET_FLAG != 0xDEADBEEF) {
        RESET_FLAG = 0xDEADBEEF;
        SystemReset();
    }

    // Clear reset flag after successful reset
    RESET_FLAG = 0;

    // Disable WWDG to prevent interrupts
    WWDG_Disable();

    // Initialize peripherals
    SystemClock_Config();
    GPIO_Init();
    UART2_Init();
    DMA1_Init();

    while (1) {
        // Turn LED on and send LED ON message
        GPIOA_ODR |= (1 << 5);  // LED on
        UART2_DMA_Transmit(message_led_on);
        Delay_ms(100);

        // Turn LED off and send LED OFF message
        GPIOA_ODR &= ~(1 << 5); // LED off
        UART2_DMA_Transmit(message_led_off);
        Delay_ms(100);
    }
}

void WWDG_Disable(void) {
    RCC_APB1ENR |= (1 << 11);
    WWDG_CFR &= ~(1 << 9);
    WWDG_SR &= ~(1 << 0);
    RCC_APB1ENR &= ~(1 << 11);
    if (RCC_APB1ENR & (1 << 11)) {
        RCC_APB1ENR &= ~(1 << 11);
    }
}

void SystemReset(void) {
    SCB_AIRCR = (0x5FA << 16) | (1 << 2);
    while (1);
}

void SystemClock_Config(void) {
    RCC_CR |= (1 << 0);
    while (!(RCC_CR & (1 << 1)));
    RCC_CFGR &= ~(3 << 0);
    while ((RCC_CFGR & (3 << 2)) != (0 << 2));
    RCC_CFGR &= ~(7 << 10);
    RCC_APB1ENR |= (1 << 17);
}

void GPIO_Init(void) {
    RCC_AHB1ENR |= (1 << 0);
    GPIOA_MODER &= ~(3 << 4);
    GPIOA_MODER |= (2 << 4);
    GPIOA_AFRL &= ~(0xF << 8);
    GPIOA_AFRL |= (7 << 8);
    GPIOA_MODER &= ~(3 << 10);
    GPIOA_MODER |= (1 << 10);
    GPIOA_ODR &= ~(1 << 5);
}

void UART2_Init(void) {
    RCC_APB1ENR |= (1 << 17);
    USART2_CR1 = 0;
    USART2_BRR = 0x683;
    USART2_CR1 |= (1 << 3);
    USART2_CR3 |= (1 << 7);
    USART2_CR1 |= (1 << 13);
}

void DMA1_Init(void) {
    RCC_AHB1ENR |= (1 << 21);
    DMA1_S6CR = 0;
    DMA1_S6CR |= (4 << 25); // Channel 4 (USART2_TX)
    DMA1_S6CR |= (1 << 10); // Memory increment mode
    DMA1_S6CR |= (0 << 9);  // Peripheral fixed (USART2_DR)
    DMA1_S6CR |= (1 << 8);  // Memory-to-Peripheral direction
    DMA1_S6CR |= (0 << 13); // Byte-sized memory data (MSIZE)
    DMA1_S6CR |= (0 << 11); // Byte-sized peripheral data (PSIZE)
    DMA1_S6CR |= (1 << 6);  // High priority
    DMA1_S6CR &= ~(1 << 5); // Disable FIFO mode (DMDIS = 0)
}

void UART2_DMA_Transmit(const char *data) {
    uint32_t len;
   while (data[len] != '\0') len++;

    DMA1_S6CR &= ~(1 << 0);
    while (DMA1_S6CR & (1 << 0));

    DMA1_HIFCR |= (1 << 11);
    DMA1_HIFCR |= (1 << 10);
    DMA1_HIFCR |= (1 << 8);
    DMA1_HIFCR |= (1 << 9);
    DMA1_HIFCR |= (1 << 6);

    DMA1_S6PAR = (uint32_t)&USART2_DR;
    DMA1_S6M0AR = (uint32_t)data;
    DMA1_S6NDTR = len;

    // Check USART2 status before starting DMA
    if (!(USART2_SR & (1 << 7))) { // Check TXE (Transmit Data Register Empty)
        // If TXE is not set, there might be an issue with USART2
        return;
    }

    DMA1_S6CR |= (1 << 0);

    while (!(USART2_SR & (1 << 6)));
}

void Delay_ms(uint32_t ms) {
    for (uint32_t i = 0; i < ms * 4000; i++) {
        __asm("nop");
    }
}