#ifndef ID_SWITCH_DRIVER_H
#define ID_SWITCH_DRIVER_H

#include "main.h"

/* Defines *******************************************************************/
#define ID_SWITCH1 GPIO_PIN_1
#define ID_SWITCH2 GPIO_PIN_0
#define ID_SWITCH3 GPIO_PIN_15
#define ID_SWITCH4 GPIO_PIN_14

/* Functions *****************************************************************/
void GPIO_Deinit(void);
void GPIO_Init(void);
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI15_10_IRQHandler(void);

/* Global Variables **********************************************************/
extern uint8_t id_value;

#endif
