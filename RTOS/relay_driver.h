#ifndef RELAY_DRIVER_H
#define RELAY_DRIVER_H

/* Defines *******************************************************************/

#define ID_SWITCH1				GPIO_PIN_1
#define ID_PORT						GPIOG
#define RELAY_Pin					GPIO_PIN_12
#define RELAY_GPIO_Port		GPIOE


#define READ_SWITCH		HAL_GPIO_ReadPin(ID_PORT ,ID_SWITCH1)

#define RELAY_OPEN		HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin, GPIO_PIN_SET)
#define RELAY_CLOSE		HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin, GPIO_PIN_RESET)


/* Functions *****************************************************************/
void GPIO_Init(void);
void GPIO_DeInit(void);
void relay_driver(void);
void EXTI1_IRQHandler(void);

#endif
