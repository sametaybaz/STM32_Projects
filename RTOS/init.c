#include "main.h"
#include "led_driver.h"
#include "relay_driver.h"

/********** Initialize GPIO Pins and Ports **********/
void GPIO_Init(void)
{
		/* Initialize GPIO Configuration Structure */
    GPIO_InitTypeDef GPIO_InitStruct = {0};
		
		/* GPIO Port F Clock Enable */
    __HAL_RCC_GPIOF_CLK_ENABLE();		// LED_ICIN
		__HAL_RCC_GPIOG_CLK_ENABLE();  // ID_ICIN
		__HAL_RCC_GPIOE_CLK_ENABLE();  // ROLE_ICIN
		
		 /*Configure GPIO pin Output Level */
		HAL_GPIO_WritePin(LED_PORT, LED_1, GPIO_PIN_RESET);
    
		/*Configure GPIO pin Output Level */
		HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin, GPIO_PIN_RESET);
		
		/* Initialize GPIO Pins for LED Control */
		GPIO_InitStruct.Pin = LED_1;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
		
		 /*Initialize GPIO Pin for Relay Control */
		GPIO_InitStruct.Pin = RELAY_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		HAL_GPIO_Init(RELAY_GPIO_Port, &GPIO_InitStruct);
		
		 /*Configure GPIO pin : PG1 (ID SWITCH) */
		GPIO_InitStruct.Pin = GPIO_PIN_1;
		GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
		

		
		
}

