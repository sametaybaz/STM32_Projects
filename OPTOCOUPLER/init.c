#include "main.h"
#include "opto_driver.h"

/********** Initialize GPIO Pins and Ports **********/

void GPIO_Init(void)
{
   	/* Initialize GPIO Configuration Structure */
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports B and F Clock Enable */
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(USERLED_PORT, USERLED_6 | USERLED_7, GPIO_PIN_RESET);
   
     /* Initialize GPIO Pins for USERLED Control */
    GPIO_InitStruct.Pin = USERLED_6 | USERLED_7;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

     /*Initialize OPTO Pins for OPTOCOUPLER interrupt Control */
    GPIO_InitStruct.Pin = OPTO1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(OPTO_PORT, &GPIO_InitStruct);
		
		/* Set priority and enable EXTI9_5_IRQn interrupt */
		HAL_NVIC_SetPriority(EXTI9_5_IRQn, 1, 0);
		HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

}
