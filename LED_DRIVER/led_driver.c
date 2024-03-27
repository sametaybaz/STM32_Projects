#include "led_driver.h"
#include "main.h"

/********** Turn On (Set) User LED Pins **********/
void open(void)
{
		HAL_GPIO_WritePin(LED_PORT, LED_1 | LED_2 | LED_3 | LED_4, GPIO_PIN_SET);
}

/********** Turn Off (Set) User LED Pins **********/
void close(void)
{ 
		HAL_GPIO_WritePin(LED_PORT, LED_1 | LED_2 | LED_3 | LED_4, GPIO_PIN_RESET);
}

/********** Toggle State of User LED Pins **********/
void toggle(void)
{ 
		HAL_GPIO_TogglePin(LED_PORT, LED_1 | LED_2 | LED_3 | LED_4);
}
