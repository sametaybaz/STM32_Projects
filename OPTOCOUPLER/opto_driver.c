#include "main.h"
#include "opto_driver.h"
#include "select.h"

/********** Callback function for handling EXTI interrupts **********/

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{	
	#ifdef USE_OPTO1
	if (GPIO_Pin == OPTO1_Pin)
	{ 
		if (HAL_GPIO_ReadPin(OPTO_PORT, OPTO1_Pin) == GPIO_PIN_SET)
				 HAL_GPIO_WritePin(USERLED_PORT, USERLED_6, GPIO_PIN_SET);
	}
	#endif
	
	#ifdef USE_OPTO2
	if (GPIO_Pin == OPTO2_Pin) 
	{
		if (HAL_GPIO_ReadPin(OPTO_PORT, OPTO2_Pin) == GPIO_PIN_SET)
				 HAL_GPIO_WritePin(USERLED_PORT, USERLED_7, GPIO_PIN_SET);
	}
	#endif
}

/********** Handle interrupts for EXTI lines 9 to 5 **********/
void EXTI9_5_IRQHandler(void)
{		
		#ifdef USE_OPTO1
    HAL_GPIO_EXTI_IRQHandler(OPTO1_Pin);
    #endif
		
		#ifdef USE_OPTO2
		HAL_GPIO_EXTI_IRQHandler(OPTO2_Pin);
		#endif
}
