#include "main.h"
#include "relay_driver.h"

/********** Deinitialize GPIO Pins and Ports **********/
void GPIO_DeInit(void)
{
  /* Disable Clocks for GPIO Ports B and E */
  __HAL_RCC_GPIOB_CLK_DISABLE();
  __HAL_RCC_GPIOE_CLK_DISABLE();
  
	/* Deinitialize GPIO Pins for Relay and Switch */
	HAL_GPIO_DeInit(RELAY_GPIO_Port, RELAY_Pin);
	HAL_GPIO_DeInit(SWITCH_GPIO_Port, SWITCH_Pin);
}
