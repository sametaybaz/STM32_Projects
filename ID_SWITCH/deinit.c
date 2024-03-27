#include "main.h"
#include "id_switch_driver.h"

/********** Deinitialize GPIO Pins and Ports **********/
void GPIO_Deinit(void)
{	
		/* Disable Clocks for GPIO Ports */
	__HAL_RCC_GPIOH_CLK_DISABLE();
  __HAL_RCC_GPIOC_CLK_DISABLE(); 
  __HAL_RCC_GPIOF_CLK_DISABLE(); 
  __HAL_RCC_GPIOG_CLK_DISABLE(); 
  __HAL_RCC_GPIOE_CLK_DISABLE(); 
  __HAL_RCC_GPIOD_CLK_DISABLE();
  __HAL_RCC_GPIOA_CLK_DISABLE();
	
  /* Deinitialize GPIO */
  HAL_GPIO_DeInit(GPIOF, GPIO_PIN_14|GPIO_PIN_15);
  HAL_GPIO_DeInit(GPIOG, GPIO_PIN_0|GPIO_PIN_1);
	HAL_GPIO_DeInit(GPIOC, BL_2_Pin|LE_2_Pin);
	HAL_GPIO_DeInit(GPIOE, D2_Pin|D1_Pin|D3_Pin|D0_Pin|BL_1_Pin);
	
  /* Disabling EXTI Interrupts*/
  HAL_NVIC_DisableIRQ(EXTI0_IRQn);
  HAL_NVIC_DisableIRQ(EXTI1_IRQn);
  HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);
}
