#include "main.h"
#include "led_driver.h"

/********** Deinitialize GPIO Pins and Ports **********/
void GPIO_DeInit(void)
{		
		/* Disable Clocks for GPIO Port F*/
    __HAL_RCC_GPIOF_CLK_DISABLE();
	
		/* Deinitialize GPIO Pins for LEDs */
    HAL_GPIO_DeInit(GPIOF, LED_1 | LED_2 | LED_3 | LED_4);
}
