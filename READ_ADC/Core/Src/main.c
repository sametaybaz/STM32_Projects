
#include "main.h"
#include "../../MDK-ARM/select.h"


/* Programin kullanimi !
**
** select.h dosaysindan kullanilmak istenen yöntemlere ait olan 
** definelarin basindaki yorum satiri kaldirilarak istenen yöntemler
** ayri ayri yada birlikte kullanilabilir.

** Her bir yanan user led bir yöntemin calistigini temsil eder. 
** 7-segment üzerindeki sicaklik degeri dma yöntemi ile hesaplanan 
** sicakligi gösterecek sekilde ayarlanmistir.
*/

/* Entry Point */
int main(void)
{
	/* initializes the Hardware Abstraction Layer (HAL) library */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_ADC3_Init();
	
	/* To ensure the while loop runs for a specific duration */
	int counter = 15;
	
  while (1)
  {			
				#ifdef USE_DMA_METHOD
				/* ADC DMA mode for temperature measurement. */
				/* Delay and stop to operate continuously and keep updated */
				{
					HAL_ADC_Start_DMA(&hadc3, adc_dma_buffer, ADC_BUFFER_SIZE);
					display_seven_segment(temperature_dma);
					HAL_Delay(300);
					HAL_ADC_Stop_DMA(&hadc3);
				}
				#endif
				
				//Delay to prevent conflicts between DMA and interrupt modes and for increase loop time
				HAL_Delay(300); 
				
				#ifdef USE_INTERRUPT_METHOD
				/* Measure temperature with ADC using interruptmodes */
				HAL_ADC_Start_IT(&hadc1);
				#endif
				
				
				#ifdef USE_POOLING_METHOD
				/* Measure temperature with ADC using polling modes */
			 {
					HAL_ADC_Start(&hadc2);
					POOL_ADC();
			 }
			 #endif 
				
				
			/* Stop ADC, reset GPIO, and deinitialize after a specified measurement duration  */
			if (counter == 0)
			{ 	
					#ifdef USE_INTERRUPT_METHOD
					HAL_ADC_Stop_IT(&hadc1);
					#endif
				
					#ifdef USE_DMA_METHOD
					HAL_ADC_Stop_DMA(&hadc3);
					#endif
				
					#ifdef USE_POOLING_METHOD
					HAL_ADC_Stop(&hadc2);
					#endif
						
					reset_all();
					deinit();
					break;
			}
			
			// Delay to prevent conflicts between DMA and interrupt modes and for increase loop time
			HAL_Delay(400); 
			counter--;
  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
		
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */



