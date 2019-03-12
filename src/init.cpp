#include "stm32.h"
#include "codal_target_hal.h"
#include "CodalDmesg.h"

void target_init();

extern "C"
__attribute((weak))
void cpu_init()
{
    SystemCoreClockUpdate();

    target_init();

    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    RCC_OscInitTypeDef RCC_OscInitStruct;

    /* Enable HSE oscillator and activate PLL with HSE as source */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON; /* External 8 MHz xtal on OSC_IN/OSC_OUT */
    RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9; // 72 MHz (8 MHz * 9)
    int r = HAL_RCC_OscConfig(&RCC_OscInitStruct);
    CODAL_ASSERT(r == HAL_OK);

    /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
    RCC_ClkInitStruct.ClockType =
        (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK; // 72 MHz
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;        // 72 MHz
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;         // 36 MHz
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;         // 72 MHz
    r = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);
    CODAL_ASSERT(r == HAL_OK);

    SystemCoreClockUpdate();

    __HAL_RCC_TIM2_CLK_ENABLE();

    // enable backup registers (for reboot into bootloader or into app)
    PWR->CR |= PWR_CR_DBP;
    RCC->BDCR |= RCC_BDCR_RTCEN;
}
