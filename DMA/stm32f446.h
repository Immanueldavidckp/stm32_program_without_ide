#ifndef STM32F446_H
#define STM32F446_H

// Type definitions
typedef unsigned int uint32_t;

// Peripheral Base Addresses
#define GPIOA_BASE      0x40020000
#define RCC_BASE        0x40023800
#define USART2_BASE     0x40004400
#define WWDG_BASE       0x40002C00
#define SCB_BASE        0xE000ED00
#define DMA1_BASE       0x40026000

// GPIOA Registers
#define GPIOA_MODER     (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR       (*(volatile uint32_t *)(GPIOA_BASE + 0x14))
#define GPIOA_AFRL      (*(volatile uint32_t *)(GPIOA_BASE + 0x20))
#define GPIOA_AFRH      (*(volatile uint32_t *)(GPIOA_BASE + 0x24))

// RCC Registers
#define RCC_AHB1ENR     (*(volatile uint32_t *)(RCC_BASE + 0x30))
#define RCC_APB1ENR     (*(volatile uint32_t *)(RCC_BASE + 0x40))
#define RCC_APB2ENR     (*(volatile uint32_t *)(RCC_BASE + 0x44))
#define RCC_CR          (*(volatile uint32_t *)(RCC_BASE + 0x00))
#define RCC_PLLCFGR     (*(volatile uint32_t *)(RCC_BASE + 0x04))
#define RCC_CFGR        (*(volatile uint32_t *)(RCC_BASE + 0x08))

// USART2 Registers
#define USART2_CR1      (*(volatile uint32_t *)(USART2_BASE + 0x0C))
#define USART2_CR3      (*(volatile uint32_t *)(USART2_BASE + 0x14))
#define USART2_BRR      (*(volatile uint32_t *)(USART2_BASE + 0x08))
#define USART2_SR       (*(volatile uint32_t *)(USART2_BASE + 0x00))
#define USART2_DR       (*(volatile uint32_t *)(USART2_BASE + 0x04))

// WWDG Registers
#define WWDG_CR         (*(volatile uint32_t *)(WWDG_BASE + 0x00))
#define WWDG_CFR        (*(volatile uint32_t *)(WWDG_BASE + 0x04))
#define WWDG_SR         (*(volatile uint32_t *)(WWDG_BASE + 0x08))

// SCB Registers
#define SCB_AIRCR       (*(volatile uint32_t *)(SCB_BASE + 0x0C))

// DMA1 Registers
#define DMA1_LISR       (*(volatile uint32_t *)(DMA1_BASE + 0x00))
#define DMA1_HISR       (*(volatile uint32_t *)(DMA1_BASE + 0x04))
#define DMA1_LIFCR      (*(volatile uint32_t *)(DMA1_BASE + 0x08))
#define DMA1_HIFCR      (*(volatile uint32_t *)(DMA1_BASE + 0x0C))
#define DMA1_S6CR       (*(volatile uint32_t *)(DMA1_BASE + 0xA0)) // Stream 6 Control Register
#define DMA1_S6NDTR     (*(volatile uint32_t *)(DMA1_BASE + 0xA4)) // Stream 6 Number of Data Register
#define DMA1_S6PAR      (*(volatile uint32_t *)(DMA1_BASE + 0xA8)) // Stream 6 Peripheral Address Register
#define DMA1_S6M0AR     (*(volatile uint32_t *)(DMA1_BASE + 0xAC)) // Stream 6 Memory 0 Address Register

#endif