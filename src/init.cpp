#include "stm32.h"
#include "codal_target_hal.h"
#include "CodalDmesg.h"

void target_init();

#define USE_HSI 1

#define CHECK(call) if(call != HAL_OK) target_panic(909)

extern "C" 
__attribute__((weak))
void cpu_init()
{
    SystemCoreClockUpdate();

    target_init();

    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    RCC_OscInitTypeDef RCC_OscInitStruct;

    /* -1- Select HSI  as system clock source to allow modification of the PLL configuration */
    RCC_ClkInitStruct.ClockType       = RCC_CLOCKTYPE_SYSCLK;
    RCC_ClkInitStruct.SYSCLKSource    = RCC_SYSCLKSOURCE_HSI;
    CHECK(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0));

#if 0
#ifdef USE_HSI
    /* -2- Enable HSI Oscillator, select it as PLL source and finally activate the PLL */
    RCC_OscInitStruct.OscillatorType    = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState          = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue  = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLSource     = RCC_PLLSOURCE_HSI_DIV2;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16; // 64 MHz (8 MHz * 16 / 2)
#else
    /* Enable HSE oscillator and activate PLL with HSE as source */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON; /* External 8 MHz xtal on OSC_IN/OSC_OUT */
    RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9; // 72 MHz (8 MHz * 9)
#endif

    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    CHECK(HAL_RCC_OscConfig(&RCC_OscInitStruct));

    /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
    RCC_ClkInitStruct.ClockType =
        (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK; // 72 MHz
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;        // 72 MHz
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;         // 36 MHz
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;         // 72 MHz
    CHECK(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2));
#else
    RCC_ClkInitStruct.ClockType =
        (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI; // 8 MHz
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;        // 8 MHz
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;         // 8 MHz
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;         // 8 MHz
    CHECK(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0));
#endif

    SystemCoreClockUpdate();

    __HAL_RCC_TIM2_CLK_ENABLE();

    // enable backup registers (for reboot into bootloader or into app)
    PWR->CR |= PWR_CR_DBP;
    RCC->BDCR |= RCC_BDCR_RTCEN;
}
