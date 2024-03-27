#include "main.h"

/********** Displays a digit (0-9) on a 7-segment display. **********/
void display_digit(uint8_t digit)
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

/********** Displays a two-digit or one-digit on two 7-segment displays. **********/
void display_seven_segment(uint8_t id_value)
{
			HAL_GPIO_WritePin(GPIOE, BL_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LE_1_GPIO_Port, LE_1_Pin, GPIO_PIN_RESET);
			display_digit(id_value);
			HAL_GPIO_WritePin(LE_1_GPIO_Port, LE_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOE, BL_1_Pin, GPIO_PIN_SET);
		
			if (id_value > 10)
			{ 	
				uint8_t digit_1 = id_value/10;
				uint8_t digit_2 = id_value%10;
				
				HAL_GPIO_WritePin(GPIOE, BL_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LE_1_GPIO_Port, LE_1_Pin, GPIO_PIN_RESET);
				display_digit(digit_1);
				HAL_GPIO_WritePin(LE_1_GPIO_Port, LE_1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOE, BL_1_Pin, GPIO_PIN_SET);
				
				HAL_Delay(50);
				
				HAL_GPIO_WritePin(GPIOC, BL_2_Pin|LE_2_Pin, GPIO_PIN_RESET);
				display_digit(digit_2);
				HAL_GPIO_WritePin(GPIOC, BL_2_Pin|LE_2_Pin, GPIO_PIN_SET);
			}
	
}
