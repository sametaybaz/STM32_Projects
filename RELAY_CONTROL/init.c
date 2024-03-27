#include "main.h"
#include "relay_driver.h"

/********** Initialize GPIO Pins and Ports **********/
void GPIO_Init(void)
{	
	/* Initialize GPIO Configuration Structure */
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports B and E Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
 
  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin, GPIO_PIN_RESET);

  /* Initialize GPIO Pin for Switch Control */
  GPIO_InitStruct.Pin = SWITCH_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SWITCH_GPIO_Port, &GPIO_InitStruct);

  /*Initialize GPIO Pin for Relay Control */
  GPIO_InitStruct.Pin = RELAY_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(RELAY_GPIO_Port, &GPIO_InitStruct);

}
