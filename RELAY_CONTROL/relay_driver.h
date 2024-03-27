#ifndef RELAY_DRIVER_H
#define RELAY_DRIVER_H

/* Defines *******************************************************************/
#define SWITCH_Pin				GPIO_PIN_1
#define SWITCH_GPIO_Port	GPIOB
#define RELAY_Pin					GPIO_PIN_12
#define RELAY_GPIO_Port		GPIOE

#define READ_SWITCH		HAL_GPIO_ReadPin(SWITCH_GPIO_Port,SWITCH_Pin)
#define RELAY_OPEN		HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin, GPIO_PIN_SET)
#define RELAY_CLOSE		HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin, GPIO_PIN_RESET)

/* Functions *****************************************************************/
void GPIO_Init(void);
void GPIO_DeInit(void);
void relay_driver(void);

#endif
