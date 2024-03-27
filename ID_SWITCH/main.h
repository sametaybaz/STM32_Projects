
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes *****************************************************************/
#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_conf.h" 

/* Defines *******************************************************************/
#define BL_2_Pin				GPIO_PIN_0
#define BL_2_GPIO_Port	GPIOC
#define LE_2_Pin				GPIO_PIN_2
#define LE_2_GPIO_Port 	GPIOC
#define D2_Pin					GPIO_PIN_10
#define D2_GPIO_Port		GPIOE
#define D1_Pin					GPIO_PIN_11
#define D1_GPIO_Port		GPIOE
#define D3_Pin					GPIO_PIN_13
#define D3_GPIO_Port		GPIOE
#define D0_Pin					GPIO_PIN_14
#define D0_GPIO_Port		GPIOE
#define BL_1_Pin				GPIO_PIN_15
#define BL_1_GPIO_Port	GPIOE
#define LE_1_Pin				GPIO_PIN_14
#define LE_1_GPIO_Port	GPIOD


/* Functions *****************************************************************/
uint32_t HAL_GetTick (void);
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority);
void SystemClock_Config(void);
void MPU_Config(void);
void Error_Handler(void);
void display_digit(uint8_t digit);
void display_seven_segment(uint8_t id_value);


#endif /* __MAIN_H */

