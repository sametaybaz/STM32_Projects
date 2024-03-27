#include "main.h"

float voltage_dma = 0;
float voltage_inter = 0;
float voltage_pool = 0;
float temperature_dma = 0;
float temperature_inter = 0;
float temperature_pool = 0;
uint32_t adc_inter = 0;
uint32_t adc_pool = 0;
uint32_t adc_dma_buffer[ADC_BUFFER_SIZE];

/*
** Waits for the completion of ADC2 conversion using HAL_ADC_PollForConversion with a timeout of 
** 1000 milliseconds. Retrieves the ADC value using HAL_ADC_GetValue and calculates temperature 
** based  on the formula in the code."
*/

void	POOL_ADC() {
	  HAL_ADC_PollForConversion(&hadc2,1000);
	  adc_pool = HAL_ADC_GetValue(&hadc2);
		voltage_pool = adc_pool * (V_REF / ADC_MAX_VALUE);
		temperature_pool = (voltage_pool - V_0) / T_C - 5.5;
		HAL_GPIO_WritePin(GPIOF, led_3_Pin, GPIO_PIN_SET);
};

/* 
** HAL_ADC_IRQHandler is an ADC interrupt handler called upon conversion completion, triggering 
** a user-defined callback(HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)).
*/

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) 
{	
		/* If the conversion is completed by hadc1 (ADC1) */
		if (hadc == &hadc1)
    {
        
        adc_inter = HAL_ADC_GetValue(&hadc1);
				voltage_inter = adc_inter * (V_REF / ADC_MAX_VALUE);
				temperature_inter = (voltage_inter - V_0) / T_C - 5.5;
        HAL_GPIO_WritePin(GPIOF, led_1_Pin, GPIO_PIN_SET);
				
    } 
		
		/* If the conversion is completed by hadc3 (ADC3) */
    if (hadc == &hadc3) 
    {				
 
				int i = 0;
				adc_dma_buffer[i] = HAL_ADC_GetValue(&hadc3);
        voltage_dma = adc_dma_buffer[i] * (V_REF / ADC_MAX_VALUE);
				temperature_dma = (voltage_dma - V_0) / T_C - 5.5;
				HAL_GPIO_WritePin(GPIOF, led_2_Pin, GPIO_PIN_SET);
			
    }
		
}

