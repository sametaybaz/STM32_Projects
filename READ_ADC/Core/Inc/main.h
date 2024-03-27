
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

/* Functions *****************************************************************/
void 	Error_Handler(void);
void 	SystemClock_Config(void);
void 	MX_GPIO_Init(void);
void 	MX_DMA_Init(void);
void 	MX_ADC1_Init(void);
void 	MX_ADC2_Init(void);
void 	MX_ADC3_Init(void);
void	POOL_ADC();
void	HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);
void 	display_seven_segment(uint8_t temperature);
void  display_digit(uint32_t digit);
void	deinit();
void	reset_all();

/* Defines *******************************************************************/
#define led_1_Pin GPIO_PIN_2
#define led_1_GPIO_Port GPIOF
#define led_2_Pin GPIO_PIN_3
#define led_2_GPIO_Port GPIOF
#define led_3_Pin GPIO_PIN_4
#define led_3_GPIO_Port GPIOF
#define led_4_Pin GPIO_PIN_5
#define led_4_GPIO_Port GPIOF
#define BL_2_Pin GPIO_PIN_0
#define BL_2_GPIO_Port GPIOC
#define LE_2_Pin GPIO_PIN_2
#define LE_2_GPIO_Port GPIOC
#define D2_Pin GPIO_PIN_10
#define D2_GPIO_Port GPIOE
#define D1_Pin GPIO_PIN_11
#define D1_GPIO_Port GPIOE
#define D3_Pin GPIO_PIN_13
#define D3_GPIO_Port GPIOE
#define D0_Pin GPIO_PIN_14
#define D0_GPIO_Port GPIOE
#define BL_1_Pin GPIO_PIN_15
#define BL_1_GPIO_Port GPIOE
#define LE_1_Pin GPIO_PIN_14
#define LE_1_GPIO_Port GPIOD

#define V_0		0.5
#define T_C		0.01
#define V_REF	3.3
#define ADC_MAX_VALUE 4095.0
#define ADC_BUFFER_SIZE 1 


/* Global Variables **********************************************************/
extern uint32_t adc_inter;
extern uint32_t adc_pool;
extern uint32_t adc_dma_buffer[ADC_BUFFER_SIZE];
extern float voltage_dma;
extern float voltage_inter;
extern float voltage_pool;
extern float temperature_dma;
extern float temperature_inter;
extern float temperature_pool;
extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
extern ADC_HandleTypeDef hadc3;
extern DMA_HandleTypeDef hdma_adc3;


/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
