
#include "main.h"

/********** Displays a digit (0-9) on a 7-segment display. **********/
void display_digit(uint32_t digit)
{ 

	switch(digit)
	{
		case 0:
			HAL_GPIO_WritePin(GPIOE, D2_Pin|D1_Pin|D3_Pin|D0_Pin, GPIO_PIN_RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOE, D3_Pin|D2_Pin|D1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOE, D0_Pin, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOE, D0_Pin|D3_Pin|D2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOE, D1_Pin, GPIO_PIN_SET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOE, D3_Pin|D2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOE, D1_Pin|D0_Pin, GPIO_PIN_SET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOE, D3_Pin|D1_Pin|D0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOE, D2_Pin, GPIO_PIN_SET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOE, D1_Pin|D3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOE, D2_Pin|D0_Pin, GPIO_PIN_SET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOE, D2_Pin|D1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOE, D3_Pin|D0_Pin, GPIO_PIN_RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOE, D2_Pin|D1_Pin|D0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOE, D3_Pin, GPIO_PIN_RESET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOE, D2_Pin|D1_Pin|D0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOE, D3_Pin, GPIO_PIN_SET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOE, D2_Pin|D1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOE, D3_Pin|D0_Pin, GPIO_PIN_SET);
			break;
		
	}
	
	return ;
}

/********** Displays a two-digit temperature on two 7-segment displays. **********/
void display_seven_segment(uint8_t temperature)
{
	uint8_t digit_1 = temperature/10;
	uint8_t digit_2 = temperature%10;
	
	
	/* for first 7-segment */
	HAL_GPIO_WritePin(GPIOE, BL_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LE_1_GPIO_Port, LE_1_Pin, GPIO_PIN_RESET);
	display_digit(digit_1);
	HAL_GPIO_WritePin(LE_1_GPIO_Port, LE_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE, BL_1_Pin, GPIO_PIN_SET);
	
	/* for prevent conflict in between two 7-segment */
	HAL_Delay(200);
	
	/* for second 7-segment */
	HAL_GPIO_WritePin(GPIOC, BL_2_Pin|LE_2_Pin, GPIO_PIN_RESET);
	display_digit(digit_2);
	HAL_GPIO_WritePin(GPIOC, BL_2_Pin|LE_2_Pin, GPIO_PIN_SET);
	
}