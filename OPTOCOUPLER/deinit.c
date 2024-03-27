#include "main.h"
#include "opto_driver.h"

/********** Deinitialize GPIO Pins and Ports **********/
void GPIO_DeInit(void)
{
  	/* Disable Clocks for GPIO Ports B and E */
  __HAL_RCC_GPIOB_CLK_DISABLE();
  __HAL_RCC_GPIOF_CLK_DISABLE();
  
	/* Deinitialize GPIO Pins*/
	HAL_GPIO_DeInit(USERLED_PORT, USERLED_6);
	HAL_GPIO_DeInit(USERLED_PORT, USERLED_7);
	HAL_GPIO_DeInit(OPTO_PORT, OPTO1_Pin);
	HAL_GPIO_DeInit(OPTO_PORT, OPTO2_Pin);
	
}
