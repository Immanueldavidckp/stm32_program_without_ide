/* startup_stm32f446retx.s - Startup code for STM32F446RE */

/* Define the stack size (4 KiB) */
.equ    Stack_Size, 0x1000

/* Define sections */
.section .isr_vector, "a", %progbits
.global g_pfnVectors

/* Vector Table */
g_pfnVectors:
    .word   _estack                 /* Top of Stack */
    .word   Reset_Handler           /* Reset Handler */
    .word   NMI_Handler             /* NMI Handler */
    .word   HardFault_Handler       /* Hard Fault Handler */
    .word   MemManage_Handler       /* MPU Fault Handler */
    .word   BusFault_Handler        /* Bus Fault Handler */
    .word   UsageFault_Handler      /* Usage Fault Handler */
    .word   0                       /* Reserved */
    .word   0                       /* Reserved */
    .word   0                       /* Reserved */
    .word   0                       /* Reserved */
    .word   SVC_Handler             /* SVCall Handler */
    .word   DebugMon_Handler        /* Debug Monitor Handler */
    .word   0                       /* Reserved */
    .word   PendSV_Handler          /* PendSV Handler */
    .word   SysTick_Handler         /* SysTick Handler */

    /* External Interrupts (IRQs 0 to 91 for STM32F446RE) */
    .word   WWDG_IRQHandler         /* IRQ 0 */
    .word   PVD_IRQHandler          /* IRQ 1 */
    .word   TAMP_STAMP_IRQHandler   /* IRQ 2 */
    .word   RTC_WKUP_IRQHandler     /* IRQ 3 */
    .word   FLASH_IRQHandler        /* IRQ 4 */
    .word   RCC_IRQHandler          /* IRQ 5 */
    .word   EXTI0_IRQHandler        /* IRQ 6 */
    .word   EXTI1_IRQHandler        /* IRQ 7 */
    .word   EXTI2_IRQHandler        /* IRQ 8 */
    .word   EXTI3_IRQHandler        /* IRQ 9 */
    .word   EXTI4_IRQHandler        /* IRQ 10 */
    .word   DMA1_Stream0_IRQHandler /* IRQ 11 */
    .word   DMA1_Stream1_IRQHandler /* IRQ 12 */
    .word   DMA1_Stream2_IRQHandler /* IRQ 13 */
    .word   DMA1_Stream3_IRQHandler /* IRQ 14 */
    .word   DMA1_Stream4_IRQHandler /* IRQ 15 */
    .word   DMA1_Stream5_IRQHandler /* IRQ 16 */
    .word   DMA1_Stream6_IRQHandler /* IRQ 17 */
    .word   ADC_IRQHandler          /* IRQ 18 */
    .word   CAN1_TX_IRQHandler      /* IRQ 19 */
    .word   CAN1_RX0_IRQHandler     /* IRQ 20 */
    .word   CAN1_RX1_IRQHandler     /* IRQ 21 */
    .word   CAN1_SCE_IRQHandler     /* IRQ 22 */
    .word   EXTI9_5_IRQHandler      /* IRQ 23 */
    .word   TIM1_BRK_TIM9_IRQHandler /* IRQ 24 */
    .word   TIM1_UP_TIM10_IRQHandler /* IRQ 25 */
    .word   TIM1_TRG_COM_TIM11_IRQHandler /* IRQ 26 */
    .word   TIM1_CC_IRQHandler      /* IRQ 27 */
    .word   TIM2_IRQHandler         /* IRQ 28 */
    .word   TIM3_IRQHandler         /* IRQ 29 */
    .word   TIM4_IRQHandler         /* IRQ 30 */
    .word   I2C1_EV_IRQHandler      /* IRQ 31 */
    .word   I2C1_ER_IRQHandler      /* IRQ 32 */
    .word   I2C2_EV_IRQHandler      /* IRQ 33 */
    .word   I2C2_ER_IRQHandler      /* IRQ 34 */
    .word   SPI1_IRQHandler         /* IRQ 35 */
    .word   SPI2_IRQHandler         /* IRQ 36 */
    .word   USART1_IRQHandler       /* IRQ 37 */
    .word   USART2_IRQHandler       /* IRQ 38 */
    .word   USART3_IRQHandler       /* IRQ 39 */
    .word   EXTI15_10_IRQHandler    /* IRQ 40 */
    .word   RTC_Alarm_IRQHandler    /* IRQ 41 */
    .word   OTG_FS_WKUP_IRQHandler  /* IRQ 42 */
    .word   TIM8_BRK_TIM12_IRQHandler /* IRQ 43 */
    .word   TIM8_UP_TIM13_IRQHandler /* IRQ 44 */
    .word   TIM8_TRG_COM_TIM14_IRQHandler /* IRQ 45 */
    .word   TIM8_CC_IRQHandler      /* IRQ 46 */
    .word   DMA1_Stream7_IRQHandler /* IRQ 47 */
    .word   FMC_IRQHandler          /* IRQ 48 */
    .word   SDIO_IRQHandler         /* IRQ 49 */
    .word   TIM5_IRQHandler         /* IRQ 50 */
    .word   SPI3_IRQHandler         /* IRQ 51 */
    .word   UART4_IRQHandler        /* IRQ 52 */
    .word   UART5_IRQHandler        /* IRQ 53 */
    .word   TIM6_DAC_IRQHandler     /* IRQ 54 */
    .word   TIM7_IRQHandler         /* IRQ 55 */
    .word   DMA2_Stream0_IRQHandler /* IRQ 56 */
    .word   DMA2_Stream1_IRQHandler /* IRQ 57 */
    .word   DMA2_Stream2_IRQHandler /* IRQ 58 */
    .word   DMA2_Stream3_IRQHandler /* IRQ 59 */
    .word   DMA2_Stream4_IRQHandler /* IRQ 60 */
    .word   0                       /* IRQ 61 */
    .word   0                       /* IRQ 62 */
    .word   CAN2_TX_IRQHandler      /* IRQ 63 */
    .word   CAN2_RX0_IRQHandler     /* IRQ 64 */
    .word   CAN2_RX1_IRQHandler     /* IRQ 65 */
    .word   CAN2_SCE_IRQHandler     /* IRQ 66 */
    .word   OTG_FS_IRQHandler       /* IRQ 67 */
    .word   DMA2_Stream5_IRQHandler /* IRQ 68 */
    .word   DMA2_Stream6_IRQHandler /* IRQ 69 */
    .word   DMA2_Stream7_IRQHandler /* IRQ 70 */
    .word   USART6_IRQHandler       /* IRQ 71 */
    .word   I2C3_EV_IRQHandler      /* IRQ 72 */
    .word   I2C3_ER_IRQHandler      /* IRQ 73 */
    .word   OTG_HS_EP1_OUT_IRQHandler /* IRQ 74 */
    .word   OTG_HS_EP1_IN_IRQHandler /* IRQ 75 */
    .word   OTG_HS_WKUP_IRQHandler  /* IRQ 76 */
    .word   OTG_HS_IRQHandler       /* IRQ 77 */
    .word   0                       /* IRQ 78 */
    .word   0                       /* IRQ 79 */
    .word   0                       /* IRQ 80 */
    .word   0                       /* IRQ 81 */
    .word   FPU_IRQHandler          /* IRQ 82 */
    .word   0                       /* IRQ 83 */
    .word   0                       /* IRQ 84 */
    .word   SPI4_IRQHandler         /* IRQ 85 */
    .word   0                       /* IRQ 86 */
    .word   0                       /* IRQ 87 */
    .word   0                       /* IRQ 88 */
    .word   0                       /* IRQ 89 */
    .word   0                       /* IRQ 90 */
    .word   0                       /* IRQ 91 */

/* Stack Section */
.section .stack, "w"
.align  3
.global _estack
.global _sstack

_sstack:
.space  Stack_Size
_estack:

/* Reset Handler */
.section .text
.global Reset_Handler
.type   Reset_Handler, %function
Reset_Handler:
    /* Set stack pointer */
    ldr     r0, =_estack
    mov     sp, r0

    /* Call the main function */
    bl      main

    /* If main returns, loop forever */
    b       .

/* Default Handler for Unhandled Interrupts */
.global Default_Handler
.type   Default_Handler, %function
Default_Handler:
Infinite_Loop:
    b       Infinite_Loop

/* Custom UsageFault_Handler for Debugging */
.global UsageFault_Handler
.type   UsageFault_Handler, %function
UsageFault_Handler:
    nop                     /* Placeholder for debugging */
    b       Infinite_Loop

/* Weak Aliases for Interrupt Handlers */
.weak   NMI_Handler
.thumb_set NMI_Handler, Default_Handler

.weak   HardFault_Handler
.thumb_set HardFault_Handler, Default_Handler

.weak   MemManage_Handler
.thumb_set MemManage_Handler, Default_Handler

.weak   BusFault_Handler
.thumb_set BusFault_Handler, Default_Handler

.weak   UsageFault_Handler
.thumb_set UsageFault_Handler, Default_Handler

.weak   SVC_Handler
.thumb_set SVC_Handler, Default_Handler

.weak   DebugMon_Handler
.thumb_set DebugMon_Handler, Default_Handler

.weak   PendSV_Handler
.thumb_set PendSV_Handler, Default_Handler

.weak   SysTick_Handler
.thumb_set SysTick_Handler, Default_Handler

.weak   WWDG_IRQHandler
.thumb_set WWDG_IRQHandler, Default_Handler

.weak   PVD_IRQHandler
.thumb_set PVD_IRQHandler, Default_Handler

.weak   TAMP_STAMP_IRQHandler
.thumb_set TAMP_STAMP_IRQHandler, Default_Handler

.weak   RTC_WKUP_IRQHandler
.thumb_set RTC_WKUP_IRQHandler, Default_Handler

.weak   FLASH_IRQHandler
.thumb_set FLASH_IRQHandler, Default_Handler

.weak   RCC_IRQHandler
.thumb_set RCC_IRQHandler, Default_Handler

.weak   EXTI0_IRQHandler
.thumb_set EXTI0_IRQHandler, Default_Handler

.weak   EXTI1_IRQHandler
.thumb_set EXTI1_IRQHandler, Default_Handler

.weak   EXTI2_IRQHandler
.thumb_set EXTI2_IRQHandler, Default_Handler

.weak   EXTI3_IRQHandler
.thumb_set EXTI3_IRQHandler, Default_Handler

.weak   EXTI4_IRQHandler
.thumb_set EXTI4_IRQHandler, Default_Handler

.weak   DMA1_Stream0_IRQHandler
.thumb_set DMA1_Stream0_IRQHandler, Default_Handler

.weak   DMA1_Stream1_IRQHandler
.thumb_set DMA1_Stream1_IRQHandler, Default_Handler

.weak   DMA1_Stream2_IRQHandler
.thumb_set DMA1_Stream2_IRQHandler, Default_Handler

.weak   DMA1_Stream3_IRQHandler
.thumb_set DMA1_Stream3_IRQHandler, Default_Handler

.weak   DMA1_Stream4_IRQHandler
.thumb_set DMA1_Stream4_IRQHandler, Default_Handler

.weak   DMA1_Stream5_IRQHandler
.thumb_set DMA1_Stream5_IRQHandler, Default_Handler

.weak   DMA1_Stream6_IRQHandler
.thumb_set DMA1_Stream6_IRQHandler, Default_Handler

.weak   ADC_IRQHandler
.thumb_set ADC_IRQHandler, Default_Handler

.weak   CAN1_TX_IRQHandler
.thumb_set CAN1_TX_IRQHandler, Default_Handler

.weak   CAN1_RX0_IRQHandler
.thumb_set CAN1_RX0_IRQHandler, Default_Handler

.weak   CAN1_RX1_IRQHandler
.thumb_set CAN1_RX1_IRQHandler, Default_Handler

.weak   CAN1_SCE_IRQHandler
.thumb_set CAN1_SCE_IRQHandler, Default_Handler

.weak   EXTI9_5_IRQHandler
.thumb_set EXTI9_5_IRQHandler, Default_Handler

.weak   TIM1_BRK_TIM9_IRQHandler
.thumb_set TIM1_BRK_TIM9_IRQHandler, Default_Handler

.weak   TIM1_UP_TIM10_IRQHandler
.thumb_set TIM1_UP_TIM10_IRQHandler, Default_Handler

.weak   TIM1_TRG_COM_TIM11_IRQHandler
.thumb_set TIM1_TRG_COM_TIM11_IRQHandler, Default_Handler

.weak   TIM1_CC_IRQHandler
.thumb_set TIM1_CC_IRQHandler, Default_Handler

.weak   TIM2_IRQHandler
.thumb_set TIM2_IRQHandler, Default_Handler

.weak   TIM3_IRQHandler
.thumb_set TIM3_IRQHandler, Default_Handler

.weak   TIM4_IRQHandler
.thumb_set TIM4_IRQHandler, Default_Handler

.weak   I2C1_EV_IRQHandler
.thumb_set I2C1_EV_IRQHandler, Default_Handler

.weak   I2C1_ER_IRQHandler
.thumb_set I2C1_ER_IRQHandler, Default_Handler

.weak   I2C2_EV_IRQHandler
.thumb_set I2C2_EV_IRQHandler, Default_Handler

.weak   I2C2_ER_IRQHandler
.thumb_set I2C2_ER_IRQHandler, Default_Handler

.weak   SPI1_IRQHandler
.thumb_set SPI1_IRQHandler, Default_Handler

.weak   SPI2_IRQHandler
.thumb_set SPI2_IRQHandler, Default_Handler

.weak   USART1_IRQHandler
.thumb_set USART1_IRQHandler, Default_Handler

.weak   USART2_IRQHandler
.thumb_set USART2_IRQHandler, Default_Handler

.weak   USART3_IRQHandler
.thumb_set USART3_IRQHandler, Default_Handler

.weak   EXTI15_10_IRQHandler
.thumb_set EXTI15_10_IRQHandler, Default_Handler

.weak   RTC_Alarm_IRQHandler
.thumb_set RTC_Alarm_IRQHandler, Default_Handler

.weak   OTG_FS_WKUP_IRQHandler
.thumb_set OTG_FS_WKUP_IRQHandler, Default_Handler

.weak   TIM8_BRK_TIM12_IRQHandler
.thumb_set TIM8_BRK_TIM12_IRQHandler, Default_Handler

.weak   TIM8_UP_TIM13_IRQHandler
.thumb_set TIM8_UP_TIM13_IRQHandler, Default_Handler

.weak   TIM8_TRG_COM_TIM14_IRQHandler
.thumb_set TIM8_TRG_COM_TIM14_IRQHandler, Default_Handler

.weak   TIM8_CC_IRQHandler
.thumb_set TIM8_CC_IRQHandler, Default_Handler

.weak   DMA1_Stream7_IRQHandler
.thumb_set DMA1_Stream7_IRQHandler, Default_Handler

.weak   FMC_IRQHandler
.thumb_set FMC_IRQHandler, Default_Handler

.weak   SDIO_IRQHandler
.thumb_set SDIO_IRQHandler, Default_Handler

.weak   TIM5_IRQHandler
.thumb_set TIM5_IRQHandler, Default_Handler

.weak   SPI3_IRQHandler
.thumb_set SPI3_IRQHandler, Default_Handler

.weak   UART4_IRQHandler
.thumb_set UART4_IRQHandler, Default_Handler

.weak   UART5_IRQHandler
.thumb_set UART5_IRQHandler, Default_Handler

.weak   TIM6_DAC_IRQHandler
.thumb_set TIM6_DAC_IRQHandler, Default_Handler

.weak   TIM7_IRQHandler
.thumb_set TIM7_IRQHandler, Default_Handler

.weak   DMA2_Stream0_IRQHandler
.thumb_set DMA2_Stream0_IRQHandler, Default_Handler

.weak   DMA2_Stream1_IRQHandler
.thumb_set DMA2_Stream1_IRQHandler, Default_Handler

.weak   DMA2_Stream2_IRQHandler
.thumb_set DMA2_Stream2_IRQHandler, Default_Handler

.weak   DMA2_Stream3_IRQHandler
.thumb_set DMA2_Stream3_IRQHandler, Default_Handler

.weak   DMA2_Stream4_IRQHandler
.thumb_set DMA2_Stream4_IRQHandler, Default_Handler

.weak   CAN2_TX_IRQHandler
.thumb_set CAN2_TX_IRQHandler, Default_Handler

.weak   CAN2_RX0_IRQHandler
.thumb_set CAN2_RX0_IRQHandler, Default_Handler

.weak   CAN2_RX1_IRQHandler
.thumb_set CAN2_RX1_IRQHandler, Default_Handler

.weak   CAN2_SCE_IRQHandler
.thumb_set CAN2_SCE_IRQHandler, Default_Handler

.weak   OTG_FS_IRQHandler
.thumb_set OTG_FS_IRQHandler, Default_Handler

.weak   DMA2_Stream5_IRQHandler
.thumb_set DMA2_Stream5_IRQHandler, Default_Handler

.weak   DMA2_Stream6_IRQHandler
.thumb_set DMA2_Stream6_IRQHandler, Default_Handler

.weak   DMA2_Stream7_IRQHandler
.thumb_set DMA2_Stream7_IRQHandler, Default_Handler

.weak   USART6_IRQHandler
.thumb_set USART6_IRQHandler, Default_Handler

.weak   I2C3_EV_IRQHandler
.thumb_set I2C3_EV_IRQHandler, Default_Handler

.weak   I2C3_ER_IRQHandler
.thumb_set I2C3_ER_IRQHandler, Default_Handler

.weak   OTG_HS_EP1_OUT_IRQHandler
.thumb_set OTG_HS_EP1_OUT_IRQHandler, Default_Handler

.weak   OTG_HS_EP1_IN_IRQHandler
.thumb_set OTG_HS_EP1_IN_IRQHandler, Default_Handler

.weak   OTG_HS_WKUP_IRQHandler
.thumb_set OTG_HS_WKUP_IRQHandler, Default_Handler

.weak   OTG_HS_IRQHandler
.thumb_set OTG_HS_IRQHandler, Default_Handler

.weak   FPU_IRQHandler
.thumb_set FPU_IRQHandler, Default_Handler

.weak   SPI4_IRQHandler
.thumb_set SPI4_IRQHandler, Default_Handler