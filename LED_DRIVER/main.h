
#ifndef __MAIN_H
#define __MAIN_H

/* Includes *****************************************************************/
#include "stm32f7xx.h"                  // Device header
#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_conf.h"         // Keil::Device:STM32Cube Framework:Classic

#ifdef _RTE_
#include "RTE_Components.h"             // Component selection
#endif
#ifdef RTE_CMSIS_RTOS2                  // when RTE component CMSIS RTOS2 is used
#include "cmsis_os2.h"                  // ::CMSIS:RTOS2
#endif

/* Functions *****************************************************************/
uint32_t HAL_GetTick (void);
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority);
void SystemClock_Config(void);
void MPU_Config(void);
void Error_Handler(void);


#endif /* __MAIN_H */

