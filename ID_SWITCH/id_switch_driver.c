#include "main.h"
#include "id_switch_driver.h"

/********** GPIO Interrupt Callback for Switch Inputs **********/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
 	  if (GPIO_Pin == ID_SWITCH1) {
        if (HAL_GPIO_ReadPin(GPIOG, ID_SWITCH1) == GPIO_PIN_SET)
            id_value |= 0x01;
				else 
						id_value &= ~0x01;
    } 

		else if (GPIO_Pin == ID_SWITCH2) {
        if (HAL_GPIO_ReadPin(GPIOG, ID_SWITCH2) == GPIO_PIN_SET)
            id_value |= 0x02;
				else 
						id_value &= ~0x02;
    } 
	
		else if (GPIO_Pin == ID_SWITCH3) {
        if (HAL_GPIO_ReadPin(GPIOF, ID_SWITCH3) == GPIO_PIN_SET)
            id_value |= 0x04;
				else 
						id_value &= ~0x04;
    }
	
		else if (GPIO_Pin == ID_SWITCH4	) {
        if (HAL_GPIO_ReadPin(GPIOF, ID_SWITCH4) == GPIO_PIN_SET)
            id_value |= 0x08;
				else 
						id_value &= ~0x08;
    }
		

}

/********** Associates EXTI line 0 interrupt with ID_SWITCH2 **********/
void EXTI0_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(ID_SWITCH2);
}


/*********** Associates EXTI line 1 interrupt with ID_SWITCH1 ***********/
void EXTI1_IRQHandler(void)
{

  HAL_GPIO_EXTI_IRQHandler(ID_SWITCH1);
}


/*********** Associates EXTI lines 10 to 15 interrupts with ID_SWITCH4 and ID_SWITCH3 **********/
void EXTI15_10_IRQHandler(void)
{

  HAL_GPIO_EXTI_IRQHandler(ID_SWITCH4);
  HAL_GPIO_EXTI_IRQHandler(ID_SWITCH3);

}
