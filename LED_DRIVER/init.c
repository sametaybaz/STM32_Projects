#include "main.h"
#include "led_driver.h"

/********** Initialize GPIO Pins and Ports **********/
void GPIO_Init(void)
{
		/* Initialize GPIO Configuration Structure */
    GPIO_InitTypeDef GPIO_InitStruct = {0};
		
		/* GPIO Port F Clock Enable */
    __HAL_RCC_GPIOF_CLK_ENABLE();
		
		 /*Configure GPIO pin Output Level */
		HAL_GPIO_WritePin(LED_PORT, LED_1 | LED_2 | LED_3 | LED_4, GPIO_PIN_RESET);
    
		/* Initialize GPIO Pins for LED Control */
		GPIO_InitStruct.Pin = LED_1 | LED_2 | LED_3 | LED_4;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
}

