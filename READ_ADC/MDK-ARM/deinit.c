
#include "main.h"

/********** Deinitializes GPIO, ADC, and DMA peripherals that were previously initialized. ***********/
void deinit()
{
	
	 /* Deinitialize GPIO */
  HAL_GPIO_DeInit(GPIOF, led_1_Pin|led_2_Pin|led_3_Pin|led_4_Pin);
	HAL_GPIO_DeInit(GPIOC, BL_2_Pin|LE_2_Pin);
	HAL_GPIO_DeInit(GPIOE, D2_Pin|D1_Pin|D3_Pin|D0_Pin|BL_1_Pin);
	HAL_GPIO_DeInit(LE_1_GPIO_Port, LE_1_Pin);
	/* Deinitialize DMA */
  HAL_DMA_DeInit(&hdma_adc3);
	
	
	  /* Deinitialize ADC */
  if (HAL_ADC_DeInit(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_ADC_DeInit(&hadc2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_ADC_DeInit(&hadc3) != HAL_OK)
  {
    Error_Handler();
  }
	
  /* Disable all used peripheral clocks */
  __HAL_RCC_ADC1_CLK_DISABLE();
  __HAL_RCC_ADC2_CLK_DISABLE();
  __HAL_RCC_ADC3_CLK_DISABLE();
  __HAL_RCC_GPIOF_CLK_DISABLE();
  __HAL_RCC_GPIOH_CLK_DISABLE();
  __HAL_RCC_GPIOC_CLK_DISABLE();
  __HAL_RCC_GPIOA_CLK_DISABLE();
  __HAL_RCC_GPIOE_CLK_DISABLE();
  __HAL_RCC_GPIOD_CLK_DISABLE();

  /* Reset peripherals */
  __HAL_RCC_ADC_FORCE_RESET();
  __HAL_RCC_ADC_RELEASE_RESET();
  __HAL_RCC_DMA2_FORCE_RESET();
  __HAL_RCC_DMA2_RELEASE_RESET();
}


/* Turns off user LEDs and seven-segment display.  */
void reset_all()
{
	HAL_GPIO_WritePin(GPIOF, led_1_Pin|led_2_Pin|led_3_Pin|led_4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, BL_2_Pin|LE_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LE_1_GPIO_Port, LE_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE, D2_Pin|D1_Pin|D3_Pin|D0_Pin
                          |BL_1_Pin, GPIO_PIN_RESET);
}